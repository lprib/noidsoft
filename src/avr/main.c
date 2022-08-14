#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "dio.h"

int main(void)
{
  dio_pin_t pin = DIO_PIN_B7;

  dio_set_direction(pin, true);

  while (1)
  {
    dio_set(pin, true);
    _delay_ms(100);
    dio_set(pin, false);
    _delay_ms(100);
  }
}
