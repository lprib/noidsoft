#include "textbox.h"

#include <render/font.h>
#include <render/window.h>

#define T textbox_t

struct T
{
  win_t win;
  char* buffer;
  int draw_start_index;
};
