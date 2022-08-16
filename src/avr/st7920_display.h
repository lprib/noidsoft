#ifndef _AVR_ST7920_DISPLAY_H_
#define _AVR_ST7920_DISPLAY_H_

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

void st7920_init(T self);
void st7920_test_mode(T self);

/**
 * Buffer must be ST7920_DISPLAY_WIDTH_UINT16 * ST7920_DISPLAY_HEIGHT in length
 */
void st7920_refresh(T self, uint16_t* buffer);

#undef T
#endif
