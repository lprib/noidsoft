#ifndef _FONT_H_
#define _FONT_H_

#include "bitmap.h"
#include <stdint.h>

// ASCII range
#define FONT_NUM_CHARS 128

typedef struct
{
  bmp_t bmp;
  int8_t bb_off_x;
  int8_t bb_off_y;
  int8_t dw_x;
  int8_t dw_y;
} font_glyph_t;

typedef struct
{
  int8_t ascent;
  int8_t descent;
  font_glyph_t* glyphs[FONT_NUM_CHARS];
} font_t;

void font_string(bmp_t* dest, font_t* font, char* string, int x, int y);
int font_string_width(font_t* font, char* string);

#endif
