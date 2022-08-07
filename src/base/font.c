#include "font.h"

#include "bitmap.h"
#include "util.h"
#include <stdbool.h>

/**
 * NOTE:
 * x, y here are referenced to the glyph's origin, which is the BOTTOM LEFT
 */
static inline void
draw_glyph(bmp_t* dest, font_glyph_t* glyph, int x, int y, bool invert)
{
  int top_left_x = x + glyph->bb_off_x;
  int top_left_y = y - glyph->bb_off_y - glyph->bmp.height;

  // TODO bake rect into bmp?
  rect_t src_rect = bmp_get_rect(&glyph->bmp);
  bmp_sprite(dest, &glyph->bmp, &src_rect, top_left_x, top_left_y, invert);
}

static inline font_glyph_t* get_or_fallback(font_t* font, char c)
{
  font_glyph_t* glyph = font->glyphs[(int)(c)];
  if (!glyph)
  {
    glyph = font->glyphs[0];
  }
  return glyph;
}

void font_string(
    bmp_t* dest,
    font_t* font,
    char* string,
    int x,
    int y,
    bool invert
)
{
  int x_acc = x;
  int y_acc = y + font->ascent;

  while (*string)
  {
    font_glyph_t* glyph = get_or_fallback(font, *string);
    draw_glyph(dest, glyph, x_acc, y_acc, invert);
    x_acc += glyph->dw_x;
    y_acc += glyph->dw_y;
    string++;
  }
}

int font_string_width(font_t* font, char* string)
{
  int width = 0;
  while (*string)
  {
    font_glyph_t* glyph = get_or_fallback(font, *string);
    width += glyph->dw_x;
    string++;
  }

  return width - 1;
}

int font_height(font_t* font)
{
  return font->ascent + font->descent;
}
