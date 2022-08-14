#include "bitmap.h"
#include "font.h"
/* clang-format off */
static bmp_elem_t helv8_bitmap_char0[] = {
  0xa800,
  0x0000,
  0x8800,
  0x0000,
  0x8800,
  0x0000,
  0xa800,
};
static font_glyph_t helv8_glyph_char0 = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 7,
    .width_elems = 1,
    .buffer = helv8_bitmap_char0
  }
};

static bmp_elem_t helv8_bitmap_space[] = {
  0x0000,
};
static font_glyph_t helv8_glyph_space = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 3,
  .dw_y = 0,
  .bmp = {
    .w = 1,
    .h = 1,
    .width_elems = 1,
    .buffer = helv8_bitmap_space
  }
};

static bmp_elem_t helv8_bitmap_A[] = {
  0x1000,
  0x1000,
  0x2800,
  0x2800,
  0x4400,
  0x7c00,
  0x8200,
  0x8200,
};
static font_glyph_t helv8_glyph_A = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 7,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_A
  }
};

static bmp_elem_t helv8_bitmap_B[] = {
  0xf000,
  0x8800,
  0x8800,
  0xf000,
  0x8800,
  0x8800,
  0x8800,
  0xf000,
};
static font_glyph_t helv8_glyph_B = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_B
  }
};

static bmp_elem_t helv8_bitmap_C[] = {
  0x7800,
  0x8400,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8400,
  0x7800,
};
static font_glyph_t helv8_glyph_C = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 6,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_C
  }
};

static bmp_elem_t helv8_bitmap_D[] = {
  0xf000,
  0x8800,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x8800,
  0xf000,
};
static font_glyph_t helv8_glyph_D = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 6,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_D
  }
};

static bmp_elem_t helv8_bitmap_E[] = {
  0xf800,
  0x8000,
  0x8000,
  0xf800,
  0x8000,
  0x8000,
  0x8000,
  0xf800,
};
static font_glyph_t helv8_glyph_E = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_E
  }
};

static bmp_elem_t helv8_bitmap_F[] = {
  0xf800,
  0x8000,
  0x8000,
  0xf000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
};
static font_glyph_t helv8_glyph_F = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_F
  }
};

static bmp_elem_t helv8_bitmap_G[] = {
  0x7800,
  0x8400,
  0x8000,
  0x8000,
  0x8c00,
  0x8400,
  0x8400,
  0x7c00,
};
static font_glyph_t helv8_glyph_G = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 6,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_G
  }
};

static bmp_elem_t helv8_bitmap_H[] = {
  0x8400,
  0x8400,
  0x8400,
  0xfc00,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
};
static font_glyph_t helv8_glyph_H = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 6,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_H
  }
};

static bmp_elem_t helv8_bitmap_I[] = {
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
};
static font_glyph_t helv8_glyph_I = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 3,
  .dw_y = 0,
  .bmp = {
    .w = 1,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_I
  }
};

static bmp_elem_t helv8_bitmap_J[] = {
  0x1000,
  0x1000,
  0x1000,
  0x1000,
  0x1000,
  0x1000,
  0x9000,
  0x6000,
};
static font_glyph_t helv8_glyph_J = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_J
  }
};

static bmp_elem_t helv8_bitmap_K[] = {
  0x8800,
  0x9000,
  0xa000,
  0xe000,
  0x9000,
  0x9000,
  0x8800,
  0x8800,
};
static font_glyph_t helv8_glyph_K = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_K
  }
};

static bmp_elem_t helv8_bitmap_L[] = {
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0xf000,
};
static font_glyph_t helv8_glyph_L = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_L
  }
};

static bmp_elem_t helv8_bitmap_M[] = {
  0x8200,
  0xc600,
  0xc600,
  0xaa00,
  0xaa00,
  0x9200,
  0x9200,
  0x9200,
};
static font_glyph_t helv8_glyph_M = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 9,
  .dw_y = 0,
  .bmp = {
    .w = 7,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_M
  }
};

static bmp_elem_t helv8_bitmap_N[] = {
  0xc400,
  0xc400,
  0xa400,
  0xa400,
  0x9400,
  0x9400,
  0x8c00,
  0x8c00,
};
static font_glyph_t helv8_glyph_N = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 6,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_N
  }
};

static bmp_elem_t helv8_bitmap_O[] = {
  0x7800,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x7800,
};
static font_glyph_t helv8_glyph_O = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 6,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_O
  }
};

static bmp_elem_t helv8_bitmap_P[] = {
  0xf000,
  0x8800,
  0x8800,
  0xf000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
};
static font_glyph_t helv8_glyph_P = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_P
  }
};

static bmp_elem_t helv8_bitmap_Q[] = {
  0x7800,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x9400,
  0x8c00,
  0x7c00,
  0x0200,
};
static font_glyph_t helv8_glyph_Q = {
  .bb_off_x = 1,
  .bb_off_y = -1,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 7,
    .h = 9,
    .width_elems = 1,
    .buffer = helv8_bitmap_Q
  }
};

static bmp_elem_t helv8_bitmap_R[] = {
  0xf000,
  0x8800,
  0x8800,
  0xf000,
  0x8800,
  0x8800,
  0x8800,
  0x8800,
};
static font_glyph_t helv8_glyph_R = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_R
  }
};

static bmp_elem_t helv8_bitmap_S[] = {
  0x7000,
  0x8800,
  0x8000,
  0x7000,
  0x0800,
  0x8800,
  0x8800,
  0x7000,
};
static font_glyph_t helv8_glyph_S = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_S
  }
};

static bmp_elem_t helv8_bitmap_T[] = {
  0xf800,
  0x2000,
  0x2000,
  0x2000,
  0x2000,
  0x2000,
  0x2000,
  0x2000,
};
static font_glyph_t helv8_glyph_T = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_T
  }
};

static bmp_elem_t helv8_bitmap_U[] = {
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x8400,
  0x7800,
};
static font_glyph_t helv8_glyph_U = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 6,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_U
  }
};

static bmp_elem_t helv8_bitmap_V[] = {
  0x8200,
  0x8200,
  0x4400,
  0x4400,
  0x4400,
  0x2800,
  0x2800,
  0x1000,
};
static font_glyph_t helv8_glyph_V = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 7,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_V
  }
};

static bmp_elem_t helv8_bitmap_W[] = {
  0x8880,
  0x8880,
  0x4900,
  0x4900,
  0x5500,
  0x2200,
  0x2200,
  0x2200,
};
static font_glyph_t helv8_glyph_W = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 9,
  .dw_y = 0,
  .bmp = {
    .w = 9,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_W
  }
};

static bmp_elem_t helv8_bitmap_X[] = {
  0x8800,
  0x8800,
  0x5000,
  0x2000,
  0x5000,
  0x5000,
  0x8800,
  0x8800,
};
static font_glyph_t helv8_glyph_X = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_X
  }
};

static bmp_elem_t helv8_bitmap_Y[] = {
  0x8200,
  0x4400,
  0x4400,
  0x2800,
  0x2800,
  0x1000,
  0x1000,
  0x1000,
};
static font_glyph_t helv8_glyph_Y = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 7,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_Y
  }
};

static bmp_elem_t helv8_bitmap_Z[] = {
  0xf800,
  0x0800,
  0x1000,
  0x2000,
  0x2000,
  0x4000,
  0x8000,
  0xf800,
};
static font_glyph_t helv8_glyph_Z = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_Z
  }
};

static bmp_elem_t helv8_bitmap_a[] = {
  0xe000,
  0x1000,
  0x7000,
  0x9000,
  0x9000,
  0x6800,
};
static font_glyph_t helv8_glyph_a = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_a
  }
};

static bmp_elem_t helv8_bitmap_b[] = {
  0x8000,
  0x8000,
  0xb000,
  0xc800,
  0x8800,
  0x8800,
  0xc800,
  0xb000,
};
static font_glyph_t helv8_glyph_b = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_b
  }
};

static bmp_elem_t helv8_bitmap_c[] = {
  0x6000,
  0x9000,
  0x8000,
  0x8000,
  0x9000,
  0x6000,
};
static font_glyph_t helv8_glyph_c = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_c
  }
};

static bmp_elem_t helv8_bitmap_d[] = {
  0x0800,
  0x0800,
  0x6800,
  0x9800,
  0x8800,
  0x8800,
  0x9800,
  0x6800,
};
static font_glyph_t helv8_glyph_d = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_d
  }
};

static bmp_elem_t helv8_bitmap_e[] = {
  0x6000,
  0x9000,
  0xf000,
  0x8000,
  0x9000,
  0x6000,
};
static font_glyph_t helv8_glyph_e = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_e
  }
};

static bmp_elem_t helv8_bitmap_f[] = {
  0x3000,
  0x4000,
  0xe000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
};
static font_glyph_t helv8_glyph_f = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_f
  }
};

static bmp_elem_t helv8_bitmap_g[] = {
  0x6800,
  0x9800,
  0x8800,
  0x8800,
  0x9800,
  0x6800,
  0x0800,
  0x7000,
};
static font_glyph_t helv8_glyph_g = {
  .bb_off_x = 0,
  .bb_off_y = -2,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_g
  }
};

static bmp_elem_t helv8_bitmap_h[] = {
  0x8000,
  0x8000,
  0xb000,
  0xc800,
  0x8800,
  0x8800,
  0x8800,
  0x8800,
};
static font_glyph_t helv8_glyph_h = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_h
  }
};

static bmp_elem_t helv8_bitmap_i[] = {
  0x8000,
  0x0000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
};
static font_glyph_t helv8_glyph_i = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 2,
  .dw_y = 0,
  .bmp = {
    .w = 1,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_i
  }
};

static bmp_elem_t helv8_bitmap_j[] = {
  0x4000,
  0x0000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
  0x8000,
};
static font_glyph_t helv8_glyph_j = {
  .bb_off_x = -1,
  .bb_off_y = -2,
  .dw_x = 2,
  .dw_y = 0,
  .bmp = {
    .w = 2,
    .h = 10,
    .width_elems = 1,
    .buffer = helv8_bitmap_j
  }
};

static bmp_elem_t helv8_bitmap_k[] = {
  0x8000,
  0x8000,
  0x9000,
  0xa000,
  0xc000,
  0xa000,
  0x9000,
  0x9000,
};
static font_glyph_t helv8_glyph_k = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_k
  }
};

static bmp_elem_t helv8_bitmap_l[] = {
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
};
static font_glyph_t helv8_glyph_l = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 2,
  .dw_y = 0,
  .bmp = {
    .w = 1,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_l
  }
};

static bmp_elem_t helv8_bitmap_m[] = {
  0xec00,
  0x9200,
  0x9200,
  0x9200,
  0x9200,
  0x9200,
};
static font_glyph_t helv8_glyph_m = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 7,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_m
  }
};

static bmp_elem_t helv8_bitmap_n[] = {
  0xb000,
  0xc800,
  0x8800,
  0x8800,
  0x8800,
  0x8800,
};
static font_glyph_t helv8_glyph_n = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_n
  }
};

static bmp_elem_t helv8_bitmap_o[] = {
  0x7000,
  0x8800,
  0x8800,
  0x8800,
  0x8800,
  0x7000,
};
static font_glyph_t helv8_glyph_o = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_o
  }
};

static bmp_elem_t helv8_bitmap_p[] = {
  0xb000,
  0xc800,
  0x8800,
  0x8800,
  0xc800,
  0xb000,
  0x8000,
  0x8000,
};
static font_glyph_t helv8_glyph_p = {
  .bb_off_x = 0,
  .bb_off_y = -2,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_p
  }
};

static bmp_elem_t helv8_bitmap_q[] = {
  0x6800,
  0x9800,
  0x8800,
  0x8800,
  0x9800,
  0x6800,
  0x0800,
  0x0800,
};
static font_glyph_t helv8_glyph_q = {
  .bb_off_x = 0,
  .bb_off_y = -2,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_q
  }
};

static bmp_elem_t helv8_bitmap_r[] = {
  0xa000,
  0xc000,
  0x8000,
  0x8000,
  0x8000,
  0x8000,
};
static font_glyph_t helv8_glyph_r = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 3,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_r
  }
};

static bmp_elem_t helv8_bitmap_s[] = {
  0x6000,
  0x9000,
  0x6000,
  0x1000,
  0x9000,
  0x6000,
};
static font_glyph_t helv8_glyph_s = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_s
  }
};

static bmp_elem_t helv8_bitmap_t[] = {
  0x4000,
  0x4000,
  0xe000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
  0x6000,
};
static font_glyph_t helv8_glyph_t = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .w = 3,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_t
  }
};

static bmp_elem_t helv8_bitmap_u[] = {
  0x9000,
  0x9000,
  0x9000,
  0x9000,
  0x9000,
  0x7000,
};
static font_glyph_t helv8_glyph_u = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_u
  }
};

static bmp_elem_t helv8_bitmap_v[] = {
  0x8800,
  0x8800,
  0x5000,
  0x5000,
  0x2000,
  0x2000,
};
static font_glyph_t helv8_glyph_v = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_v
  }
};

static bmp_elem_t helv8_bitmap_w[] = {
  0x9200,
  0x9200,
  0x5400,
  0x5400,
  0x2800,
  0x2800,
};
static font_glyph_t helv8_glyph_w = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .w = 7,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_w
  }
};

static bmp_elem_t helv8_bitmap_x[] = {
  0x8800,
  0x5000,
  0x2000,
  0x5000,
  0x8800,
  0x8800,
};
static font_glyph_t helv8_glyph_x = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_x
  }
};

static bmp_elem_t helv8_bitmap_y[] = {
  0x4800,
  0x4800,
  0x5000,
  0x5000,
  0x3000,
  0x2000,
  0x2000,
  0xc000,
};
static font_glyph_t helv8_glyph_y = {
  .bb_off_x = -1,
  .bb_off_y = -2,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_y
  }
};

static bmp_elem_t helv8_bitmap_z[] = {
  0xf000,
  0x1000,
  0x2000,
  0x4000,
  0x8000,
  0xf000,
};
static font_glyph_t helv8_glyph_z = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .w = 4,
    .h = 6,
    .width_elems = 1,
    .buffer = helv8_bitmap_z
  }
};

static bmp_elem_t helv8_bitmap_zero[] = {
  0x7000,
  0x8800,
  0x8800,
  0x8800,
  0x8800,
  0x8800,
  0x8800,
  0x7000,
};
static font_glyph_t helv8_glyph_zero = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_zero
  }
};

static bmp_elem_t helv8_bitmap_one[] = {
  0x4000,
  0xc000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
  0x4000,
};
static font_glyph_t helv8_glyph_one = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 2,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_one
  }
};

static bmp_elem_t helv8_bitmap_two[] = {
  0x7000,
  0x8800,
  0x0800,
  0x0800,
  0x3000,
  0x4000,
  0x8000,
  0xf800,
};
static font_glyph_t helv8_glyph_two = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_two
  }
};

static bmp_elem_t helv8_bitmap_three[] = {
  0x7000,
  0x8800,
  0x0800,
  0x3000,
  0x0800,
  0x0800,
  0x8800,
  0x7000,
};
static font_glyph_t helv8_glyph_three = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_three
  }
};

static bmp_elem_t helv8_bitmap_four[] = {
  0x1000,
  0x3000,
  0x5000,
  0x5000,
  0x9000,
  0xf800,
  0x1000,
  0x1000,
};
static font_glyph_t helv8_glyph_four = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_four
  }
};

static bmp_elem_t helv8_bitmap_five[] = {
  0x7800,
  0x4000,
  0x4000,
  0x7000,
  0x0800,
  0x0800,
  0x8800,
  0x7000,
};
static font_glyph_t helv8_glyph_five = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_five
  }
};

static bmp_elem_t helv8_bitmap_six[] = {
  0x7000,
  0x8800,
  0x8000,
  0xf000,
  0x8800,
  0x8800,
  0x8800,
  0x7000,
};
static font_glyph_t helv8_glyph_six = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_six
  }
};

static bmp_elem_t helv8_bitmap_seven[] = {
  0xf800,
  0x0800,
  0x1000,
  0x2000,
  0x2000,
  0x4000,
  0x4000,
  0x4000,
};
static font_glyph_t helv8_glyph_seven = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_seven
  }
};

static bmp_elem_t helv8_bitmap_eight[] = {
  0x7000,
  0x8800,
  0x8800,
  0x7000,
  0x8800,
  0x8800,
  0x8800,
  0x7000,
};
static font_glyph_t helv8_glyph_eight = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_eight
  }
};

static bmp_elem_t helv8_bitmap_nine[] = {
  0x7000,
  0x8800,
  0x8800,
  0x8800,
  0x7800,
  0x0800,
  0x8800,
  0x7000,
};
static font_glyph_t helv8_glyph_nine = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .w = 5,
    .h = 8,
    .width_elems = 1,
    .buffer = helv8_bitmap_nine
  }
};


font_t helv8 = {
  .ascent = 10,
  .descent = 2,
  .glyphs = {
    [0] = &helv8_glyph_char0,
    [32] = &helv8_glyph_space,
    [65] = &helv8_glyph_A,
    [66] = &helv8_glyph_B,
    [67] = &helv8_glyph_C,
    [68] = &helv8_glyph_D,
    [69] = &helv8_glyph_E,
    [70] = &helv8_glyph_F,
    [71] = &helv8_glyph_G,
    [72] = &helv8_glyph_H,
    [73] = &helv8_glyph_I,
    [74] = &helv8_glyph_J,
    [75] = &helv8_glyph_K,
    [76] = &helv8_glyph_L,
    [77] = &helv8_glyph_M,
    [78] = &helv8_glyph_N,
    [79] = &helv8_glyph_O,
    [80] = &helv8_glyph_P,
    [81] = &helv8_glyph_Q,
    [82] = &helv8_glyph_R,
    [83] = &helv8_glyph_S,
    [84] = &helv8_glyph_T,
    [85] = &helv8_glyph_U,
    [86] = &helv8_glyph_V,
    [87] = &helv8_glyph_W,
    [88] = &helv8_glyph_X,
    [89] = &helv8_glyph_Y,
    [90] = &helv8_glyph_Z,
    [97] = &helv8_glyph_a,
    [98] = &helv8_glyph_b,
    [99] = &helv8_glyph_c,
    [100] = &helv8_glyph_d,
    [101] = &helv8_glyph_e,
    [102] = &helv8_glyph_f,
    [103] = &helv8_glyph_g,
    [104] = &helv8_glyph_h,
    [105] = &helv8_glyph_i,
    [106] = &helv8_glyph_j,
    [107] = &helv8_glyph_k,
    [108] = &helv8_glyph_l,
    [109] = &helv8_glyph_m,
    [110] = &helv8_glyph_n,
    [111] = &helv8_glyph_o,
    [112] = &helv8_glyph_p,
    [113] = &helv8_glyph_q,
    [114] = &helv8_glyph_r,
    [115] = &helv8_glyph_s,
    [116] = &helv8_glyph_t,
    [117] = &helv8_glyph_u,
    [118] = &helv8_glyph_v,
    [119] = &helv8_glyph_w,
    [120] = &helv8_glyph_x,
    [121] = &helv8_glyph_y,
    [122] = &helv8_glyph_z,
    [48] = &helv8_glyph_zero,
    [49] = &helv8_glyph_one,
    [50] = &helv8_glyph_two,
    [51] = &helv8_glyph_three,
    [52] = &helv8_glyph_four,
    [53] = &helv8_glyph_five,
    [54] = &helv8_glyph_six,
    [55] = &helv8_glyph_seven,
    [56] = &helv8_glyph_eight,
    [57] = &helv8_glyph_nine,
  }
};
/* clang-format on */
