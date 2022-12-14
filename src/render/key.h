#ifndef _RENDER_KEY_H_
#define _RENDER_KEY_H_

/**
 * Keys which are produced by the MMI.
 */

#include <stdbool.h>

/** Before changing ordering, check if any functions in key.c rely on this
 * ordering. */
typedef enum
{
  KEY_INVALID,
  KEY_A,
  KEY_B,
  KEY_C,
  KEY_D,
  KEY_E,
  KEY_F,
  KEY_G,
  KEY_H,
  KEY_I,
  KEY_J,
  KEY_K,
  KEY_L,
  KEY_M,
  KEY_N,
  KEY_O,
  KEY_P,
  KEY_Q,
  KEY_R,
  KEY_S,
  KEY_T,
  KEY_U,
  KEY_V,
  KEY_W,
  KEY_X,
  KEY_Y,
  KEY_Z,
  KEY_SPACE,
  KEY_0,
  KEY_1,
  KEY_2,
  KEY_3,
  KEY_4,
  KEY_5,
  KEY_6,
  KEY_7,
  KEY_8,
  KEY_9,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_UP,
  KEY_DOWN
} mmi_key_t;

/* Returns ascii of key if printable, else 0 */
char key_to_char(mmi_key_t key);
mmi_key_t key_from_char(char c);
bool key_is_printable(mmi_key_t key);

#endif
