#ifndef _MENU_H_
#define _MENU_H_

#include "util.h"
#include "window.h"

#include <stdbool.h>

typedef void (*menu_selection_callback_t)(int index);

typedef struct menu_item_t
{
  char** item_list;
  int num_items;
  rect_t win_rect;
  menu_selection_callback_t selection_callback;
  bool draw_border;
} menu_params_t;

typedef struct menu_t* menu_t;

menu_t menu_create(menu_params_t* params);

win_t* menu_get_win(menu_t self);

void menu_next(menu_t self);
void menu_prev(menu_t self);
void menu_fit_height(menu_t self);
#endif
