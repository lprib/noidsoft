#include "window.h"

#include <stddef.h>

static inline void
resize_child(win_t* child, rect_t parent_old_size, rect_t parent_new_size)
{
  bool dock_left = child->dock & WIN_DOCK_LEFT;
  bool dock_right = child->dock & WIN_DOCK_RIGHT;
  bool dock_top = child->dock & WIN_DOCK_TOP;
  bool dock_bottom = child->dock & WIN_DOCK_BOTTOM;

  int parent_left_diff = parent_new_size.x - parent_old_size.x;
  int parent_top_diff = parent_new_size.y - parent_old_size.y;

  int parent_old_right = parent_old_size.x + parent_old_size.w;
  int parent_new_right = parent_new_size.x + parent_new_size.w;
  int parent_right_diff = parent_new_right - parent_old_right;

  int parent_old_bottom = parent_old_size.y + parent_old_size.h;
  int parent_new_bottom = parent_new_size.y + parent_new_size.h;
  int parent_bottom_diff = parent_new_bottom - parent_old_bottom;

  if (dock_left)
  {
    child->rect.x += parent_left_diff;
  }
  if (dock_top)
  {
    child->rect.y += parent_top_diff;
  }
  if (dock_right)
  {
    if (!dock_left)
    {
      // docked to a single side on this axis, so move the whole rect
      child->rect.x += parent_right_diff;
    }
    else
    {
      child->rect.w += parent_right_diff;
      child->rect.w -= parent_left_diff;
    }
  }
  if (dock_bottom)
  {
    if (!dock_top)
    {
      // docked to a single side on this axis, so move the whole rect
      child->rect.y += parent_bottom_diff;
    }
    else
    {
      child->rect.h += parent_bottom_diff;
      child->rect.h -= parent_top_diff;
    }
  }
}

void win_draw_recursive(win_t* self, bmp_t* dest)
{
  if (self->enabled)
  {
    self->draw_fn(self, dest);

    win_t* child = self->children;
    while (child)
    {
      win_draw_recursive(child, dest);
      child = child->next_sibling;
    }
  }
}

void win_reshape(win_t* self, rect_t new_size, bool reshape_children)
{
  if (reshape_children)
  {
    win_t* child = self->children;
    while (child)
    {
      resize_child(child, self->rect, new_size);
      child = child->next_sibling;
    }
  }
  self->rect = new_size;
}

void win_add_child(win_t* parent, win_t* child)
{
  win_t* last_child = parent->children;

  child->next_sibling = NULL;
  child->prev_sibling = NULL;

  if (last_child)
  {
    while (last_child->next_sibling)
    {
      last_child = last_child->next_sibling;
    }
    last_child->next_sibling = child;
    child->prev_sibling = last_child;
  }
  else
  {
    parent->children = child;
  }
}

bool wim_remove_child(win_t* parent, win_t* child)
{
  win_t* cur_child = parent->children;
  while (cur_child)
  {
    if (cur_child == child)
    {
      if (cur_child->next_sibling)
      {
        // cur_child->prev_sibling may be NULL
        cur_child->next_sibling->prev_sibling = cur_child->prev_sibling;
      }

      if (cur_child->prev_sibling)
      {
        // cur_child->next_sibling may be NULL
        cur_child->prev_sibling->next_sibling = cur_child->next_sibling;
      }

      child->next_sibling = NULL;
      child->prev_sibling = NULL;
      return true;
    }

    cur_child = child->next_sibling;
  }
  return false;
}
