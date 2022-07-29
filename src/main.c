#include "bitmap.h"
#include "render.h"
#include "sdl2_render_driver.h"

#include <stdio.h>

static void event_handler(r_event_t event);

int main(int argc, char* argv[])
{
  r_register_event_handler(event_handler);

  sdl2render_init();
  sdl2render_run_loop();
  sdl2render_cleanup();
  return 0;
}

static void draw(void)
{
  r_bmp_t* pix = r_get_buffer();
  bmp_clear(pix);
  // bmp_point(pix, 0, 0, POINT_SET);
  // bmp_hline(pix, 0, pix->width - 1, 0, POINT_SET);
  for (int i = 0; i < 4; i++)
  {
    bmp_rect(pix, i * 2, i * 2, pix->width - i * 4, pix->height - i * 4, BLIT_SET);
  }
}

static void event_handler(r_event_t event)
{
  if (event.type == RENDER_EVENT_RESHAPE)
  {
    printf("r\n");
    draw();
    r_request_refresh();
  }
  if (event.type == RENDER_EVENT_FRAME)
  {
    printf("f");
    fflush(stdout);
  }
}
