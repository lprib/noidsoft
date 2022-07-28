#include "bitmap.h"
#include "render.h"

#include <assert.h>
#include <string.h>

#define PARANOID 0

void bitmap_point(render_bitmap_t* bitmap, int x, int y, bitmap_point_operation_t op)
{
#if PARANOID
  assert(x >= 0);
  assert(x < bitmap->width);
  assert(y >= 0);
  assert(y < bitmap->height);
#endif

  uint8_t bitmask = 1 << (x % 8);
  uint8_t* byte = &bitmap->buffer[y * bitmap->width_bytes + x / 8];

  // TODO hoise out of here! (monomorphize somehow?)
  switch (op)
  {
  case POINT_SET:
    *byte |= bitmask;
    break;
  case POINT_CLEAR:
    *byte &= ~bitmask;
    break;
  case POINT_FLIP:
    *byte ^= bitmask;
    break;
  }
}

void bitmap_clear(render_bitmap_t* bitmap)
{
  memset(bitmap->buffer, 0, bitmap->width_bytes * bitmap->height);
}

void bitmap_hline(render_bitmap_t* bitmap, int x1, int x2, int y, bitmap_point_operation_t op)
{
  // TODO fast byte-copy impl
  for (int x = x1; x <= x2; x++)
  {
    bitmap_point(bitmap, x, y, op);
  }
}

void bitmap_vline(render_bitmap_t* bitmap, int y1, int y2, int x, bitmap_point_operation_t op)
{
  for (int y = y1; y <= y2; y++)
  {
    bitmap_point(bitmap, x, y, op);
  }
}

void bitmap_rect(render_bitmap_t* bitmap, int x, int y, int w, int h, bitmap_point_operation_t op)
{
  bitmap_hline(bitmap, x, x + w - 1, y, op);
  bitmap_hline(bitmap, x, x + w - 1, y + h - 1, op);
  bitmap_vline(bitmap, y, y + h - 1, x, op);
  bitmap_vline(bitmap, y, y + h - 1, x + w - 1, op);
}
