#include "textbox.h"

#include "font.h"
#include "menu.h"
#include "window.h"

struct T
{
  win_t win;
  char* buffer;
  int draw_start_index;
};
