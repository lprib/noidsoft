#ifndef _FONT_H_
#define _FONT_H_

#include "bitmap.h"

// ASCII range
#define FONT_NUM_CHARS 128

typdef struct
{
  int start_elem;
  int width;
  int height;
  int y_offset;
} font_glyph_info_t;

typedef struct
{
  bmp_t bmp;
  font_glyph_info_t glyph_info[FONT_NUM_CHARS];
  int max_height;
} font_t;

#endif
