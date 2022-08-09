#include "menu.h"
#include "font.h"
#include "font_micro.h"
#include "window.h"

#include "window_manager.h"

#include <stdio.h>
#include <stdlib.h>

static int const between_row_padding = 1;
static int const outer_padding = 1;

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

static inline int row_height(void)
{
  return font_height(&micro) + between_row_padding;
}

static inline int get_items_per_page(menu_t self)
{
  if (self->params->draw_border)
  {
    return (self->params->win_rect.h - outer_padding * 2 - 2) / row_height();
  }
  else
  {
    return self->params->win_rect.h / row_height();
  }
}

menu_t menu_create(menu_params_t* params)
{
  menu_t menu = malloc(sizeof(*menu));
  menu->params = params;
  menu->page_start_index = 0;
  menu->selected_index = 0;
  menu->window = (win_t
  ){.rect = params->win_rect,
    .dock = 0,
    .enabled = false,
    .focused = false,
    .draw_fn = &menu_draw_fn,
    .event_handler = &menu_event_handler};

  menu->items_per_page = get_items_per_page(menu);

  return menu;
}

win_t* menu_get_win(menu_t self)
{
  return &self->window;
}

void menu_next(menu_t self)
{
  self->selected_index++;
  winmanager_vote_redraw();
}

void menu_prev(menu_t self)
{
  self->selected_index--;
  winmanager_vote_redraw();
}

void menu_fit_height(menu_t self)
{
  self->window.rect.h =
      self->params->num_items * row_height() + outer_padding * 2 + 2;
  self->items_per_page = self->params->num_items;
}

static void menu_draw_fn(win_t* win, bmp_t* target)
{
  menu_t menu = container_of(win, struct menu_t, window);
  bool border = menu->params->draw_border;

  win_clear_op(win, target, BMP_PXL_CLEAR);
  if (border)
  {
    win_rect(
        win,
        target,
        (rect_t){0, 0, win->rect.w, win->rect.h},
        BMP_PXL_SET
    );
  }

  // TODO use containerof here to get the menu_t out
  for (int i = 0; i < menu->items_per_page; i++)
  {
    int index = (menu->page_start_index + i) % menu->params->num_items;
    bool selected = index == menu->selected_index;
    int row_y = i * row_height() + (border ? outer_padding + 1 : 0);
    int row_x = border ? outer_padding + 1 : 0;
    int highlight_w =
        border ? win->rect.w - outer_padding * 2 - 2 : win->rect.w;

    if (selected)
    {
      win_fill_rect(
          win,
          target,
          (rect_t){row_x, row_y, highlight_w, row_height()},
          BMP_PXL_SET
      );
    }

    win_string(
        win,
        target,
        &micro,
        menu->params->item_list[index],
        row_x,
        row_y,
        selected
    );
  }
}

static bool menu_event_handler(win_t* self, r_event_t event)
{
  menu_t menu = container_of(self, struct menu_t, window);

  if (event.type == RENDER_EVENT_KEYDOWN)
  {
    switch (event.key_event.key)
    {
    case KEY_J:
      menu_next(menu);
      return true;
    case KEY_K:
      menu_prev(menu);
      return true;
    case KEY_L:
      menu->params->selection_callback(menu->selected_index);
    default:
      return false;
    }
  }
  return false;
}
