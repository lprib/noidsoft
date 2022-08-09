#include "window.h"

#include <stdbool.h>

static win_t* currently_focused;
static bool redraw_requested;

void winmanager_set_focused(win_t* win)
{
  if (currently_focused)
  {
    currently_focused->focused = false;
  }

  currently_focused = win;
  win->focused = true;
}

void winmanager_send_event(r_event_t event)
{
  if (currently_focused)
  {
    win_handle_event(currently_focused, event);
  }
}

void winmanager_vote_redraw(void)
{
  redraw_requested = true;
}

bool winmanager_get_and_clear_redraw(void)
{
  bool prev_redraw = redraw_requested;
  redraw_requested = false;
  return prev_redraw;
}
