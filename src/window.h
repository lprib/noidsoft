#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <stdbool.h>
#include <stdint.h>

#include "bitmap.h"
#include "util.h"

#define WIN_DOCK_LEFT 1
#define WIN_DOCK_RIGHT 2
#define WIN_DOCK_TOP 4
#define WIN_DOCK_BOTTOM 8

struct win_s;

typedef void (*win_draw_fn_t)(struct win_s* self, bmp_t* dest);

typedef struct win_s
{
  rect_t rect;
  uint8_t dock;
  bool enabled;

  win_draw_fn_t draw_fn;

  /** pointer to head of chilren linked list */
  struct win_s* children;

  /** linked list */
  struct win_s* next_sibling;
  struct win_s* prev_sibling;
} win_t;

void win_draw_recursive(win_t* self, bmp_t* dest);
void win_reshape(win_t* self, rect_t new_size, bool reshape_children);
void win_add_child(win_t* parent, win_t* child);

#endif
