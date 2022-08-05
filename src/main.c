#include "bitmap.h"
#include "font.h"
#include "font_helv8.h"
#include "font_micro.h"
#include "key.h"
#include "render.h"
#include "sdl2_render_driver.h"
#include "util.h"
#include "window.h"

#include <stdio.h>

static void event_handler(r_event_t event);

static bmp_elem_t smile_sprite[] = {
    (bmp_elem_t)0b00111100 << 8,
    (bmp_elem_t)0b01000010 << 8,
    (bmp_elem_t)0b10100101 << 8,
    (bmp_elem_t)0b10000001 << 8,
    (bmp_elem_t)0b10100101 << 8,
    (bmp_elem_t)0b10011001 << 8,
    (bmp_elem_t)0b01000010 << 8,
    (bmp_elem_t)0b00111100 << 8};

static bmp_t smile =
    {.width = 8, .height = 8, .width_elems = 1, .buffer = smile_sprite};

static void draw_outline(win_t* self, bmp_t* target)
{
  win_rect(
      self,
      target,
      (rect_t){0, 0, self->rect.w, self->rect.h},
      BMP_PXL_SET
  );
}

static void draw_outline_text(win_t* self, bmp_t* target)
{
  draw_outline(self, target);
  win_string(self, target, &micro, "Some Text Here", 2, 2);
}

static win_t main_win = {
    .rect = {0, 0, 128, 64},
    .dock = 0,
    .enabled = true,
    .draw_fn = &draw_outline,
    .next_sibling = NULL};

static win_t child1 = {
    .rect = {8, 8, 10, 10},
    .dock = WIN_DOCK_TOP | WIN_DOCK_LEFT,
    .enabled = true,
    .draw_fn = &draw_outline,
    .next_sibling = NULL};

static win_t child2 = {
    .rect = {112, 48, 8, 8},
    .dock = WIN_DOCK_BOTTOM | WIN_DOCK_RIGHT,
    .enabled = true,
    .draw_fn = &draw_outline,
    .next_sibling = NULL};

static win_t child3 = {
    .rect = {8, 38, 112, 9},
    .dock = WIN_DOCK_LEFT | WIN_DOCK_BOTTOM | WIN_DOCK_RIGHT,
    .enabled = true,
    .draw_fn = &draw_outline_text,
    .next_sibling = NULL};

static win_t child4 = {
    .rect = {4, 4, 120, 56},
    .dock = WIN_DOCK_TOP | WIN_DOCK_LEFT | WIN_DOCK_BOTTOM | WIN_DOCK_RIGHT,
    .enabled = true,
    .draw_fn = &draw_outline,
    .next_sibling = NULL};

static void draw(void)
{
  bmp_t* pix = r_get_buffer();
  bmp_clear(pix);
  for (int i = 0; i < pix->width; i++)
  {
    if (!(i % BMP_PIX_PER_ELEM))
    {
      bmp_point(pix, i, 0, BMP_PXL_SET);
    }
  }
  win_reshape(&main_win, bmp_get_rect(pix), true);
  win_draw_recursive(&main_win, pix);
  // bmp_fill_rect(pix, 2, 2, pix->width - 4, pix->height - 4, BMP_PXL_SET);
  // font_string(pix, &helv8, "Abcdefg Quick Brown Fox", 0, 10);
  // font_string(pix, &micro, "Abcdefg", 0, 23);
  // bmp_rect_t r = {0, 0, 16, 8};
  // bmp_sprite(pix, &helv08_glyph_A.bmp, &r, 20, 20);

  // bmp_point(pix, 0, 0, POINT_SET);
  // bmp_hline(pix, 0, pix->width - 1, 0, POINT_SET);
  // bmp_fill_rect(pix, pix->width - 9, pix->height - 9, 9, 9, BMP_PXL_INVERT);

  // rect_t r = bmp_get_rect(&smile);
  // bmp_sprite(pix, &smile, &r, 30, 30);
  // for (int i = 0; i < 4; i++)
  // {
  // bmp_rect(pix, i * 2, i * 2, pix->width - i * 4, pix->height - i * 4,
  // BMP_PXL_SET);
  // }
}

static void event_handler(r_event_t event)
{
  if (event.type == RENDER_EVENT_RESHAPE)
  {
    // printf("r\n");
    draw();
    r_request_refresh();
  }
  if (event.type == RENDER_EVENT_FRAME)
  {
    // printf("f");
    // fflush(stdout);
  }
  if (event.type == RENDER_EVENT_KEYDOWN)
  {
    printf("%c\n", key_to_char(event.key_event.key));
  }
}

int main(int argc, char* argv[])
{
  r_register_event_handler(event_handler);

  win_add_child(&main_win, &child1);
  win_add_child(&main_win, &child2);
  win_add_child(&main_win, &child3);
  win_add_child(&main_win, &child4);
  sdl_init();
  sdl_main_loop();
  sdl_cleanup();
  return 0;
}
