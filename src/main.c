#include "bitmap.h"
#include "font.h"
#include "font_helv8.h"
#include "font_micro.h"
#include "render.h"
#include "sdl2_render_driver.h"
#include "util.h"

#include <stdio.h>

static void event_handler(r_event_t event);

int main(int argc, char* argv[])
{
  r_register_event_handler(event_handler);

  sdl_init();
  sdl_main_loop();
  sdl_cleanup();
  return 0;
}

static bmp_elem_t smile_sprite[] = {
    (bmp_elem_t)0b11111100 << 8,
    (bmp_elem_t)0b11000010 << 8,
    (bmp_elem_t)0b10100101 << 8,
    (bmp_elem_t)0b10000001 << 8,
    (bmp_elem_t)0b10100101 << 8,
    (bmp_elem_t)0b10011001 << 8,
    (bmp_elem_t)0b11000010 << 8,
    (bmp_elem_t)0b11111100 << 8};

static bmp_t smile =
    {.width = 8, .height = 8, .width_elems = 1, .buffer = smile_sprite};

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
  // bmp_fill_rect(pix, 2, 2, pix->width - 4, pix->height - 4, BMP_PXL_SET);
  font_string(pix, &helv08, "Abcdefg Quick Brown Fox", 10, 10);
  font_string(pix, &micro, "Abcdefg Quick Brown Fox", 11, 23);
  // bmp_rect_t r = {0, 0, 16, 8};
  // bmp_sprite(pix, &helv08_glyph_A.bmp, &r, 20, 20);

  // bmp_point(pix, 0, 0, POINT_SET);
  // bmp_hline(pix, 0, pix->width - 1, 0, POINT_SET);
  // bmp_fill_rect(pix, pix->width - 9, pix->height - 9, 9, 9, BMP_PXL_INVERT);

  bmp_rect_t sprite_rect = {0, 0, 8, 8};
  bmp_sprite(pix, &smile, &sprite_rect, 30, 30);
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
}
