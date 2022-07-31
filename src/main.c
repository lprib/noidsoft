#include "bitmap.h"
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
    (bmp_elem_t)0b00111100,
    (bmp_elem_t)0b01000010,
    (bmp_elem_t)0b10100101,
    (bmp_elem_t)0b10000001,
    (bmp_elem_t)0b10100101,
    (bmp_elem_t)0b10011001,
    (bmp_elem_t)0b01000010,
    (bmp_elem_t)0b00111100};

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
  // bmp_point(pix, 0, 0, POINT_SET);
  // bmp_hline(pix, 0, pix->width - 1, 0, POINT_SET);
  bmp_fill_rect(pix, 8, 8, pix->width - 9, pix->height - 9, BMP_PXL_SET);
  bmp_fill_rect(pix, pix->width - 9, pix->height - 9, 9, 9, BMP_PXL_INVERT);

  bmp_rect_t sprite_rect = {0, 0, 4, 8};
  bmp_sprite(pix, &smile, &sprite_rect, pix->width - 20, pix->height - 20);
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
