#include "window.h"

#include "font.h"

#include <platform_interface/error_check.h>

#include <stdbool.h>

/**
 * These are all just thin wrappers over bitmap.h functions. They translate the
 * coordinates into window-local fist.
 *
 * TODO enable clippping in source rect.
 *
 * This source implements the drawing functionality of mmi/window.h
 */

void win_point(win_t* self, bmp_t* target, int x, int y, bmp_op_t op)
{
  CHECK(x >= 0);
  CHECK(x < self->rect.w);
  CHECK(y >= 0);
  CHECK(y < self->rect.h);
  bmp_point(target, self->rect.x + x, self->rect.y, op);
}

void win_hline(win_t* self, bmp_t* target, int x1, int x2, int y, bmp_op_t op)
{
  bmp_hline(target, self->rect.x + x1, self->rect.x + x2, self->rect.y + y, op);
}

void win_vline(win_t* self, bmp_t* target, int y1, int y2, int x, bmp_op_t op)
{
  bmp_vline(target, self->rect.y + y1, self->rect.y + y2, self->rect.x + x, op);
}

void win_rect(win_t* self, bmp_t* target, rect_t rect, bmp_op_t op)
{
  rect.x += self->rect.x;
  rect.y += self->rect.y;
  bmp_rect(target, rect, op);
}

void win_fill_rect(win_t* self, bmp_t* target, rect_t rect, bmp_op_t op)
{
  CHECK(rect.x >= 0);
  CHECK(rect.x < self->rect.w);
  CHECK(rect.y >= 0);
  CHECK(rect.y < self->rect.h);
  CHECK(rect.x + rect.w <= self->rect.w);
  CHECK(rect.y + rect.h <= self->rect.h);

  rect.x += self->rect.x;
  rect.y += self->rect.y;
  bmp_fill_rect(target, rect, op);
}

void win_clear_op(win_t* self, bmp_t* target, bmp_op_t op)
{
  bmp_fill_rect(target, self->rect, op);
}

void win_sprite(
    win_t* self,
    bmp_t* target,
    bmp_t* src,
    rect_t* src_rect,
    int x,
    int y,
    bool invert
)
{
  CHECK(x < self->rect.w);
  CHECK(y < self->rect.h);

  bmp_sprite(target, src, src_rect, self->rect.x + x, self->rect.y + y, invert);
}

void win_string(
    win_t* self,
    bmp_t* target,
    font_t* font,
    str_t str,
    int x,
    int y,
    bool invert
)
{
  CHECK(x >= 0);
  CHECK(x < self->rect.w);
  CHECK(y >= 0);
  CHECK(y < self->rect.h);
  int font_width = font_string_width(font, str);
  CHECK(x + font_width <= self->rect.w);
  CHECK(y + font_height(font) <= self->rect.h);

  font_string(target, font, str, self->rect.x + x, self->rect.y + y, invert);
}
