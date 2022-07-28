#include "bitmap.h"
#include "render.h"
#include "sdl2_render_driver.h"

#include <stdio.h>

static void event_handler(render_event_t event);

int main(int argc, char* argv[])
{
  render_register_event_handler(event_handler);

  sdl2render_init();
  sdl2render_run_loop();
  sdl2render_cleanup();
  return 0;
}

static void draw(void)
{
  render_bitmap_t* pix = render_get_buffer();
  bitmap_clear(pix);
  // bitmap_point(pix, 0, 0, POINT_SET);
  // bitmap_hline(pix, 0, pix->width - 1, 0, POINT_SET);
  for (int i = 0; i < 4; i++)
  {
    bitmap_rect(pix, i * 2, i * 2, pix->width - i * 4, pix->height - i * 4, POINT_SET);
  }
}

static void event_handler(render_event_t event)
{
  if (event.type == RENDER_EVENT_RESHAPE)
  {
    printf("r\n");
    draw();
    render_request_refresh();
  }
  if (event.type == RENDER_EVENT_FRAME)
  {
    printf("f");
    fflush(stdout);
  }
}
