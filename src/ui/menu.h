#ifndef _UI_MENU_H_
#define _UI_MENU_H_

#include <base/util.h>
#include <mmi/font.h>
#include <mmi/window.h>

#include <stdbool.h>

#define T menu_t
typedef struct T* T;

typedef void (*menu_selection_callback_t)(int index);

typedef struct menu_item_t
{
  str_t* items;
  int items_len;
  bool do_border;
  font_t* font;
  rect_t win_rect;
  menu_selection_callback_t selection_callback;
} menu_config_t;

/**
 * Creates a menu from the parameters.
 * A menu contains it's own window, see menu_get_win.
 * The menu's window is initially disabled.
 */
T menu_create(menu_config_t* params);

/**
 * Get the window owned by this menu.
 */
win_t* menu_get_win(T self);

/**
 * Highlight the next item of the menu.
 * This is also done automatically by menu's window's event handler.
 */
void menu_next(T self);

/**
 * Highlight the previous item of the menu.
 * This is also done automatically by menu's window's event handler.
 */
void menu_prev(T self);

/**
 * Shrink or grow the menu's height to hold all of the menu's items on screen.
 */
void menu_fit_height(T self);

/**
 * Shrink or grow the menu's width to hold the maximum width of any one menu
 * item.
 */
void menu_fit_width(T self);

#undef T
#endif
