#include "usart.h"

#include <base/util.h>

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

void usart_init(uint32_t baudrate)
{
  // todo make a version of this with all parameters (frame size, parity, etc)

  UCSR0A = 0x00;
  // enable receive and transmit
  UCSR0B = util_bit(RXEN0) | util_bit(TXEN0);
  // set frame size to 8 bit
  UCSR0C = util_bit(UCSZ00) | util_bit(UCSZ01);

  // set baudrate
  uint32_t ubrr = (F_CPU / (16 * baudrate)) - 1;
  UBRR0H = ubrr >> 8;
  UBRR0L = ubrr & 0xFF;
}

void usart_wait_write(unsigned char data)
{
  // wait for transmit buffer to be empty
  while (!usart_write_ready())
  {
  }

  UCSR0A |= util_bit(TXC0);

  UDR0 = data;
}

bool usart_read_ready()
{
  return UCSR0A & util_bit(RXC0);
}

bool usart_write_ready()
{
  return UCSR0A & util_bit(UDRE0);
}

unsigned char usart_read()
{
  return UDR0;
}

unsigned char usart_wait_read()
{
  while (!usart_read_ready())
    ;
  return usart_read();
}

void usart_write_bytes(unsigned char* data, size_t length)
{
  for (int i = 0; i < length; i++)
  {
    usart_wait_write(data[i]);
  }
}

void usart_write_string(char* string)
{
  while (*string != 0)
  {
    usart_wait_write(*(string++));
  }
}

void usart_write_line(char* string)
{
  usart_write_string(string);
  usart_wait_write('\n');
}

void usart_write_int_line(int data)
{
  char string[15];
  sprintf(string, "%d", data);
  usart_write_line(string);
}

void usart_write_int_hex_line(int data)
{
  char string[6];
  sprintf(string, "%X", data);
  usart_write_line(string);
}

size_t usart_read_string(char* buffer, size_t buffer_size)
{
  return usart_read_bytes_until(buffer, buffer_size, 0);
}

size_t usart_read_line(char* buffer, size_t buffer_size)
{
  // note the buffer size is one less when passed on to accommodate zero
  // terminator
  size_t num_bytes_read = usart_read_bytes_until(buffer, buffer_size - 1, '\n');
  // add zero terminator
  buffer[num_bytes_read] = 0;
  return num_bytes_read + 1;
}

size_t usart_read_bytes_until(char* buffer, size_t buffer_size, char endbyte)
{
  int i;
  for (i = 0; i < buffer_size; i++)
  {
    char c = usart_wait_read();
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

void usart_flush_buffer()
{
  unsigned char volatile dummy __attribute__((unused));
  while (UCSR0A & util_bit(RXC0))
  {
    // read values into dummy var to remove them from the buffer
    dummy = UDR0;
  }
}
