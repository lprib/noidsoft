#ifndef _WINDOW_H_
#define _WINDOW_H_

/**
 * Window structure. Windows have a linked-list of children. When drawing
 * inside a window's draw_fn, use the win_X(...) functions, which have
 * coordinates referenced to the current window's top left corner.
 *
 * When children are docked (eg. win.dock = WIN_DOCK_BOTTOM | WIN_DOCK_RIGHT),
 * reshaping the parent will also reshape the children to maintain the docking.
 */

#include <stdbool.h>
#include <stdint.h>

#include "bitmap.h"
#include "font.h"
#include "render.h"
#include "util.h"

typedef enum
{
  WIN_DOCK_LEFT = 1,
  WIN_DOCK_RIGHT = 2,
  WIN_DOCK_TOP = 4,
  WIN_DOCK_BOTTOM = 8,
} win_dock_side_t;

struct win_s;

typedef void (*win_draw_fn_t)(struct win_s* self, bmp_t* target);

/**
 * Returns whether or not to consume the event.
 * If not consumed, the event will be passed to children (if enabled).
 */
typedef bool (*win_event_handler_t)(struct win_s* self, r_event_t event);

typedef struct win_s
{
  rect_t rect;
  /** Bitfield of win_dock_side_t */
  uint8_t dock;

  /** if !enabled, don't draw self and children */
  bool enabled;

  /** focused window receives events */
  bool focused;

  win_draw_fn_t draw_fn;
  win_event_handler_t event_handler;

  struct win_s* parent;

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

/**
 * Call windows event handler. If the window does not consume the event, it is
 * passed to the parent window.
 */
void win_handle_event(win_t* self, r_event_t event);

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
void win_string(
    win_t* self,
    bmp_t* target,
    font_t* font,
    char* string,
    int x,
    int y
);

#endif
