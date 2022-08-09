#include "menu.h"
#include "font.h"
#include "font_micro.h"
#include "window.h"

#include <stdio.h>
#include <stdlib.h>

// padding below text
static int const between_row_padding = 1;
// padding between menu selection and outer border
static int const outer_padding = 1;
// padding between text and selection bounding box
static int const inner_padding_x = 1;

static void menu_draw_fn(win_t* self, bmp_t* target);
static bool menu_event_handler(win_t* self, r_event_t event);

struct menu_t
{
  // Client defined items
  char** items;
  int items_len;
  bool do_border;
  menu_selection_callback_t selection_callback;

  // Internally defined items
  int page_len;
  int page_start_index;
  int selected_index;
  win_t win;
};

static inline int row_height(void)
{
  return font_height(&micro) + between_row_padding;
}

static inline int get_items_per_page(menu_t self)
{
  if (self->do_border)
  {
    return (self->win.rect.h - outer_padding * 2 - 2) / row_height();
  }
  else
  {
    return self->win.rect.h / row_height();
  }
}

static inline int screen_to_array_item_index(menu_t self, int idx)
{
  return (self->page_start_index + idx) % self->items_len;
}

static inline void increment_wrap(int* n, int size)
{
  if (*n >= size - 1)
  {
    *n = 0;
  }
  else
  {
    (*n)++;
  }
}

static inline void decrement_wrap(int* n, int size)
{
  if (*n <= 0)
  {
    *n = size - 1;
  }
  else
  {
    (*n)--;
  }
}

menu_t menu_create(menu_params_t* params)
{
  menu_t menu = malloc(sizeof(*menu));
  menu->items = params->items;
  menu->items_len = params->items_len;
  menu->do_border = params->do_border;
  menu->selection_callback = params->selection_callback;

  menu->page_start_index = 0;
  menu->selected_index = 0;
  menu->win = (win_t
  ){.rect = params->win_rect,
    .dock = 0,
    .enabled = false,
    .focused = false,
    .draw_fn = &menu_draw_fn,
    .event_handler = &menu_event_handler};

  menu->page_len = util_min(menu->items_len, get_items_per_page(menu));

  return menu;
}

win_t* menu_get_win(menu_t self)
{
  return &self->win;
}

void menu_next(menu_t self)
{
  int page_end_index =
      (self->page_start_index + self->page_len - 1) % self->items_len;

  if (self->selected_index == page_end_index)
  {
    // at the end of a page, scroll the page down
    increment_wrap(&self->page_start_index, self->items_len);
  }
  increment_wrap(&self->selected_index, self->items_len);

  printf("page %d, idx %d\n", self->page_start_index, self->selected_index);
  self->win.dirty = true;
}

void menu_prev(menu_t self)
{
  if (self->selected_index == self->page_start_index)
  {
    // at the start of a page, scroll the page up
    decrement_wrap(&self->page_start_index, self->items_len);
  }
  decrement_wrap(&self->selected_index, self->items_len);
  printf("page %d, idx %d\n", self->page_start_index, self->selected_index);
  self->win.dirty = true;
}

void menu_fit_height(menu_t self)
{
  self->win.rect.h = self->items_len * row_height() + outer_padding * 2 + 2;
  self->page_len = self->items_len;
  self->win.dirty = true;
}

void menu_fit_width(menu_t self)
{
  int max_string_width = 0;
  for (int i = 0; i < self->items_len; i++)
  {
    int item_width = font_string_width(&micro, self->items[i]);
    if (item_width > max_string_width)
    {
      max_string_width = item_width;
    }
  }

  if (self->do_border)
  {
    self->win.rect.w =
        max_string_width + inner_padding_x * 2 + outer_padding * 2 + 2;
  }
  else
  {
    self->win.rect.w = max_string_width + inner_padding_x * 2;
  }
  printf("neww = %d\n", self->win.rect.w);
  self->win.dirty = true;
}

static void menu_draw_fn(win_t* win, bmp_t* target)
{
  printf("redraw\n");
  menu_t self = util_container_of(win, struct menu_t, win);
  bool border = self->do_border;

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
  for (int i = 0; i < self->page_len; i++)
  {
    int index = screen_to_array_item_index(self, i);
    bool selected = index == self->selected_index;
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
        self->items[index],
        row_x + inner_padding_x,
        row_y,
        selected
    );
  }
}

static bool menu_event_handler(win_t* win, r_event_t event)
{
  menu_t self = util_container_of(win, struct menu_t, win);

  if (event.type == RENDER_EVENT_KEYDOWN)
  {
    switch (event.key_event.key)
    {
    case KEY_J:
      menu_next(self);
      return true;
    case KEY_K:
      menu_prev(self);
      return true;
    case KEY_L:
      self->selection_callback(self->selected_index);
    default:
      return false;
    }
  }
  return false;
}
