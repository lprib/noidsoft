#ifndef _AVR_ST7920_DISPLAY_H_
#define _AVR_ST7920_DISPLAY_H_

/**
 * ST7920 display driver in graphics mode.
 */

#include "dio.h"

#define T st7920_t

typedef struct T* T;

struct T
{
  dio_pin_t rs;
  dio_pin_t rw;
  dio_pin_t e;
  dio_bank_t data_bank;
};

#define ST7920_DISPLAY_WIDTH_UINT16 8
#define ST7920_DISPLAY_WIDTH 128
#define ST7920_DISPLAY_HEIGHT 64

/** Initialize display and set to graphics mode */
void st7920_init(T self);

/**
 * Send buffer data to screen.
 *
 * Buffer must be ST7920_DISPLAY_WIDTH_UINT16 * ST7920_DISPLAY_HEIGHT in length
 */
void st7920_refresh(T self, uint16_t* buffer);

#undef T
#endif
