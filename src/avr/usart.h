#ifndef _AVR_USART_H_
#define _AVR_USART_H_

/**
 * Abstracted driver for USARTs. Get a usart object with usart_get_from_number,
 * eg. for USART1:
 *
 * usart_t my_usart = usart_get_from_number(1);
 * usart_write_string(my_usart, "hello");
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define T usart_t

typedef struct T const* T;

/** Get a usart_t reference from number, eg. USART0 or USART1 */
T usart_get_from_number(int which);

void usart_init(T self, uint32_t f_cpu, uint32_t baudrate);

/** Waits until ready to write, and then writes data */
void usart_write_byte(T self, uint8_t data);

/** wait until data is available and read it */
uint8_t usart_read_byte(T self);

void usart_write_bytes(T self, uint8_t* data, size_t length);

/** write string not including zero terminator */
void usart_write_string(T self, char* string);

/**
 * Reads usart until zero terminator is encountered (terminator is copied to
 * buffer as well)
 *
 * NOTE: If the buffer fills before a zero is found, the string will not be
 * terminated.
 */
size_t usart_read_string(T self, char* buffer, size_t buffer_size);

/**
 * Reads until a newline is found, appends a zero terminator after the newline.
 * If a newline is not found, buffer_size - 1 characters will be read, and a
 * zero terminator will be added.
 */
size_t usart_read_line(T self, char* buffer, size_t buffer_size);

/** read until either endbyte is found or buffer fills */
size_t
usart_read_bytes_until(T self, char* buffer, size_t buffer_size, char endbyte);

void usart_flush_input_buffer(T self);

#undef T

#endif
