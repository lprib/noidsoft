#ifndef _MMI_FONT_H_
#define _MMI_FONT_H_

/**
 * Utilities for drawing strings with a bitmap font.
 */

#include "bitmap.h"

#include <base/str.h>

#include <stdbool.h>
#include <stdint.h>

// ASCII range
#define FONT_NUM_CHARS 128

typedef struct
{
  bmp_t bmp;

  /** See BDF spec for definition of these fields */
  int8_t bb_off_x;
  int8_t bb_off_y;
  int8_t dw_x;
  int8_t dw_y;
} font_glyph_t;

typedef struct
{
  int8_t ascent;
  int8_t descent;
  /**
   * Uses array of pointers indirection because not every character from
   * 0..FONT_NUM_CHARS may be supported by this font.
   */
  font_glyph_t* glyphs[FONT_NUM_CHARS];
} font_t;

/**
 * Draw string to dest bitmap at specified x, y topleft coords.
 * Any unspupported characters in string will be rendered as char0 glyph.
 */
void font_string(
    bmp_t* dest,
    font_t* font,
    str_t str,
    int x,
    int y,
    bool invert
);

/** Get width in px of string if drawn with specified font */
int font_string_width(font_t* font, str_t str);

/** Total height of font (ascent + descent) */
int font_height(font_t* font);

#endif
