#include "bitmap.h"
#include "font.h"
#include "font_helv8.h"
#include "font_micro.h"
#include "key.h"
#include "menu.h"
#include "render.h"
#include "sdl2_render_driver.h"
#include "util.h"
#include "window.h"
#include "window_manager.h"

#include <execinfo.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void event_handler(r_event_t event);
static void menu_selected(int idx);
static void segfault_handler(int sig);

char* menu_items[] = {"test", "else", "thing"};

menu_params_t params = {
    .item_list = menu_items,
    .num_items = 3,
    .win_rect = {10, 10, 30, 30},
    .selection_callback = &menu_selected,
    .draw_border = true};

menu_t menu;

static void menu_selected(int idx)
{
  printf("selected %d\n", idx);
}

static void draw(void)
{
  bmp_t* target = r_get_buffer();
  bmp_clear(target);
  win_draw_recursive(menu_get_win(menu), target);
  bmp_point(target, 0, 0, BMP_PXL_SET);
}

static void event_handler(r_event_t event)
{
  winmanager_send_event(event);

  switch (event.type)
  {
  case RENDER_EVENT_DRIVER_INITIALIZED:
  case RENDER_EVENT_RESHAPE:
    winmanager_vote_redraw();
    break;
  case RENDER_EVENT_FRAME:
    break;
  case RENDER_EVENT_KEYDOWN:
    break;
  case RENDER_EVENT_KEYUP:
    break;
  }

  if (winmanager_get_and_clear_redraw())
  {
    draw();
    r_request_refresh();
  }
}

static void segfault_handler(int sig)
{
  void* array[10];
  size_t size;

  size = backtrace(array, 10);
  fprintf(stderr, "Segfault %d", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

int main(int argc, char* argv[])
{
  signal(SIGSEGV, &segfault_handler);

  r_register_event_handler(event_handler);
  menu = menu_create(&params);
  menu_fit_height(menu);
  menu_get_win(menu)->enabled = true;

  winmanager_set_focused(menu_get_win(menu));

  sdl_init();
  sdl_main_loop();
  sdl_cleanup();
  return 0;
}
