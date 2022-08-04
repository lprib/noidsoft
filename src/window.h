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

typedef void (*win_draw_fn_t)(struct win_s* self, bmp_t* target);

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

/**
 * If enabled, draw the window and children recursively.
 */
void win_draw_recursive(win_t* self, bmp_t* dest);

/**
 * Resize the window, and reshape docked children if specified
 */
void win_reshape(win_t* self, rect_t new_size, bool reshape_children);

/**
 * Add a child window. Also sets the child's graphics context to point to the
 * same render bitmap.
 */
void win_add_child(win_t* parent, win_t* child);

/**
 * Returns whether the child was found (and removed) in the parent
 * TODO untested
 */
bool win_remove_child(win_t* parent, win_t* child);

// Implemented in window_graphics.c
void win_point(win_t* self, bmp_t* target, int x, int y, bmp_op_t op);
void win_hline(win_t* self, bmp_t* target, int x1, int x2, int y, bmp_op_t op);
void win_vline(win_t* self, bmp_t* target, int y1, int y2, int x, bmp_op_t op);
void win_rect(win_t* self, bmp_t* target, rect_t rect, bmp_op_t op);
void win_fill_rect(win_t* self, bmp_t* target, rect_t rect, bmp_op_t op);
void win_sprite(
    win_t* self,
    bmp_t* target,
    bmp_t* src,
    rect_t* src_rect,
    int x,
    int y
);

#endif
