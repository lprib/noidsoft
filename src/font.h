#ifndef _FONT_H_
#define _FONT_H_

#include "bitmap.h"

// ASCII range
#define FONT_NUM_CHARS 128

typedef struct
{
  bmp_t bmp;
  int dwx;
  int dwy;
} font_glyph_t;

typedef struct
{
  int ascent;
  int descent;
  font_glyph_t* glyphs[FONT_NUM_CHARS];
} font_t;

#endif
