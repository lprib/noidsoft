#ifndef _UI_TEXTBOX_H_
#define _UI_TEXTBOX_H_

#include <mmi/font.h>
#include <mmi/window.h>

#include <stdbool.h>

#define T textbox_t
typedef struct T* T;

typedef struct
{
  int max_len;
  rect_t win_rect;
  bool do_border;
  font_t* font;
} textbox_config_t;

/**
 * Creates a textbox from the parameters.
 * A textbox contains it's own window, see menu_get_win.
 * The textbox's window is initially disabled.
 */
T textbox_create(textbox_config_t config);

/**
 * Get the window owned by this textbox.
 */
win_t* textbox_get_win(T self);

char* textbox_get_text(T self);

/**
 * Shrink or grow the textbox's height to font size
 */
void textbox_fit_height(T self);

#undef T
#endif
