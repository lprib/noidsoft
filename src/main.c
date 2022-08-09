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
static void main_win_draw(win_t* self, bmp_t* target);

char* menu_items[] = {"zero", "one", "two"};

win_t main_win = {
    .rect = {0, 0, 128, 64},
    .dock = WIN_DOCK_TOP | WIN_DOCK_LEFT | WIN_DOCK_BOTTOM | WIN_DOCK_RIGHT,
    .enabled = true,
    .focused = false,
    .dirty = false,
    .draw_fn = &main_win_draw};

menu_params_t params = {
    .items = menu_items,
    .items_len = 3,
    .win_rect = {10, 10, 30, 30},
    .selection_callback = &menu_selected,
    .do_border = true};

menu_t menu;

static void main_win_draw(win_t* self, bmp_t* target)
{
  win_clear_op(self, target, BMP_PXL_CLEAR);
}

static void menu_selected(int idx)
{
  printf("selected %d\n", idx);
}

static void event_handler(r_event_t event)
{
  winmanager_send_event(event);

  bmp_t* target = r_get_buffer();

  switch (event.type)
  {
  case RENDER_EVENT_DRIVER_INITIALIZED:
    win_draw_recursive_unconditional(&main_win, target);
    r_request_refresh();
    break;
  case RENDER_EVENT_RESHAPE:
    menu_get_win(menu)->dirty = true;
    break;
  case RENDER_EVENT_FRAME:
    break;
  case RENDER_EVENT_KEYDOWN:
    break;
  case RENDER_EVENT_KEYUP:
    break;
  }

  if (win_draw_recursive_if_dirty(&main_win, target))
  {
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
  menu_fit_width(menu);
  menu_get_win(menu)->enabled = true;

  win_add_child(&main_win, menu_get_win(menu));

  winmanager_set_focused(menu_get_win(menu));

  sdl_init();
  sdl_main_loop();
  sdl_cleanup();
  return 0;
}
