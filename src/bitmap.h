#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stdint.h>

/**
 * Generic bitmap drawing functions.
 *
 * Note all operations are bounds unchecked.
 */

/** A single element of the bitmap buffer. */
typedef uint8_t bmp_elem_t;

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

/** bits (pixels) in each element of bmp_t.buffer */
#define BMP_PIX_PER_ELEM 8

/** value of bmp_elem_t that is all 1s */
#define BMP_FILLED_ELEM 0xFF

typedef enum
{
  BLIT_SET,
  BLIT_CLEAR,
  BLIT_INVERT,
} bmp_blit_op_t;

void bmp_point(bmp_t* bitmap, int x, int y, bmp_blit_op_t op);
void bmp_clear(bmp_t* bitmap);
void bmp_blit_clear(bmp_t* bitmap, bmp_blit_op_t op);
void bmp_hline(bmp_t* bitmap, int x1, int x2, int y, bmp_blit_op_t op);
void bmp_vline(bmp_t* bitmap, int y1, int y2, int x, bmp_blit_op_t op);
void bmp_rect(bmp_t* bitmap, int x, int y, int w, int h, bmp_blit_op_t op);
void bmp_fill_rect(bmp_t* bitmap, int x, int y, int w, int h, bmp_blit_op_t op);

#endif
