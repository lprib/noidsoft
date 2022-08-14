#include "bitmap.h"

#include "util.h"

#include "check.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// constant defs from header
int const BMP_PIX_PER_ELEM = sizeof(bmp_elem_t) * CHAR_BIT;
bmp_elem_t const BMP_FILLED_ELEM = (bmp_elem_t)(~(bmp_elem_t)0);
bmp_elem_t const BMP_ONE_ELEM = (bmp_elem_t)(1 << (BMP_PIX_PER_ELEM - 1));

#define N_END_BITS(n) ((1 << (n)) - 1)
#define N_START_BITS(n) (((1 << (n)) - 1) << (BMP_PIX_PER_ELEM - (n)))

static inline bmp_elem_t* get_elem(bmp_t* bmp, int x_elem_index, int y_index)
{
  return &bmp->buffer[y_index * bmp->width_elems + x_elem_index];
}

static inline void blit_elem(bmp_elem_t* dest, bmp_elem_t pattern, bmp_op_t op)
{
  switch (op)
  {
  case BMP_PXL_SET:
    *dest |= pattern;
    break;
  case BMP_PXL_CLEAR:
    *dest &= ~pattern;
    break;
  case BMP_PXL_INVERT:
    *dest ^= pattern;
    break;
  }
}

static inline void blit_elem_masked(
    bmp_elem_t* dest,
    bmp_elem_t pattern,
    bmp_elem_t mask,
    bool invert
)
{
  *dest &= ~mask;
  if (invert)
  {
    *dest |= ~pattern & mask;
  }
  else
  {
    *dest |= pattern & mask;
  }
}

static inline void shift_with_overflow(
    bmp_elem_t in,
    int amount,
    bmp_elem_t* out1,
    bmp_elem_t* out2
)
{
  ASSERT(amount <= BMP_PIX_PER_ELEM);

  *out1 = in >> amount;
  *out2 = in << (BMP_PIX_PER_ELEM - amount);
}

void bmp_point(bmp_t* bmp, int x, int y, bmp_op_t mode)
{
  ASSERT(x >= 0);
  ASSERT(x < bmp->width);
  ASSERT(y >= 0);
  ASSERT(y < bmp->height);

  bmp_elem_t bitmask = BMP_ONE_ELEM >> (x % BMP_PIX_PER_ELEM);
  bmp_elem_t* dest = get_elem(bmp, x / BMP_PIX_PER_ELEM, y);

  switch (mode)
  {
  case BMP_PXL_SET:
    *dest |= bitmask;
    break;
  case BMP_PXL_CLEAR:
    *dest &= ~bitmask;
    break;
  case BMP_PXL_INVERT:
    *dest ^= bitmask;
    break;
  }
}

void bmp_clear(bmp_t* bmp)
{
  memset(bmp->buffer, 0, bmp->width_elems * bmp->height * sizeof(bmp_elem_t));
}

void bmp_clear_op(bmp_t* bmp, bmp_op_t op)
{
  for (int i = 0; i < (bmp->width_elems * bmp->height); i++)
  {
    blit_elem(&bmp->buffer[i], BMP_FILLED_ELEM, op);
  }
}

void bmp_hline(bmp_t* bmp, int x1, int x2, int y, bmp_op_t op)
{
  // TODO fast byte-copy impl
  for (int x = x1; x <= x2; x++)
  {
    bmp_point(bmp, x, y, op);
  }
}

void bmp_vline(bmp_t* bmp, int y1, int y2, int x, bmp_op_t op)
{
  for (int y = y1; y <= y2; y++)
  {
    bmp_point(bmp, x, y, op);
  }
}

void bmp_rect(bmp_t* bitmap, rect_t rect, bmp_op_t op)
{
  // TODO overlapping lines break with op BMP_PXL_INVERT
  bmp_hline(bitmap, rect.x, rect.x + rect.w - 1, rect.y, op);
  bmp_hline(bitmap, rect.x, rect.x + rect.w - 1, rect.y + rect.h - 1, op);
  bmp_vline(bitmap, rect.y, rect.y + rect.h - 1, rect.x, op);
  bmp_vline(bitmap, rect.y, rect.y + rect.h - 1, rect.x + rect.w - 1, op);
}

/**
 * Render filled rect byte-by-byte.
 *
 * First renderes the full byte portion of each scanline by blitting 0xFF. Eg
 * from _byte_ index B to (exclusive) C
 *
 * Then renders the overhang bits from A to B and the overhang bits from C to D.
 *
 *       A    B                                C    D
 *       v    v                                v    v
 * 01234567 | 01234567 01234567 ... 01234567 | 01234567
 *
 * If the rect is too small for this algo, it will fall back to a simple
 * foreach and bmp_point.
 */
void bmp_fill_rect(bmp_t* bitmap, rect_t rect, bmp_op_t op)
{
  ASSERT(rect.x >= 0);
  ASSERT(rect.x < bitmap->width);
  ASSERT(rect.y >= 0);
  ASSERT(rect.y < bitmap->height);
  ASSERT(rect.x + rect.w <= bitmap->width);
  ASSERT(rect.y + rect.h <= bitmap->height);

  // full byte portion
  int first_inside_elem_boundary =
      utl_divide_round_up(rect.x, BMP_PIX_PER_ELEM);
  int last_elem_boundary_exclusive = (rect.x + rect.w) / BMP_PIX_PER_ELEM;

  // start overhang bits
  int num_start_overhang_bits =
      first_inside_elem_boundary * BMP_PIX_PER_ELEM - rect.x;
  bmp_elem_t start_overhang_blit = N_END_BITS(num_start_overhang_bits);

  // end overhand bits
  int num_end_overhang_bits =
      (rect.x + rect.w) - last_elem_boundary_exclusive * BMP_PIX_PER_ELEM;
  bmp_elem_t end_overhang_blit = N_START_BITS(num_end_overhang_bits);

  // Handle the case where there is only a single elem stride of width.
  // start_overhang_blit will always go to the end of the elem boundary. We
  // need to erase the outside bits.
  bool is_single_stride_blit =
      first_inside_elem_boundary > last_elem_boundary_exclusive;
  if (is_single_stride_blit)
  {
    int num_to_erase = BMP_PIX_PER_ELEM - (rect.x + rect.w);
    start_overhang_blit &= ~N_END_BITS(num_to_erase);
  }

  ASSERT(num_start_overhang_bits >= 0);
  ASSERT(num_start_overhang_bits < BMP_PIX_PER_ELEM);
  ASSERT(num_end_overhang_bits >= 0);
  ASSERT(num_end_overhang_bits < BMP_PIX_PER_ELEM);

  for (int y_iter = rect.y; y_iter < rect.y + rect.h; y_iter++)
  {
    // blit full bytes first
    for (int x_elem_iter = first_inside_elem_boundary;
         x_elem_iter < last_elem_boundary_exclusive;
         x_elem_iter++)
    {
      blit_elem(get_elem(bitmap, x_elem_iter, y_iter), BMP_FILLED_ELEM, op);
    }

    blit_elem(
        get_elem(bitmap, first_inside_elem_boundary - 1, y_iter),
        start_overhang_blit,
        op
    );

    if (!is_single_stride_blit)
    {
      blit_elem(
          get_elem(bitmap, last_elem_boundary_exclusive, y_iter),
          end_overhang_blit,
          op
      );
    }
  }
}

/**
 * Limitations:
 * src_rect.w must always be less <= BMP_PIX_PER_ELEM
 * src_rect.x must be bmp_elem_t aligned
 */
void bmp_sprite(
    bmp_t* dest,
    bmp_t* src,
    rect_t* src_rect,
    int x,
    int y,
    bool invert
)
{
  ASSERT(src_rect->w <= BMP_PIX_PER_ELEM);
  ASSERT(src_rect->x % BMP_PIX_PER_ELEM == 0);

  ASSERT(x < dest->width);
  ASSERT(y < dest->height);

  // assumption: src_rect.x will always be byte aligned, so will always have
  // offset 0 into a bmp_elem_t
  int shift_amount = x % BMP_PIX_PER_ELEM;
  bmp_elem_t src_mask_1;
  bmp_elem_t src_mask_2;
  shift_with_overflow(
      N_START_BITS(src_rect->w),
      shift_amount,
      &src_mask_1,
      &src_mask_2
  );

  // If the sprite crosses elem boundaries, we need to do a second blit of the
  // overhang
  bool do_second_blit =
      ((x % BMP_PIX_PER_ELEM) + src_rect->w) > BMP_PIX_PER_ELEM;

  for (int y_iter = 0; y_iter < src_rect->h; y_iter++)
  {
    ASSERT(x / BMP_PIX_PER_ELEM < dest->width_elems);

    int src_y = src_rect->y + y_iter;
    int dest_y = y + y_iter;

    ASSERT(src_y < src->height);
    ASSERT(dest_y < dest->height);

    bmp_elem_t* target_elem = get_elem(dest, x / BMP_PIX_PER_ELEM, dest_y);
    bmp_elem_t src_1;
    bmp_elem_t src_2;
    // assumption: src_rect->x is always on a byte boundary
    shift_with_overflow(
        *get_elem(src, src_rect->x / BMP_PIX_PER_ELEM, src_y),
        shift_amount,
        &src_1,
        &src_2
    );

    blit_elem_masked(target_elem, src_1, src_mask_1, invert);
    if (do_second_blit)
    {
      ASSERT((x / BMP_PIX_PER_ELEM + 1) < dest->width_elems);
      // move one over and draw the second blit
      blit_elem_masked(target_elem + 1, src_2, src_mask_2, invert);
    }
  }
}

rect_t bmp_get_rect(bmp_t* bitmap)
{
  return (rect_t){0, 0, bitmap->width, bitmap->height};
}
