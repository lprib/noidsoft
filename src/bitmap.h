#ifndef _BITMAP_H_
#define _BITMAP_H_

#include "render.h"

/** Note all routines are unchecked */

typedef enum
{
  POINT_SET,
  POINT_CLEAR,
  POINT_FLIP
} bitmap_point_operation_t;

void bitmap_point(render_bitmap_t* bitmap, int x, int y, bitmap_point_operation_t op);
void bitmap_clear(render_bitmap_t* bitmap);
void bitmap_hline(render_bitmap_t* bitmap, int x1, int x2, int y, bitmap_point_operation_t op);
void bitmap_vline(render_bitmap_t* bitmap, int y1, int y2, int x, bitmap_point_operation_t op);
void bitmap_rect(render_bitmap_t* bitmap, int x, int y, int w, int h, bitmap_point_operation_t op);

#endif
