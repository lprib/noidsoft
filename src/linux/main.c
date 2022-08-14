#include "sdl2_render_driver.h"

#include <base/str.h>
#include <base/util.h>
#include <mmi/bitmap.h>
#include <mmi/font.h>
#include <mmi/font_helv8.h>
#include <mmi/font_micro.h>
#include <mmi/key.h>
#include <mmi/mmi.h>
#include <mmi/window.h>
#include <ui/menu.h>
#include <ui/window_manager.h>

#include <execinfo.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void create_menu(void);
static void event_handler(mmi_event_t event);
static void menu_selected(int idx);
static bool main_win_event_handler(win_t* self, mmi_event_t event);
static void segfault_handler(int sig);
static void main_win_draw(win_t* self, bmp_t* target);

win_t main_win = {
    .rect = {0, 0, 200, 200},
    .dock = WIN_DOCK_TOP | WIN_DOCK_LEFT | WIN_DOCK_BOTTOM | WIN_DOCK_RIGHT,
    .enabled = true,
    .focused = false,
    .dirty = false,
    .draw_fn = &main_win_draw,
    .event_handler = &main_win_event_handler};

menu_t menu;

static void create_menu(void)
{
  str_t menu_items[] = {
      str_new("Test Text"),
      str_new("More ....."),
      str_new("AbCdEfGhIjK"),
      str_new("1234567890")};

  menu_config_t params = {
      .items = menu_items,
      .items_len = sizeof(menu_items) / sizeof(menu_items[0]),
      .win_rect = {1, 1, 198, 198},
      .selection_callback = &menu_selected,
      .font = &helv8,
      .do_border = false};

  menu = menu_create(&params);
}

static void main_win_draw(win_t* self, bmp_t* target)
{
  win_clear_op(self, target, BMP_PXL_CLEAR);
}

static void menu_selected(int idx)
{
  printf("selected %d\n", idx);
}

bool menu_focused = false;

static bool main_win_event_handler(win_t* self, mmi_event_t event)
{
  if (event.type == RENDER_EVENT_KEYDOWN)
  {
    printf("parent %c\n", key_to_char(event.key_event.key));
    if (event.key_event.key == KEY_SPACE)
    {
      menu_focused = !menu_focused;
      if (menu_focused)
      {
        winmanager_set_focused(menu_get_win(menu));
      }
      else
      {
        winmanager_set_focused(&main_win);
      }
      menu_get_win(menu)->dirty = true;
    }
  }
  return true;
}

static void event_handler(mmi_event_t event)
{
  winmanager_send_event(event);

  bmp_t* target = mmi_get_render_target();

  switch (event.type)
  {
  case RENDER_EVENT_DRIVER_INITIALIZED:
    win_draw_recursive_unconditional(&main_win, target);
    mmi_display_refresh();
    break;
  case RENDER_EVENT_RESHAPE:
    win_reshape(&main_win, bmp_get_rect(target), true);
    main_win.dirty = true;
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
    mmi_display_refresh();
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

  mmi_register_event_handler(event_handler);
  /* menu_fit_height(menu); */
  /* menu_fit_width(menu); */
  create_menu();
  menu_get_win(menu)->enabled = true;
  menu_get_win(menu)->dock =
      WIN_DOCK_TOP | WIN_DOCK_LEFT | WIN_DOCK_RIGHT | WIN_DOCK_BOTTOM;

  win_add_child(&main_win, menu_get_win(menu));

  winmanager_set_focused(menu_get_win(menu));

  sdl_init();
  sdl_main_loop();
  sdl_cleanup();
  return 0;
}
