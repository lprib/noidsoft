#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

/**
 * Manages a set of windows.
 *
 * This module is a singleton.
 */

#include "render.h"
#include "window.h"

/**
 * Unfocus the previously focused window, and focus win.
 */
void winmanager_set_focused(win_t* win);

/**
 * Send an event to the currently focused window.
 */
void winmanager_send_event(r_event_t event);

#endif
