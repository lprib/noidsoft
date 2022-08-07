#include "menu.h"
#include "font.h"
#include "font_micro.h"
#include "window.h"

#include <stdlib.h>

static void menu_draw_fn(win_t* self, bmp_t* target);
static bool menu_event_handler(win_t* self, r_event_t event);

struct menu_t
{
  menu_params_t* params;
  int items_per_page;
  int page_start_index;
  int selected_index;
  win_t window;
};

menu_t menu_create(menu_params_t* params)
{
  int items_per_page = params->win_rect.h / font_height(&micro);
  menu_t menu = malloc(sizeof(*menu));
  menu->params = params;
  menu->items_per_page = items_per_page;
  menu->page_start_index = 0;
  menu->selected_index = 0;
  menu->window = (win_t
  ){.rect = params->win_rect,
    .dock = 0,
    .enabled = false,
    .focused = false,
    .draw_fn = &menu_draw_fn,
    .event_handler = &menu_event_handler};

  return menu;
}

win_t* menu_get_win(menu_t self)
{
  return &self->window;
}

static void menu_draw_fn(win_t* self, bmp_t* target)
{
  // TODO use containerof here to get the menu_t out
}

static bool menu_event_handler(win_t* self, r_event_t event)
{
}
