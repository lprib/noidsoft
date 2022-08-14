#include "textbox.h"

#include <mmi/font.h>
#include <mmi/window.h>

#define T textbox_t

struct T
{
  win_t win;
  char* buffer;
  int draw_start_index;
};
