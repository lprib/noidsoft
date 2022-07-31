#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <limits.h>
#include <stdint.h>

/**
 * Generic bitmap drawing functions.
 *
 * Note all operations are bounds unchecked.
 */

/** A single element of the bitmap buffer. */
typedef uint32_t bmp_elem_t;

typedef struct
{
  /** width in pixels */
  int width;

  /** height in pixels */
  int height;

  /**
   * Width of buffer in units of bmp_elem_t. Total buffer size is
   * width_elems*height. Buffer width is the minimum amount of elems to hold
   * `width` pixels. Ie. there may be padding.
   */
  int width_elems;

  /* buffer */
  bmp_elem_t* buffer;

} bmp_t;

typedef struct
{
  int x;
  int y;
  int w;
  int h;
} bmp_rect_t;

/** bits (pixels) in each element of bmp_t.buffer */
extern int const BMP_PIX_PER_ELEM;
/** value of bmp_elem_t that is all 1s */
extern bmp_elem_t const BMP_FILLED_ELEM;

typedef enum
{
  BMP_PXL_SET,
  BMP_PXL_CLEAR,
  BMP_PXL_INVERT,
} bmp_op_t;

void bmp_point(bmp_t* bitmap, int x, int y, bmp_op_t op);
void bmp_clear(bmp_t* bitmap);
void bmp_blit_clear(bmp_t* bitmap, bmp_op_t op);
void bmp_hline(bmp_t* bitmap, int x1, int x2, int y, bmp_op_t op);
void bmp_vline(bmp_t* bitmap, int y1, int y2, int x, bmp_op_t op);
void bmp_rect(bmp_t* bitmap, int x, int y, int w, int h, bmp_op_t op);
void bmp_fill_rect(bmp_t* bitmap, int x, int y, int w, int h, bmp_op_t op);

void bmp_sprite(bmp_t* dest, bmp_t* src, bmp_rect_t* src_rect, int x, int y);

#endif
