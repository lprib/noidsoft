#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "dio.h"
#include "st7920_display.h"

struct st7920_t disp =
    {.rs = DIO_PIN_E5, .rw = DIO_PIN_G5, .e = DIO_PIN_E3, DIO_BANK_F};

int main(void)
{
  dio_pin_t pin = DIO_PIN_B7;

  dio_set_direction(pin, true);

  st7920_init(&disp);
  st7920_test_mode(&disp);

  while (1)
  {
    dio_set(pin, true);
    _delay_ms(1000);
    dio_set(pin, false);
    _delay_ms(1000);
  }
}
