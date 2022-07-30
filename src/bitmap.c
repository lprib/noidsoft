#include "bitmap.h"
#include "util.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define PARANOID 1

#define N_TOP_BITS(n) (((1 << (n)) - 1) << (BMP_PIX_PER_ELEM - (n)))
#define N_BOTTOM_BITS(n) ((1 << (n)) - 1)

static inline void blit_to_dest_elem(bmp_elem_t* dest, bmp_elem_t pattern, bmp_blit_op_t op)
{
  switch (op)
  {
  case BLIT_SET:
    *dest |= pattern;
    break;
  case BLIT_CLEAR:
    *dest &= ~pattern;
    break;
  case BLIT_INVERT:
    *dest ^= pattern;
    break;
  }
}

void bmp_point(bmp_t* bmp, int x, int y, bmp_blit_op_t mode)
{
#if PARANOID
  assert(x >= 0);
  assert(x < bmp->width);
  assert(y >= 0);
  assert(y < bmp->height);
#endif

  bmp_elem_t bitmask = 1 << (x % BMP_PIX_PER_ELEM);
  bmp_elem_t* dest = &bmp->buffer[y * bmp->width_elems + x / BMP_PIX_PER_ELEM];

  switch (mode)
  {
  // For the single point case, SET and OVERWRITE are identical
  case BLIT_SET:
    *dest |= bitmask;
    break;
  case BLIT_CLEAR:
    *dest &= ~bitmask;
    break;
  case BLIT_INVERT:
    *dest ^= bitmask;
    break;
  }
}

void bmp_clear(bmp_t* bmp)
{
  memset(bmp->buffer, 0, bmp->width_elems * bmp->height);
}

void bmp_blit_clear(bmp_t* bmp, bmp_blit_op_t mode)
{
  for (int i = 0; i < (bmp->width_elems * bmp->height); i++)
  {
    blit_to_dest_elem(&bmp->buffer[i], BMP_FILLED_ELEM, mode);
  }
}

void bmp_hline(bmp_t* bmp, int x1, int x2, int y, bmp_blit_op_t op)
{
  // TODO fast byte-copy impl
  for (int x = x1; x <= x2; x++)
  {
    bmp_point(bmp, x, y, op);
  }
}

void bmp_vline(bmp_t* bmp, int y1, int y2, int x, bmp_blit_op_t op)
{
  for (int y = y1; y <= y2; y++)
  {
    bmp_point(bmp, x, y, op);
  }
}

void bmp_rect(bmp_t* bmp, int x, int y, int w, int h, bmp_blit_op_t op)
{
  // TODO overlapping lines break with op BLIT_INVERT
  bmp_hline(bmp, x, x + w - 1, y, op);
  bmp_hline(bmp, x, x + w - 1, y + h - 1, op);
  bmp_vline(bmp, y, y + h - 1, x, op);
  bmp_vline(bmp, y, y + h - 1, x + w - 1, op);
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
void bmp_fill_rect(bmp_t* bmp, int x, int y, int w, int h, bmp_blit_op_t op)
{
#if PARANOID
  assert(x >= 0);
  assert(x < bmp->width);
  assert(y >= 0);
  assert(y < bmp->height);
  assert(x + w <= bmp->width);
  assert(y + h <= bmp->height);
#endif

  if (w > BMP_PIX_PER_ELEM)
  {
    // large rect case

    // last x coord that is inside rectangle
    int x2_incl = x + w - 1;

    // full byte portion
    int first_inside_elem_boundary = utl_divide_round_up(x, BMP_PIX_PER_ELEM);
    int last_elem_boundary_exclusive = (x + w) / BMP_PIX_PER_ELEM;

    // start overhang bits
    int num_start_overhang_bits = first_inside_elem_boundary * BMP_PIX_PER_ELEM - x;
    bmp_elem_t start_overhang_blit = N_TOP_BITS(num_start_overhang_bits);

    // end overhand bits
    int num_end_overhang_bits = (x + w) - last_elem_boundary_exclusive * BMP_PIX_PER_ELEM;
    bmp_elem_t end_overhang_blit = N_BOTTOM_BITS(num_end_overhang_bits);

#if PARANOID
    assert(num_start_overhang_bits >= 0);
    assert(num_start_overhang_bits < BMP_PIX_PER_ELEM);
    assert(num_end_overhang_bits >= 0);
    assert(num_end_overhang_bits < BMP_PIX_PER_ELEM);
#endif

    for (int y_iter = y; y_iter < y + h; y_iter++)
    {
      // blit full bytes first
      for (int x_byte_iter = first_inside_elem_boundary; x_byte_iter < last_elem_boundary_exclusive;
           x_byte_iter++)
      {
        blit_to_dest_elem(
            &bmp->buffer[y_iter * bmp->width_elems + x_byte_iter],
            BMP_FILLED_ELEM,
            op
        );
      }

      blit_to_dest_elem(
          &bmp->buffer[y_iter * bmp->width_elems + first_inside_elem_boundary - 1],
          start_overhang_blit,
          op
      );

      blit_to_dest_elem(
          &bmp->buffer[y_iter * bmp->width_elems + last_elem_boundary_exclusive],
          end_overhang_blit,
          op
      );
    }
  }
  else
  {
    // small rect case

    // Dumb algorithm for now to deal with the edge case of a small rect that
    // may be contained in a single elem stride or two incomplete elem strides
    for (int y_iter = y; y_iter < y + h; y_iter++)
    {
      for (int x_iter = x; x_iter < x + w; x_iter++)
      {
        bmp_point(bmp, x_iter, y_iter, op);
      }
    }
  }
}
