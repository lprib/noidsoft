#include "ui_main.h"

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

#include <stdbool.h>

#include <stdio.h>
#include <string.h>

static void create_menu(void);
static void event_handler(mmi_event_t event);
static void menu_selected(int idx);
static bool main_win_event_handler(win_t* self, mmi_event_t event);
static void main_win_draw(win_t* self, bmp_t* target);

win_t main_win = {
    .rect = {0, 0, 128, 64},
    .dock = 0,
    .enabled = true,
    .focused = false,
    .dirty = false,
    .draw_fn = &main_win_draw,
    .event_handler = &main_win_event_handler};

menu_t menu;

str_t* menu_items;

static void create_menu(void)
{
  str_t internal_menu_items[] =
      {str_new("Test"), str_new("More"), str_new("AbCdjK"), str_new("12340")};

  menu_items = malloc(sizeof(internal_menu_items));
  memcpy(menu_items, internal_menu_items, sizeof(internal_menu_items));

  menu_config_t params = {
      .items = menu_items,
      .items_len = sizeof(internal_menu_items) / sizeof(internal_menu_items[0]),
      .win_rect = {1, 1, 126, 62},
      .selection_callback = &menu_selected,
      .font = &helv8,
      .do_border = true};

  menu = menu_create(&params);
}

static void main_win_draw(win_t* self, bmp_t* target)
{
  win_clear_op(self, target, BMP_PXL_CLEAR);
  win_rect(
      self,
      target,
      (rect_t){0, 0, self->rect.w, self->rect.h},
      BMP_PXL_SET
  );
}

static void menu_selected(int idx)
{
  /* printf("selected %d\n", idx); */
}

bool menu_focused = false;

static bool main_win_event_handler(win_t* self, mmi_event_t event)
{
  if (event.type == RENDER_EVENT_KEYDOWN)
  {
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
    winmanager_send_event(event);
    break;
  case RENDER_EVENT_KEYUP:
    break;
  }

  if (win_draw_recursive_if_dirty(&main_win, target))
  {
    mmi_display_refresh();
  }
}

void ui_init(void)
{
  mmi_register_event_handler(event_handler);
  // menu_fit_height(menu);
  // menu_fit_width(menu);

  create_menu();
  menu_get_win(menu)->enabled = true;
  win_add_child(&main_win, menu_get_win(menu));
  winmanager_set_focused(menu_get_win(menu));

  // bmp_t* t = mmi_get_render_target();
  // bmp_clear(t);
  // font_string(t, &helv8, str_new("hello"), 0, 0, false);
  // mmi_display_refresh();
}
