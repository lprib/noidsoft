#include "usart.h"
#include "dio.h"

#include <base/util.h>

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define T usart_t

struct T
{
  // control and status
  register_t ucsrxa;
  register_t ucsrxb;
  register_t ucsrxc;

  // baud rate registers
  register_t ubrrxl;
  register_t ubrrxh;

  // data register
  register_t udrx;
};

#define NUM_USARTS 4
static const struct T usart_list[NUM_USARTS] = {
    {.ucsrxa = &UCSR0A,
     .ucsrxb = &UCSR0B,
     .ucsrxc = &UCSR0C,
     .ubrrxl = &UBRR0L,
     .ubrrxh = &UBRR0H,
     .udrx = &UDR0},
    {.ucsrxa = &UCSR1A,
     .ucsrxb = &UCSR1B,
     .ucsrxc = &UCSR1C,
     .ubrrxl = &UBRR1L,
     .ubrrxh = &UBRR1H,
     .udrx = &UDR1},
    {.ucsrxa = &UCSR2A,
     .ucsrxb = &UCSR2B,
     .ucsrxc = &UCSR2C,
     .ubrrxl = &UBRR2L,
     .ubrrxh = &UBRR2H,
     .udrx = &UDR2},
    {.ucsrxa = &UCSR3A,
     .ucsrxb = &UCSR3B,
     .ucsrxc = &UCSR3C,
     .ubrrxl = &UBRR3L,
     .ubrrxh = &UBRR3H,
     .udrx = &UDR3},
};

static inline bool usart_read_ready(T self)
{
  return *self->ucsrxa & util_bit(RXC0);
}
static inline bool usart_write_ready(T self)
{
  return *self->ucsrxa & util_bit(UDRE0);
}
static inline unsigned char usart_read(T self)
{
  return *self->udrx;
}

T usart_get_from_number(int which)
{
  return &usart_list[which];
}

void usart_init(T self, uint32_t f_cpu, uint32_t baudrate)
{
  // todo make a version of this with all parameters (frame size, parity, etc)

  *self->ucsrxa = 0x00;
  // enable receive and transmit
  *self->ucsrxb = util_bit(RXEN0) | util_bit(TXEN0);
  // set frame size to 8 bit
  *self->ucsrxc = util_bit(UCSZ00) | util_bit(UCSZ01);

  // set baudrate
  uint32_t ubrr = (f_cpu / (16 * baudrate)) - 1;
  *self->ubrrxh = ubrr >> 8;
  *self->ubrrxl = ubrr & 0xFF;
}

void usart_write_byte(T self, uint8_t data)
{
  // wait for transmit buffer to be empty
  while (!usart_write_ready(self))
  {
  }

  *self->ucsrxa |= util_bit(TXC0);

  *self->udrx = data;
}

unsigned char usart_read_byte(T self)
{
  while (!usart_read_ready(self))
    ;
  return usart_read(self);
}

void usart_write_bytes(T self, uint8_t* data, size_t length)
{
  for (int i = 0; i < length; i++)
  {
    usart_write_byte(self, data[i]);
  }
}

void usart_write_string(T self, char* string)
{
  while (*string != 0)
  {
    usart_write_byte(self, *(string++));
  }
}

size_t usart_read_string(T self, char* buffer, size_t buffer_size)
{
  return usart_read_bytes_until(self, buffer, buffer_size, 0);
}

size_t usart_read_line(T self, char* buffer, size_t buffer_size)
{
  // note the buffer size is one less when passed on to accommodate zero
  // terminator
  size_t num_bytes_read =
      usart_read_bytes_until(self, buffer, buffer_size - 1, '\n');
  // add zero terminator
  buffer[num_bytes_read] = 0;
  return num_bytes_read + 1;
}

size_t
usart_read_bytes_until(T self, char* buffer, size_t buffer_size, char endbyte)
{
  int i;
  for (i = 0; i < buffer_size; i++)
  {
    char c = usart_read_byte(self);
    buffer[i] = c;

    if (c == endbyte)
    {
      // successfully read full string
      break;
    }
  }

  // reached full buffer without finding endbyte
  return i + 1;
}

void usart_flush_input_buffer(T self)
{
  unsigned char volatile dummy __attribute__((unused));
  while (usart_read_ready(self))
  {
    // read values into dummy var to remove them from the buffer
    dummy = usart_read(self);
  }
}
