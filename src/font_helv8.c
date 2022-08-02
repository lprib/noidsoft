#include "bitmap.h"
#include "font.h"
/* clang-format off */
static bmp_elem_t helv08_bitmap_char0[] = {
  0x1500,
  0x0000,
  0x1100,
  0x0000,
  0x1100,
  0x0000,
  0x1500,
};
static font_glyph_t helv08_glyph_char0 = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 7,
    .width_elems = 1,
    .buffer = helv08_bitmap_char0
  }
};

static bmp_elem_t helv08_bitmap_space[] = {
  0x0000,
};
static font_glyph_t helv08_glyph_space = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 3,
  .dw_y = 0,
  .bmp = {
    .width = 1,
    .height = 1,
    .width_elems = 1,
    .buffer = helv08_bitmap_space
  }
};

static bmp_elem_t helv08_bitmap_A[] = {
  0x0800,
  0x0800,
  0x1400,
  0x1400,
  0x2200,
  0x3e00,
  0x4100,
  0x4100,
};
static font_glyph_t helv08_glyph_A = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 7,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_A
  }
};

static bmp_elem_t helv08_bitmap_B[] = {
  0x0f00,
  0x1100,
  0x1100,
  0x0f00,
  0x1100,
  0x1100,
  0x1100,
  0x0f00,
};
static font_glyph_t helv08_glyph_B = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_B
  }
};

static bmp_elem_t helv08_bitmap_C[] = {
  0x1e00,
  0x2100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x2100,
  0x1e00,
};
static font_glyph_t helv08_glyph_C = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 6,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_C
  }
};

static bmp_elem_t helv08_bitmap_D[] = {
  0x0f00,
  0x1100,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x1100,
  0x0f00,
};
static font_glyph_t helv08_glyph_D = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 6,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_D
  }
};

static bmp_elem_t helv08_bitmap_E[] = {
  0x1f00,
  0x0100,
  0x0100,
  0x1f00,
  0x0100,
  0x0100,
  0x0100,
  0x1f00,
};
static font_glyph_t helv08_glyph_E = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_E
  }
};

static bmp_elem_t helv08_bitmap_F[] = {
  0x1f00,
  0x0100,
  0x0100,
  0x0f00,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
};
static font_glyph_t helv08_glyph_F = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_F
  }
};

static bmp_elem_t helv08_bitmap_G[] = {
  0x1e00,
  0x2100,
  0x0100,
  0x0100,
  0x3100,
  0x2100,
  0x2100,
  0x3e00,
};
static font_glyph_t helv08_glyph_G = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 6,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_G
  }
};

static bmp_elem_t helv08_bitmap_H[] = {
  0x2100,
  0x2100,
  0x2100,
  0x3f00,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
};
static font_glyph_t helv08_glyph_H = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 6,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_H
  }
};

static bmp_elem_t helv08_bitmap_I[] = {
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
};
static font_glyph_t helv08_glyph_I = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 3,
  .dw_y = 0,
  .bmp = {
    .width = 1,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_I
  }
};

static bmp_elem_t helv08_bitmap_J[] = {
  0x0800,
  0x0800,
  0x0800,
  0x0800,
  0x0800,
  0x0800,
  0x0900,
  0x0600,
};
static font_glyph_t helv08_glyph_J = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_J
  }
};

static bmp_elem_t helv08_bitmap_K[] = {
  0x1100,
  0x0900,
  0x0500,
  0x0700,
  0x0900,
  0x0900,
  0x1100,
  0x1100,
};
static font_glyph_t helv08_glyph_K = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_K
  }
};

static bmp_elem_t helv08_bitmap_L[] = {
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0f00,
};
static font_glyph_t helv08_glyph_L = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_L
  }
};

static bmp_elem_t helv08_bitmap_M[] = {
  0x4100,
  0x6300,
  0x6300,
  0x5500,
  0x5500,
  0x4900,
  0x4900,
  0x4900,
};
static font_glyph_t helv08_glyph_M = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 9,
  .dw_y = 0,
  .bmp = {
    .width = 7,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_M
  }
};

static bmp_elem_t helv08_bitmap_N[] = {
  0x2300,
  0x2300,
  0x2500,
  0x2500,
  0x2900,
  0x2900,
  0x3100,
  0x3100,
};
static font_glyph_t helv08_glyph_N = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 6,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_N
  }
};

static bmp_elem_t helv08_bitmap_O[] = {
  0x1e00,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x1e00,
};
static font_glyph_t helv08_glyph_O = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 6,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_O
  }
};

static bmp_elem_t helv08_bitmap_P[] = {
  0x0f00,
  0x1100,
  0x1100,
  0x0f00,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
};
static font_glyph_t helv08_glyph_P = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_P
  }
};

static bmp_elem_t helv08_bitmap_Q[] = {
  0x1e00,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x2900,
  0x3100,
  0x3e00,
  0x4000,
};
static font_glyph_t helv08_glyph_Q = {
  .bb_off_x = 1,
  .bb_off_y = -1,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 7,
    .height = 9,
    .width_elems = 1,
    .buffer = helv08_bitmap_Q
  }
};

static bmp_elem_t helv08_bitmap_R[] = {
  0x0f00,
  0x1100,
  0x1100,
  0x0f00,
  0x1100,
  0x1100,
  0x1100,
  0x1100,
};
static font_glyph_t helv08_glyph_R = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_R
  }
};

static bmp_elem_t helv08_bitmap_S[] = {
  0x0e00,
  0x1100,
  0x0100,
  0x0e00,
  0x1000,
  0x1100,
  0x1100,
  0x0e00,
};
static font_glyph_t helv08_glyph_S = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_S
  }
};

static bmp_elem_t helv08_bitmap_T[] = {
  0x1f00,
  0x0400,
  0x0400,
  0x0400,
  0x0400,
  0x0400,
  0x0400,
  0x0400,
};
static font_glyph_t helv08_glyph_T = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_T
  }
};

static bmp_elem_t helv08_bitmap_U[] = {
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x2100,
  0x1e00,
};
static font_glyph_t helv08_glyph_U = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 6,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_U
  }
};

static bmp_elem_t helv08_bitmap_V[] = {
  0x4100,
  0x4100,
  0x2200,
  0x2200,
  0x2200,
  0x1400,
  0x1400,
  0x0800,
};
static font_glyph_t helv08_glyph_V = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 7,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_V
  }
};

static bmp_elem_t helv08_bitmap_W[] = {
  0x0111,
  0x0111,
  0x0092,
  0x0092,
  0x00aa,
  0x0044,
  0x0044,
  0x0044,
};
static font_glyph_t helv08_glyph_W = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 9,
  .dw_y = 0,
  .bmp = {
    .width = 9,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_W
  }
};

static bmp_elem_t helv08_bitmap_X[] = {
  0x1100,
  0x1100,
  0x0a00,
  0x0400,
  0x0a00,
  0x0a00,
  0x1100,
  0x1100,
};
static font_glyph_t helv08_glyph_X = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_X
  }
};

static bmp_elem_t helv08_bitmap_Y[] = {
  0x4100,
  0x2200,
  0x2200,
  0x1400,
  0x1400,
  0x0800,
  0x0800,
  0x0800,
};
static font_glyph_t helv08_glyph_Y = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 7,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_Y
  }
};

static bmp_elem_t helv08_bitmap_Z[] = {
  0x1f00,
  0x1000,
  0x0800,
  0x0400,
  0x0400,
  0x0200,
  0x0100,
  0x1f00,
};
static font_glyph_t helv08_glyph_Z = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 7,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_Z
  }
};

static bmp_elem_t helv08_bitmap_a[] = {
  0x0700,
  0x0800,
  0x0e00,
  0x0900,
  0x0900,
  0x1600,
};
static font_glyph_t helv08_glyph_a = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_a
  }
};

static bmp_elem_t helv08_bitmap_b[] = {
  0x0100,
  0x0100,
  0x0d00,
  0x1300,
  0x1100,
  0x1100,
  0x1300,
  0x0d00,
};
static font_glyph_t helv08_glyph_b = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_b
  }
};

static bmp_elem_t helv08_bitmap_c[] = {
  0x0600,
  0x0900,
  0x0100,
  0x0100,
  0x0900,
  0x0600,
};
static font_glyph_t helv08_glyph_c = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_c
  }
};

static bmp_elem_t helv08_bitmap_d[] = {
  0x1000,
  0x1000,
  0x1600,
  0x1900,
  0x1100,
  0x1100,
  0x1900,
  0x1600,
};
static font_glyph_t helv08_glyph_d = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_d
  }
};

static bmp_elem_t helv08_bitmap_e[] = {
  0x0600,
  0x0900,
  0x0f00,
  0x0100,
  0x0900,
  0x0600,
};
static font_glyph_t helv08_glyph_e = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_e
  }
};

static bmp_elem_t helv08_bitmap_f[] = {
  0x0c00,
  0x0200,
  0x0700,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
};
static font_glyph_t helv08_glyph_f = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_f
  }
};

static bmp_elem_t helv08_bitmap_g[] = {
  0x1600,
  0x1900,
  0x1100,
  0x1100,
  0x1900,
  0x1600,
  0x1000,
  0x0e00,
};
static font_glyph_t helv08_glyph_g = {
  .bb_off_x = 0,
  .bb_off_y = -2,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_g
  }
};

static bmp_elem_t helv08_bitmap_h[] = {
  0x0100,
  0x0100,
  0x0d00,
  0x1300,
  0x1100,
  0x1100,
  0x1100,
  0x1100,
};
static font_glyph_t helv08_glyph_h = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_h
  }
};

static bmp_elem_t helv08_bitmap_i[] = {
  0x0100,
  0x0000,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
};
static font_glyph_t helv08_glyph_i = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 2,
  .dw_y = 0,
  .bmp = {
    .width = 1,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_i
  }
};

static bmp_elem_t helv08_bitmap_j[] = {
  0x0200,
  0x0000,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
  0x0100,
};
static font_glyph_t helv08_glyph_j = {
  .bb_off_x = -1,
  .bb_off_y = -2,
  .dw_x = 2,
  .dw_y = 0,
  .bmp = {
    .width = 2,
    .height = 10,
    .width_elems = 1,
    .buffer = helv08_bitmap_j
  }
};

static bmp_elem_t helv08_bitmap_k[] = {
  0x0100,
  0x0100,
  0x0900,
  0x0500,
  0x0300,
  0x0500,
  0x0900,
  0x0900,
};
static font_glyph_t helv08_glyph_k = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_k
  }
};

static bmp_elem_t helv08_bitmap_l[] = {
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
};
static font_glyph_t helv08_glyph_l = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 2,
  .dw_y = 0,
  .bmp = {
    .width = 1,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_l
  }
};

static bmp_elem_t helv08_bitmap_m[] = {
  0x3700,
  0x4900,
  0x4900,
  0x4900,
  0x4900,
  0x4900,
};
static font_glyph_t helv08_glyph_m = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 7,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_m
  }
};

static bmp_elem_t helv08_bitmap_n[] = {
  0x0d00,
  0x1300,
  0x1100,
  0x1100,
  0x1100,
  0x1100,
};
static font_glyph_t helv08_glyph_n = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_n
  }
};

static bmp_elem_t helv08_bitmap_o[] = {
  0x0e00,
  0x1100,
  0x1100,
  0x1100,
  0x1100,
  0x0e00,
};
static font_glyph_t helv08_glyph_o = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_o
  }
};

static bmp_elem_t helv08_bitmap_p[] = {
  0x0d00,
  0x1300,
  0x1100,
  0x1100,
  0x1300,
  0x0d00,
  0x0100,
  0x0100,
};
static font_glyph_t helv08_glyph_p = {
  .bb_off_x = 0,
  .bb_off_y = -2,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_p
  }
};

static bmp_elem_t helv08_bitmap_q[] = {
  0x1600,
  0x1900,
  0x1100,
  0x1100,
  0x1900,
  0x1600,
  0x1000,
  0x1000,
};
static font_glyph_t helv08_glyph_q = {
  .bb_off_x = 0,
  .bb_off_y = -2,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_q
  }
};

static bmp_elem_t helv08_bitmap_r[] = {
  0x0500,
  0x0300,
  0x0100,
  0x0100,
  0x0100,
  0x0100,
};
static font_glyph_t helv08_glyph_r = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .width = 3,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_r
  }
};

static bmp_elem_t helv08_bitmap_s[] = {
  0x0600,
  0x0900,
  0x0600,
  0x0800,
  0x0900,
  0x0600,
};
static font_glyph_t helv08_glyph_s = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_s
  }
};

static bmp_elem_t helv08_bitmap_t[] = {
  0x0200,
  0x0200,
  0x0700,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
  0x0600,
};
static font_glyph_t helv08_glyph_t = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 4,
  .dw_y = 0,
  .bmp = {
    .width = 3,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_t
  }
};

static bmp_elem_t helv08_bitmap_u[] = {
  0x0900,
  0x0900,
  0x0900,
  0x0900,
  0x0900,
  0x0e00,
};
static font_glyph_t helv08_glyph_u = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_u
  }
};

static bmp_elem_t helv08_bitmap_v[] = {
  0x1100,
  0x1100,
  0x0a00,
  0x0a00,
  0x0400,
  0x0400,
};
static font_glyph_t helv08_glyph_v = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_v
  }
};

static bmp_elem_t helv08_bitmap_w[] = {
  0x4900,
  0x4900,
  0x2a00,
  0x2a00,
  0x1400,
  0x1400,
};
static font_glyph_t helv08_glyph_w = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 8,
  .dw_y = 0,
  .bmp = {
    .width = 7,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_w
  }
};

static bmp_elem_t helv08_bitmap_x[] = {
  0x1100,
  0x0a00,
  0x0400,
  0x0a00,
  0x1100,
  0x1100,
};
static font_glyph_t helv08_glyph_x = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_x
  }
};

static bmp_elem_t helv08_bitmap_y[] = {
  0x1200,
  0x1200,
  0x0a00,
  0x0a00,
  0x0c00,
  0x0400,
  0x0400,
  0x0300,
};
static font_glyph_t helv08_glyph_y = {
  .bb_off_x = -1,
  .bb_off_y = -2,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_y
  }
};

static bmp_elem_t helv08_bitmap_z[] = {
  0x0f00,
  0x0800,
  0x0400,
  0x0200,
  0x0100,
  0x0f00,
};
static font_glyph_t helv08_glyph_z = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 5,
  .dw_y = 0,
  .bmp = {
    .width = 4,
    .height = 6,
    .width_elems = 1,
    .buffer = helv08_bitmap_z
  }
};

static bmp_elem_t helv08_bitmap_zero[] = {
  0x0e00,
  0x1100,
  0x1100,
  0x1100,
  0x1100,
  0x1100,
  0x1100,
  0x0e00,
};
static font_glyph_t helv08_glyph_zero = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_zero
  }
};

static bmp_elem_t helv08_bitmap_one[] = {
  0x0200,
  0x0300,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
  0x0200,
};
static font_glyph_t helv08_glyph_one = {
  .bb_off_x = 1,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 2,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_one
  }
};

static bmp_elem_t helv08_bitmap_two[] = {
  0x0e00,
  0x1100,
  0x1000,
  0x1000,
  0x0c00,
  0x0200,
  0x0100,
  0x1f00,
};
static font_glyph_t helv08_glyph_two = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_two
  }
};

static bmp_elem_t helv08_bitmap_three[] = {
  0x0e00,
  0x1100,
  0x1000,
  0x0c00,
  0x1000,
  0x1000,
  0x1100,
  0x0e00,
};
static font_glyph_t helv08_glyph_three = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_three
  }
};

static bmp_elem_t helv08_bitmap_four[] = {
  0x0800,
  0x0c00,
  0x0a00,
  0x0a00,
  0x0900,
  0x1f00,
  0x0800,
  0x0800,
};
static font_glyph_t helv08_glyph_four = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_four
  }
};

static bmp_elem_t helv08_bitmap_five[] = {
  0x1e00,
  0x0200,
  0x0200,
  0x0e00,
  0x1000,
  0x1000,
  0x1100,
  0x0e00,
};
static font_glyph_t helv08_glyph_five = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_five
  }
};

static bmp_elem_t helv08_bitmap_six[] = {
  0x0e00,
  0x1100,
  0x0100,
  0x0f00,
  0x1100,
  0x1100,
  0x1100,
  0x0e00,
};
static font_glyph_t helv08_glyph_six = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_six
  }
};

static bmp_elem_t helv08_bitmap_seven[] = {
  0x1f00,
  0x1000,
  0x0800,
  0x0400,
  0x0400,
  0x0200,
  0x0200,
  0x0200,
};
static font_glyph_t helv08_glyph_seven = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_seven
  }
};

static bmp_elem_t helv08_bitmap_eight[] = {
  0x0e00,
  0x1100,
  0x1100,
  0x0e00,
  0x1100,
  0x1100,
  0x1100,
  0x0e00,
};
static font_glyph_t helv08_glyph_eight = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_eight
  }
};

static bmp_elem_t helv08_bitmap_nine[] = {
  0x0e00,
  0x1100,
  0x1100,
  0x1100,
  0x1e00,
  0x1000,
  0x1100,
  0x0e00,
};
static font_glyph_t helv08_glyph_nine = {
  .bb_off_x = 0,
  .bb_off_y = 0,
  .dw_x = 6,
  .dw_y = 0,
  .bmp = {
    .width = 5,
    .height = 8,
    .width_elems = 1,
    .buffer = helv08_bitmap_nine
  }
};


font_t helv08 = {
  .ascent = 10,
  .descent = 2,
  .glyphs = {
    [0] = &helv08_glyph_char0,
    [32] = &helv08_glyph_space,
    [65] = &helv08_glyph_A,
    [66] = &helv08_glyph_B,
    [67] = &helv08_glyph_C,
    [68] = &helv08_glyph_D,
    [69] = &helv08_glyph_E,
    [70] = &helv08_glyph_F,
    [71] = &helv08_glyph_G,
    [72] = &helv08_glyph_H,
    [73] = &helv08_glyph_I,
    [74] = &helv08_glyph_J,
    [75] = &helv08_glyph_K,
    [76] = &helv08_glyph_L,
    [77] = &helv08_glyph_M,
    [78] = &helv08_glyph_N,
    [79] = &helv08_glyph_O,
    [80] = &helv08_glyph_P,
    [81] = &helv08_glyph_Q,
    [82] = &helv08_glyph_R,
    [83] = &helv08_glyph_S,
    [84] = &helv08_glyph_T,
    [85] = &helv08_glyph_U,
    [86] = &helv08_glyph_V,
    [87] = &helv08_glyph_W,
    [88] = &helv08_glyph_X,
    [89] = &helv08_glyph_Y,
    [90] = &helv08_glyph_Z,
    [97] = &helv08_glyph_a,
    [98] = &helv08_glyph_b,
    [99] = &helv08_glyph_c,
    [100] = &helv08_glyph_d,
    [101] = &helv08_glyph_e,
    [102] = &helv08_glyph_f,
    [103] = &helv08_glyph_g,
    [104] = &helv08_glyph_h,
    [105] = &helv08_glyph_i,
    [106] = &helv08_glyph_j,
    [107] = &helv08_glyph_k,
    [108] = &helv08_glyph_l,
    [109] = &helv08_glyph_m,
    [110] = &helv08_glyph_n,
    [111] = &helv08_glyph_o,
    [112] = &helv08_glyph_p,
    [113] = &helv08_glyph_q,
    [114] = &helv08_glyph_r,
    [115] = &helv08_glyph_s,
    [116] = &helv08_glyph_t,
    [117] = &helv08_glyph_u,
    [118] = &helv08_glyph_v,
    [119] = &helv08_glyph_w,
    [120] = &helv08_glyph_x,
    [121] = &helv08_glyph_y,
    [122] = &helv08_glyph_z,
    [48] = &helv08_glyph_zero,
    [49] = &helv08_glyph_one,
    [50] = &helv08_glyph_two,
    [51] = &helv08_glyph_three,
    [52] = &helv08_glyph_four,
    [53] = &helv08_glyph_five,
    [54] = &helv08_glyph_six,
    [55] = &helv08_glyph_seven,
    [56] = &helv08_glyph_eight,
    [57] = &helv08_glyph_nine,
  }
};
/* clang-format on */
