#include "font.h"

#include "bitmap.h"

void font_char(bmp_t* dest, font_t* font, char c, int x, int y)
{
  font_glyph_t* glyph = font->glyphs[(int)c];
  if (!glyph)
  {
    glyph = font->glyphs[0];
  }

  int top_left_x = x + glyph->bb_off_x;
  int top_left_y = y + glyph->bb_off_y - glyph->bmp.height;

  // TODO bake rect into bmp?
  bmp_rect_t src_rect = {0, 0, glyph->bmp.width, glyph->bmp.height};
  bmp_sprite(dest, &glyph->bmp, &src_rect, top_left_x, top_left_y);
}
