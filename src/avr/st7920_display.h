#ifndef _AVR_ST7920_DISPLAY_H_
#define _AVR_ST7920_DISPLAY_H_

#include "dio.h"

typedef struct
{
  dio_pin_t RS;
  dio_pin_t RW;
  dio_pin_t E;
  dio_bank_t data_bank;
} st7920_t;

#endif
