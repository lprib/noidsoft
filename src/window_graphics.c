#include "font.h"
#include "window.h"

#define CHECK_ENABLE_ASSERTS
#include "check.h"

void win_point(win_t* self, bmp_t* target, int x, int y, bmp_op_t op)
{
  ASSERT(x >= 0);
  ASSERT(x < self->rect.w);
  ASSERT(y >= 0);
  ASSERT(y < self->rect.h);
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
  ASSERT(rect.x >= 0);
  ASSERT(rect.x < self->rect.w);
  ASSERT(rect.y >= 0);
  ASSERT(rect.y < self->rect.h);
  ASSERT(rect.x + rect.w <= self->rect.w);
  ASSERT(rect.y + rect.h <= self->rect.h);

  rect.x += self->rect.x;
  rect.y += self->rect.y;
  bmp_fill_rect(target, rect, op);
}

void win_sprite(
    win_t* self,
    bmp_t* target,
    bmp_t* src,
    rect_t* src_rect,
    int x,
    int y
)
{
  ASSERT(x < self->rect.w);
  ASSERT(y < self->rect.h);

  bmp_sprite(target, src, src_rect, self->rect.x + x, self->rect.y + y);
}

void win_string(
    win_t* self,
    bmp_t* target,
    font_t* font,
    char* string,
    int x,
    int y
)
{
  ASSERT(x >= 0);
  ASSERT(x < self->rect.w);
  ASSERT(y >= 0);
  ASSERT(y < self->rect.h);
  int font_width = font_string_width(font, string);
  ASSERT(x + font_width < self->rect.w);

  font_string(target, font, string, self->rect.x + x, self->rect.y + y);
}
