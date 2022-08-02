#ifndef _FONT_H_
#define _FONT_H_

#include "bitmap.h"

// ASCII range
#define FONT_NUM_CHARS 128

typedef struct
{
  bmp_t bmp;
  int bb_off_x;
  int bb_off_y;
  int dw_x;
  int dw_y;
} font_glyph_t;

typedef struct
{
  int ascent;
  int descent;
  font_glyph_t* glyphs[FONT_NUM_CHARS];
} font_t;

void font_char(bmp_t* dest, font_t* font, char c, int x, int y);

#endif
