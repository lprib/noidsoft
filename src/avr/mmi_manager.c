/**
 * Implements mmi/mmi.h for the ST7920 display and serial input
 */

#include "mmi_manager.h"
#include "dio.h"
#include "st7920_display.h"
#include "usart.h"

#include <mmi/bitmap.h>
#include <mmi/mmi.h>

#include <stdbool.h>

struct st7920_t display =
    {.rs = DIO_PIN_E5, .rw = DIO_PIN_G5, .e = DIO_PIN_E3, DIO_BANK_F};

// ASSUMPTION: bmp_elem_t is always uint16_t
bmp_elem_t buffer[ST7920_DISPLAY_WIDTH_UINT16 * ST7920_DISPLAY_HEIGHT] = {0};

bmp_t back_buffer = {
    .w = ST7920_DISPLAY_HEIGHT,
    .h = ST7920_DISPLAY_HEIGHT,
    .width_elems = ST7920_DISPLAY_WIDTH_UINT16,
    .buffer = buffer};

mmi_event_handler_t event_handler;

void mmimanager_init(void)
{
  st7920_init(&display);
  usart_init(9600);
}

void mmimanager_run_loop(void)
{
  if (event_handler)
  {
    mmi_event_t ev = {.type = RENDER_EVENT_DRIVER_INITIALIZED};
    event_handler(ev);
  }

  while (1)
  {
    unsigned char input = usart_wait_read();
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
  return &back_buffer;
}

void mmi_display_refresh(void)
{
  st7920_refresh(&display, back_buffer.buffer);
}

void mmi_register_event_handler(mmi_event_handler_t handler)
{
  event_handler = handler;
}
