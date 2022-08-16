/**
 * Implements mmi/mmi.h for the ST7920 display and serial input
 */

#include "mmi_manager.h"
#include "dio.h"
#include "st7920_display.h"

#include <mmi/bitmap.h>
#include <mmi/mmi.h>

struct st7920_t display =
    {.rs = DIO_PIN_E5, .rw = DIO_PIN_G5, .e = DIO_PIN_E3, DIO_BANK_F};

// ASSUMPTION: bmp_elem_t is always uint16_t
bmp_elem_t buffer[ST7920_DISPLAY_WIDTH_UINT16 * ST7920_DISPLAY_HEIGHT] = {0};

bmp_t back_buffer = {
    .w = ST7920_DISPLAY_HEIGHT,
    .h = ST7920_DISPLAY_HEIGHT,
    .width_elems = ST7920_DISPLAY_WIDTH_UINT16,
    .buffer = buffer};

void mmimanager_init(void)
{
  st7920_init(&display);
}

void mmimanager_run_loop(void)
{
  while (1)
  {
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
}
