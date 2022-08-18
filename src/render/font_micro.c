#include "bitmap.h"
#include "font.h"
/* clang-format off */
static bmp_elem_t micro_bitmap_C000[] = {
  0x0000,
  0xe000,
  0xe000,
  0xe000,
  0x0000,
};
static font_glyph_t micro_glyph_C000 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_C000
  }
};

static bmp_elem_t micro_bitmap_C040[] = {
  0x0000,
  0x0000,
  0x0000,
  0x0000,
  0x0000,
};
static font_glyph_t micro_glyph_C040 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_C040
  }
};

static bmp_elem_t micro_bitmap_A[] = {
  0xe000,
  0xa000,
  0xe000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_A = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_A
  }
};

static bmp_elem_t micro_bitmap_B[] = {
  0xe000,
  0xa000,
  0xc000,
  0xa000,
  0xe000,
};
static font_glyph_t micro_glyph_B = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_B
  }
};

static bmp_elem_t micro_bitmap_C[] = {
  0xe000,
  0x8000,
  0x8000,
  0x8000,
  0xe000,
};
static font_glyph_t micro_glyph_C = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_C
  }
};

static bmp_elem_t micro_bitmap_D[] = {
  0xc000,
  0xa000,
  0xa000,
  0xa000,
  0xc000,
};
static font_glyph_t micro_glyph_D = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_D
  }
};

static bmp_elem_t micro_bitmap_E[] = {
  0xe000,
  0x8000,
  0xe000,
  0x8000,
  0xe000,
};
static font_glyph_t micro_glyph_E = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_E
  }
};

static bmp_elem_t micro_bitmap_F[] = {
  0xe000,
  0x8000,
  0xe000,
  0x8000,
  0x8000,
};
static font_glyph_t micro_glyph_F = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_F
  }
};

static bmp_elem_t micro_bitmap_G[] = {
  0xe000,
  0x8000,
  0xa000,
  0xa000,
  0xe000,
};
static font_glyph_t micro_glyph_G = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_G
  }
};

static bmp_elem_t micro_bitmap_H[] = {
  0xa000,
  0xa000,
  0xe000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_H = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_H
  }
};

static bmp_elem_t micro_bitmap_I[] = {
  0xe000,
  0x4000,
  0x4000,
  0x4000,
  0xe000,
};
static font_glyph_t micro_glyph_I = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_I
  }
};

static bmp_elem_t micro_bitmap_J[] = {
  0x2000,
  0x2000,
  0x2000,
  0xa000,
  0xe000,
};
static font_glyph_t micro_glyph_J = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_J
  }
};

static bmp_elem_t micro_bitmap_K[] = {
  0xa000,
  0xa000,
  0xc000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_K = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_K
  }
};

static bmp_elem_t micro_bitmap_L[] = {
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0xe000,
};
static font_glyph_t micro_glyph_L = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_L
  }
};

static bmp_elem_t micro_bitmap_M[] = {
  0xa000,
  0xe000,
  0xa000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_M = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_M
  }
};

static bmp_elem_t micro_bitmap_N[] = {
  0xe000,
  0xa000,
  0xa000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_N = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_N
  }
};

static bmp_elem_t micro_bitmap_O[] = {
  0xe000,
  0xa000,
  0xa000,
  0xa000,
  0xe000,
};
static font_glyph_t micro_glyph_O = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_O
  }
};

static bmp_elem_t micro_bitmap_P[] = {
  0xe000,
  0xa000,
  0xe000,
  0x8000,
  0x8000,
};
static font_glyph_t micro_glyph_P = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_P
  }
};

static bmp_elem_t micro_bitmap_Q[] = {
  0xe000,
  0xa000,
  0xa000,
  0xc000,
  0x6000,
};
static font_glyph_t micro_glyph_Q = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_Q
  }
};

static bmp_elem_t micro_bitmap_R[] = {
  0xe000,
  0xa000,
  0xc000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_R = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_R
  }
};

static bmp_elem_t micro_bitmap_S[] = {
  0xe000,
  0x8000,
  0xe000,
  0x2000,
  0xe000,
};
static font_glyph_t micro_glyph_S = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_S
  }
};

static bmp_elem_t micro_bitmap_T[] = {
  0xe000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
};
static font_glyph_t micro_glyph_T = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_T
  }
};

static bmp_elem_t micro_bitmap_U[] = {
  0xa000,
  0xa000,
  0xa000,
  0xa000,
  0xe000,
};
static font_glyph_t micro_glyph_U = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_U
  }
};

static bmp_elem_t micro_bitmap_V[] = {
  0xa000,
  0xa000,
  0xa000,
  0xa000,
  0x4000,
};
static font_glyph_t micro_glyph_V = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_V
  }
};

static bmp_elem_t micro_bitmap_W[] = {
  0xa000,
  0xa000,
  0xa000,
  0xe000,
  0xa000,
};
static font_glyph_t micro_glyph_W = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_W
  }
};

static bmp_elem_t micro_bitmap_X[] = {
  0xa000,
  0xe000,
  0x4000,
  0xe000,
  0xa000,
};
static font_glyph_t micro_glyph_X = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_X
  }
};

static bmp_elem_t micro_bitmap_Y[] = {
  0xa000,
  0xa000,
  0xe000,
  0x4000,
  0x4000,
};
static font_glyph_t micro_glyph_Y = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_Y
  }
};

static bmp_elem_t micro_bitmap_Z[] = {
  0xe000,
  0x2000,
  0x4000,
  0x8000,
  0xe000,
};
static font_glyph_t micro_glyph_Z = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_Z
  }
};

static bmp_elem_t micro_bitmap_a[] = {
  0x0000,
  0xc000,
  0x6000,
  0xa000,
  0x6000,
};
static font_glyph_t micro_glyph_a = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_a
  }
};

static bmp_elem_t micro_bitmap_b[] = {
  0x8000,
  0xc000,
  0xa000,
  0xa000,
  0xc000,
};
static font_glyph_t micro_glyph_b = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_b
  }
};

static bmp_elem_t micro_bitmap_c[] = {
  0x0000,
  0x6000,
  0x8000,
  0x8000,
  0x6000,
};
static font_glyph_t micro_glyph_c = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_c
  }
};

static bmp_elem_t micro_bitmap_d[] = {
  0x2000,
  0x6000,
  0xa000,
  0xa000,
  0x6000,
};
static font_glyph_t micro_glyph_d = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_d
  }
};

static bmp_elem_t micro_bitmap_e[] = {
  0x0000,
  0x6000,
  0xa000,
  0xc000,
  0x6000,
};
static font_glyph_t micro_glyph_e = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_e
  }
};

static bmp_elem_t micro_bitmap_f[] = {
  0x6000,
  0x8000,
  0xc000,
  0x8000,
  0x8000,
};
static font_glyph_t micro_glyph_f = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_f
  }
};

static bmp_elem_t micro_bitmap_g[] = {
  0x0000,
  0xc000,
  0xa000,
  0x6000,
  0xc000,
};
static font_glyph_t micro_glyph_g = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_g
  }
};

static bmp_elem_t micro_bitmap_h[] = {
  0x8000,
  0xc000,
  0xa000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_h = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_h
  }
};

static bmp_elem_t micro_bitmap_i[] = {
  0x8000,
  0x0000,
  0x8000,
  0x8000,
  0x8000,
};
static font_glyph_t micro_glyph_i = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 2,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_i
  }
};

static bmp_elem_t micro_bitmap_j[] = {
  0x0000,
  0x2000,
  0x2000,
  0xa000,
  0x4000,
};
static font_glyph_t micro_glyph_j = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_j
  }
};

static bmp_elem_t micro_bitmap_k[] = {
  0x8000,
  0xa000,
  0xc000,
  0xc000,
  0xa000,
};
static font_glyph_t micro_glyph_k = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_k
  }
};

static bmp_elem_t micro_bitmap_l[] = {
  0xc000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
};
static font_glyph_t micro_glyph_l = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_l
  }
};

static bmp_elem_t micro_bitmap_m[] = {
  0x0000,
  0xe000,
  0xe000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_m = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_m
  }
};

static bmp_elem_t micro_bitmap_n[] = {
  0x0000,
  0xc000,
  0xa000,
  0xa000,
  0xa000,
};
static font_glyph_t micro_glyph_n = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_n
  }
};

static bmp_elem_t micro_bitmap_o[] = {
  0x0000,
  0x4000,
  0xa000,
  0xa000,
  0x4000,
};
static font_glyph_t micro_glyph_o = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_o
  }
};

static bmp_elem_t micro_bitmap_p[] = {
  0x0000,
  0xc000,
  0xa000,
  0xc000,
  0x8000,
};
static font_glyph_t micro_glyph_p = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_p
  }
};

static bmp_elem_t micro_bitmap_q[] = {
  0x0000,
  0x6000,
  0xa000,
  0x6000,
  0x2000,
};
static font_glyph_t micro_glyph_q = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_q
  }
};

static bmp_elem_t micro_bitmap_r[] = {
  0x0000,
  0xc000,
  0xa000,
  0x8000,
  0x8000,
};
static font_glyph_t micro_glyph_r = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_r
  }
};

static bmp_elem_t micro_bitmap_s[] = {
  0x0000,
  0x6000,
  0xc000,
  0x6000,
  0xc000,
};
static font_glyph_t micro_glyph_s = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_s
  }
};

static bmp_elem_t micro_bitmap_t[] = {
  0x4000,
  0xe000,
  0x4000,
  0x4000,
  0x2000,
};
static font_glyph_t micro_glyph_t = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_t
  }
};

static bmp_elem_t micro_bitmap_u[] = {
  0x0000,
  0xa000,
  0xa000,
  0xa000,
  0x6000,
};
static font_glyph_t micro_glyph_u = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_u
  }
};

static bmp_elem_t micro_bitmap_v[] = {
  0x0000,
  0xa000,
  0xa000,
  0xa000,
  0x4000,
};
static font_glyph_t micro_glyph_v = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_v
  }
};

static bmp_elem_t micro_bitmap_w[] = {
  0x0000,
  0xa000,
  0xa000,
  0xe000,
  0xe000,
};
static font_glyph_t micro_glyph_w = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_w
  }
};

static bmp_elem_t micro_bitmap_x[] = {
  0x0000,
  0xa000,
  0x4000,
  0x4000,
  0xa000,
};
static font_glyph_t micro_glyph_x = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_x
  }
};

static bmp_elem_t micro_bitmap_y[] = {
  0x0000,
  0xa000,
  0xa000,
  0x6000,
  0xc000,
};
static font_glyph_t micro_glyph_y = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_y
  }
};

static bmp_elem_t micro_bitmap_z[] = {
  0x0000,
  0xe000,
  0x6000,
  0xc000,
  0xe000,
};
static font_glyph_t micro_glyph_z = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_z
  }
};

static bmp_elem_t micro_bitmap_0[] = {
  0x4000,
  0xa000,
  0xa000,
  0xa000,
  0x4000,
};
static font_glyph_t micro_glyph_0 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_0
  }
};

static bmp_elem_t micro_bitmap_1[] = {
  0x4000,
  0xc000,
  0x4000,
  0x4000,
  0x4000,
};
static font_glyph_t micro_glyph_1 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_1
  }
};

static bmp_elem_t micro_bitmap_2[] = {
  0xc000,
  0x2000,
  0x4000,
  0x8000,
  0xe000,
};
static font_glyph_t micro_glyph_2 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_2
  }
};

static bmp_elem_t micro_bitmap_3[] = {
  0xc000,
  0x2000,
  0x6000,
  0x2000,
  0xe000,
};
static font_glyph_t micro_glyph_3 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_3
  }
};

static bmp_elem_t micro_bitmap_4[] = {
  0xa000,
  0xa000,
  0xa000,
  0xe000,
  0x2000,
};
static font_glyph_t micro_glyph_4 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_4
  }
};

static bmp_elem_t micro_bitmap_5[] = {
  0xe000,
  0x8000,
  0xc000,
  0x2000,
  0xc000,
};
static font_glyph_t micro_glyph_5 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_5
  }
};

static bmp_elem_t micro_bitmap_6[] = {
  0x6000,
  0x8000,
  0xe000,
  0xa000,
  0xe000,
};
static font_glyph_t micro_glyph_6 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_6
  }
};

static bmp_elem_t micro_bitmap_7[] = {
  0xe000,
  0x2000,
  0x2000,
  0x4000,
  0x4000,
};
static font_glyph_t micro_glyph_7 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_7
  }
};

static bmp_elem_t micro_bitmap_8[] = {
  0xe000,
  0xa000,
  0xe000,
  0xa000,
  0xe000,
};
static font_glyph_t micro_glyph_8 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_8
  }
};

static bmp_elem_t micro_bitmap_9[] = {
  0xe000,
  0xa000,
  0xe000,
  0x2000,
  0xc000,
};
static font_glyph_t micro_glyph_9 = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 5,
    .width_elems = 1,
    .buffer = micro_bitmap_9
  }
};


font_t micro = {
  .ascent = 5,
  .descent = 0,
  .glyphs = {
    [0] = &micro_glyph_C000,
    [32] = &micro_glyph_C040,
    [65] = &micro_glyph_A,
    [66] = &micro_glyph_B,
    [67] = &micro_glyph_C,
    [68] = &micro_glyph_D,
    [69] = &micro_glyph_E,
    [70] = &micro_glyph_F,
    [71] = &micro_glyph_G,
    [72] = &micro_glyph_H,
    [73] = &micro_glyph_I,
    [74] = &micro_glyph_J,
    [75] = &micro_glyph_K,
    [76] = &micro_glyph_L,
    [77] = &micro_glyph_M,
    [78] = &micro_glyph_N,
    [79] = &micro_glyph_O,
    [80] = &micro_glyph_P,
    [81] = &micro_glyph_Q,
    [82] = &micro_glyph_R,
    [83] = &micro_glyph_S,
    [84] = &micro_glyph_T,
    [85] = &micro_glyph_U,
    [86] = &micro_glyph_V,
    [87] = &micro_glyph_W,
    [88] = &micro_glyph_X,
    [89] = &micro_glyph_Y,
    [90] = &micro_glyph_Z,
    [97] = &micro_glyph_a,
    [98] = &micro_glyph_b,
    [99] = &micro_glyph_c,
    [100] = &micro_glyph_d,
    [101] = &micro_glyph_e,
    [102] = &micro_glyph_f,
    [103] = &micro_glyph_g,
    [104] = &micro_glyph_h,
    [105] = &micro_glyph_i,
    [106] = &micro_glyph_j,
    [107] = &micro_glyph_k,
    [108] = &micro_glyph_l,
    [109] = &micro_glyph_m,
    [110] = &micro_glyph_n,
    [111] = &micro_glyph_o,
    [112] = &micro_glyph_p,
    [113] = &micro_glyph_q,
    [114] = &micro_glyph_r,
    [115] = &micro_glyph_s,
    [116] = &micro_glyph_t,
    [117] = &micro_glyph_u,
    [118] = &micro_glyph_v,
    [119] = &micro_glyph_w,
    [120] = &micro_glyph_x,
    [121] = &micro_glyph_y,
    [122] = &micro_glyph_z,
    [48] = &micro_glyph_0,
    [49] = &micro_glyph_1,
    [50] = &micro_glyph_2,
    [51] = &micro_glyph_3,
    [52] = &micro_glyph_4,
    [53] = &micro_glyph_5,
    [54] = &micro_glyph_6,
    [55] = &micro_glyph_7,
    [56] = &micro_glyph_8,
    [57] = &micro_glyph_9,
  }
};
/* clang-format on */
