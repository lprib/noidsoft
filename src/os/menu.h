#ifndef _MENU_H_
#define _MENU_H_

#include "font.h"
#include "util.h"
#include "window.h"

#include <stdbool.h>

typedef void (*menu_selection_callback_t)(int index);

typedef struct menu_item_t
{
  char** items;
  int items_len;
  bool do_border;
  font_t* font;
  rect_t win_rect;
  menu_selection_callback_t selection_callback;
} menu_params_t;

typedef struct menu_t* menu_t;

/**
 * Creates a menu from the parameters.
 * A menu contains it's own window, see menu_get_win.
 * The menu's window is initially disabled.
 */
menu_t menu_create(menu_params_t* params);

/**
 * Get the window owned by this menu.
 */
win_t* menu_get_win(menu_t self);

/**
 * Highlight the next item of the menu.
 * This is also done automatically by menu's window's event handler.
 */
void menu_next(menu_t self);

/**
 * Highlight the previous item of the menu.
 * This is also done automatically by menu's window's event handler.
 */
void menu_prev(menu_t self);

/**
 * Shrink or grow the menu's height to hold all of the menu's items on screen.
 */
void menu_fit_height(menu_t self);

/**
 * Shrink or grow the menu's width to hold the maximum width of any one menu
 * item.
 */
void menu_fit_width(menu_t self);
#endif
