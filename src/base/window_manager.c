#include "window.h"

static win_t* currently_focused;

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
