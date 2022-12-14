// provided implementations
#include "avr_mmi.h"
#include <platform_interface/mmi.h>

// dependencies
#include "dio.h"
#include "st7920_display.h"
#include "usart.h"

#include <render/bitmap.h>

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#define PRINT_BUF_SIZ 50

struct st7920_t display =
    {.rs = DIO_PIN_E5, .rw = DIO_PIN_G5, .e = DIO_PIN_E3, DIO_BANK_F};

// ASSUMPTION: bmp_elem_t is always uint16_t
bmp_elem_t raw_buffer[ST7920_DISPLAY_WIDTH_UINT16 * ST7920_DISPLAY_HEIGHT] = {
    0};

bmp_t back_buffer_bmp = {
    .w = ST7920_DISPLAY_HEIGHT,
    .h = ST7920_DISPLAY_HEIGHT,
    .width_elems = ST7920_DISPLAY_WIDTH_UINT16,
    .buffer = raw_buffer};

mmi_event_handler_t event_handler;

usart_t serial_comms_usart;

void avrmmi_init(void)
{
  st7920_init(&display);
  serial_comms_usart = usart_get_from_number(0);
  usart_init(serial_comms_usart, 16000000UL, 9600);
}

void avrmmi_main_loop(void)
{
  if (event_handler)
  {
    mmi_event_t ev = {.type = RENDER_EVENT_DRIVER_INITIALIZED};
    event_handler(ev);
  }

  while (1)
  {
    unsigned char input = usart_read_byte(serial_comms_usart);
    if (event_handler)
    {
      mmi_event_t ev = {
          .type = RENDER_EVENT_KEYDOWN,
          .key_event = {.key = key_from_char(input)}};
      event_handler(ev);
    }
  }
}

// mmi/mmi.h implementation:

bmp_t* mmi_get_render_target(void)
{
  return &back_buffer_bmp;
}

void mmi_display_refresh(void)
{
  st7920_refresh(&display, back_buffer_bmp.buffer);
}

void mmi_register_event_handler(mmi_event_handler_t handler)
{
  event_handler = handler;
}

void mmi_printf(char* format, ...)
{
  static char print_buf[PRINT_BUF_SIZ];
  va_list args;
  va_start(args, format);
  vsnprintf(print_buf, PRINT_BUF_SIZ, format, args);
  va_end(args);

  usart_write_string(serial_comms_usart, print_buf);
}
