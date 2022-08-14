#ifndef _MMI_BITMAP_H_
#define _MMI_BITMAP_H_

/**
 * Generic bitmap drawing functions. Bitmaps are a bit-packed array of
 * bmp_elem_t.
 *
 * Operations are bounds checked within the target bitmaps width and height.
 */

#include <base/util.h>

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

/** A single element of the bitmap buffer. */
typedef uint16_t bmp_elem_t;

typedef struct
{
  /** width in pixels */
  int w;

  /** height in pixels */
  int h;

  /**
   * Width of buffer in units of bmp_elem_t. Total buffer size is
   * width_elems*height. Buffer width is the minimum amount of elems to hold
   * `width` pixels. Ie. there may be padding.
   */
  int width_elems;

  /* buffer */
  bmp_elem_t* buffer;

} bmp_t;

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
void bmp_clear_op(bmp_t* bitmap, bmp_op_t op);
void bmp_hline(bmp_t* bitmap, int x1, int x2, int y, bmp_op_t op);
void bmp_vline(bmp_t* bitmap, int y1, int y2, int x, bmp_op_t op);
void bmp_rect(bmp_t* bitmap, rect_t rect, bmp_op_t op);
void bmp_fill_rect(bmp_t* bitmap, rect_t rect, bmp_op_t op);

/**
 * Draws a sprite bitmap `src` onto `dest` at specified x, y top left coords.
 * `src_rect` defines the sub-texture that will be drawn from the src bitmap.
 *
 * Limitations:
 * src_rect.x must lie on a bitmap element boundary.
 * src_rect.w must be <= BMP_PIX_PER_ELEM
 */
void bmp_sprite(
    bmp_t* dest,
    bmp_t* src,
    rect_t* src_rect,
    int x,
    int y,
    bool invert
);

rect_t bmp_get_rect(bmp_t* bitmap);

#endif
