#include "font.h"

#include "bitmap.h"

/**
 * NOTE:
 * x, y here are referenced to the glyph's origin, which is the BOTTOM LEFT
 */
static inline void draw_glyph(bmp_t* dest, font_glyph_t* glyph, int x, int y)
{
  int top_left_x = x + glyph->bb_off_x;
  int top_left_y = y - glyph->bb_off_y - glyph->bmp.height;

  // TODO bake rect into bmp?
  bmp_rect_t src_rect = {0, 0, glyph->bmp.width, glyph->bmp.height};
  bmp_sprite(dest, &glyph->bmp, &src_rect, top_left_x, top_left_y);
}

void font_string(bmp_t* dest, font_t* font, char* string, int x, int y)
{
  int x_acc = x;
  int y_acc = y + font->ascent;

  while (*string)
  {
    font_glyph_t* glyph = font->glyphs[(int)(*string)];
    if (!glyph)
    {
      glyph = font->glyphs[0];
    }
    draw_glyph(dest, glyph, x_acc, y_acc);
    x_acc += glyph->dw_x;
    y_acc += glyph->dw_y;
    string++;
  }
}
