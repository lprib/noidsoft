#ifndef _BITMAP_H_
#define _BITMAP_H_

#include "render.h"
#include <stdbool.h>

/** Note all routines are unchecked */

typedef enum
{
  BLIT_SET,
  BLIT_CLEAR,
  BLIT_INVERT,
} bmp_blit_op_t;

void bmp_point(r_bmp_t* bitmap, int x, int y, bmp_blit_op_t op);
void bmp_clear(r_bmp_t* bitmap);
void bmp_blitclear(r_bmp_t* bitmap, bmp_blit_op_t op);
void bmp_hline(r_bmp_t* bitmap, int x1, int x2, int y, bmp_blit_op_t op);
void bmp_vline(r_bmp_t* bitmap, int y1, int y2, int x, bmp_blit_op_t op);
void bmp_rect(r_bmp_t* bitmap, int x, int y, int w, int h, bmp_blit_op_t op);

#endif
