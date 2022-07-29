#include "bitmap.h"
#include "render.h"
#include "util.h"

#include <assert.h>
#include <string.h>

#define PARANOID 0

static inline void blit_to_dest_byte(uint8_t* dest, uint8_t pattern, bmp_blit_op_t op)
{
  switch(op)
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

void bmp_point(r_bmp_t* bmp, int x, int y, bmp_blit_op_t mode)
{
#if PARANOID
  assert(x >= 0);
  assert(x < bmp->width);
  assert(y >= 0);
  assert(y < bmp->height);
#endif

  uint8_t bitmask = 1 << (x % 8);
  uint8_t* dest = &bmp->buffer[y * bmp->width_bytes + x / 8];

  switch(mode)
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

void bmp_clear(r_bmp_t* bmp)
{
  memset(bmp->buffer, 0, bmp->width_bytes * bmp->height);
}

void bmp_blit_clear(r_bmp_t* bmp, bmp_blit_op_t mode)
{
  static uint8_t const filled_byte = 0xFF;

  for(int i = 0; i < (bmp->width_bytes * bmp->height); i++)
  {
    blit_to_dest_byte(&bmp->buffer[i], filled_byte, mode);
  }
}

void bmp_hline(r_bmp_t* bmp, int x1, int x2, int y, bmp_blit_op_t op)
{
  // TODO fast byte-copy impl
  for (int x = x1; x <= x2; x++)
  {
    bmp_point(bmp, x, y, op);
  }
}

void bmp_vline(r_bmp_t* bmp, int y1, int y2, int x, bmp_blit_op_t op)
{
  for (int y = y1; y <= y2; y++)
  {
    bmp_point(bmp, x, y, op);
  }
}

void bmp_rect(r_bmp_t* bmp, int x, int y, int w, int h, bmp_blit_op_t op)
{
  bmp_hline(bmp, x, x + w - 1, y, op);
  bmp_hline(bmp, x, x + w - 1, y + h - 1, op);
  bmp_vline(bmp, y, y + h - 1, x, op);
  bmp_vline(bmp, y, y + h - 1, x + w - 1, op);
}

#define N_TOP_BITS(n) (((1 << (n)) - 1) << (8 - (n)))

void bmp_fill_rect(r_bmp_t* bmp, int x, int y, int w, int h, bmp_blit_op_t op)
{
  int first_inside_byte_boundary = utl_divide_round_up(x, 8);
  int last_byte_boundary_exclusive  = (x + w) / 8;
  for(int y_iter = y; y_iter < y + h; y_iter++)
  {
    // blit full bytes first
    for(int x_byte_iter = first_inside_byte_boundary; x_byte_iter < last_byte_boundary_exclusive; x_byte_iter++)
    {
      blit_to_dest_byte(&bmp->buffer[y_iter * bmp->width_bytes + x_byte_iter], 0xFF, op);
    }

    // blit start and end stragglers
    // TODO
  }
}
