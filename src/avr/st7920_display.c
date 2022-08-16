#include "st7920_display.h"

#include "dio.h"

#include <stdint.h>

#define T st7920_t

// mask for reading busy bit from data bus
static const uint8_t BUSY_FLAG_MASK = 0x80;

// ddr mask for setting all data bus pins to output except busy flag
static const uint8_t BUSY_FLAG_INPUT_MASK = 0x7f;
// ddr mask for setting all data bus pins to output
static const uint8_t ALL_OUTPUT_MASK = 0xff;

static void write_data(T self, bool rs, uint8_t data);
static void wait_busy(T self);
static void setup_graphics_mode(T self);

static inline void set_data_bank_direction(T self, uint8_t direction_vector)
{
  *dio_ddr_regs[self->data_bank] = direction_vector;
}

static inline void write_data_bank(T self, uint8_t data)
{
  *dio_port_regs[self->data_bank] = data;
}

static inline uint8_t read_data_bank(T self)
{
  return *dio_pin_regs[self->data_bank];
}

static inline void delay_3_clocks(void)
{
  __asm__ volatile("nop\n\t"
                   "nop\n\t"
                   "nop\n\t");
}

static inline void delay_6_clocks(void)
{
  __asm__ volatile("nop\n\t"
                   "nop\n\t"
                   "nop\n\t"
                   "nop\n\t"
                   "nop\n\t"
                   "nop\n\t");
}

static inline void enter_basic_instruction_set(T self)
{
  // Note this also keeps display in graphics and 8-bit parallel mode
  write_data(self, false, 0x32);
}

static inline void enter_extended_instruction_set(T self)
{
  // Note this also keeps display in graphics and 8-bit parallel mode
  write_data(self, false, 0x36);
}

void st7920_init(T self)
{
  dio_set(self->rs, false);
  dio_set(self->rw, false);
  dio_set(self->e, false);
  write_data_bank(self, 0x00);

  dio_set_direction(self->rs, true);
  dio_set_direction(self->rw, true);
  dio_set_direction(self->e, true);
  set_data_bank_direction(self, ALL_OUTPUT_MASK);

  setup_graphics_mode(self);
}

void st7920_test_mode(T self)
{
  write_data(self, 0, 0x01);
  write_data(self, 0, 0x02);
  write_data(self, 0, 0x0F);

  char* string = "Hello world";
  int row = 0;
  int col = 0;
  int ddram_addr = (row % 2) * 0x10 + (row >= 2) * 0x08 + col / 2;

  write_data(self, false, (1 << 7) | ddram_addr);

  if (col % 2)
  {
    write_data(self, true, ' ');
  }

  while (*string)
  {
    write_data(self, true, *string);
    string++;
  }
}

static int const HALF_HEIGHT = 32;

void st7920_refresh(T self, uint16_t* buffer)
{
  // Note we must already by in extended instruction set mode and graphics mode

  // ERRATA:
  // rather than storing the bottom half of the screen in GDRAM y coordinates
  // 32..63, it is instead stored as GDRAM columns 8-15. So Eg. "logical" row
  // index 32 is actually stored at row 0 in column 8 onwards.
  //
  // We only iterate over the first half of Y values (rows). For each row we
  // first draw the top-half corresponding row in GDRAM column 0-7, then the
  // bottom-half corresponding row in column 8-15.

  for (int y = 0; y < HALF_HEIGHT; y++)
  {
    enter_extended_instruction_set(self);
    // SET GDRAM ADDR Y
    write_data(self, false, (1 << 7) | y);
    // SET GDRAM ADDR X
    write_data(self, false, (1 << 7) | 0);
    enter_basic_instruction_set(self);

    for (int x = 0; x < ST7920_DISPLAY_WIDTH_UINT16; x++)
    {
      uint16_t element = buffer[y * ST7920_DISPLAY_WIDTH_UINT16 + x];
      // WRITE RAM
      write_data(self, true, element >> 8);
      write_data(self, true, element & 0xFF);
    }
    for (int x = 0; x < ST7920_DISPLAY_WIDTH_UINT16; x++)
    {
      uint16_t element =
          buffer[(y + HALF_HEIGHT) * ST7920_DISPLAY_WIDTH_UINT16 + x];
      // WRITE RAM
      write_data(self, true, element >> 8);
      write_data(self, true, element & 0xFF);
    }
  }
}

static void write_data(T self, bool rs, uint8_t data)
{
  dio_set(self->rs, rs);
  dio_set(self->rw, false);

  write_data_bank(self, data);

  dio_set(self->e, true);
  delay_3_clocks();
  dio_set(self->e, false);

  wait_busy(self);
}

static void wait_busy(T self)
{
  set_data_bank_direction(self, BUSY_FLAG_INPUT_MASK);
  dio_set(self->rs, false);
  dio_set(self->rw, true);

  bool busy = true;
  while (busy)
  {
    dio_set(self->e, true);
    delay_6_clocks();
    busy = (read_data_bank(self) & BUSY_FLAG_MASK) != 0;
    dio_set(self->e, false);
  }

  set_data_bank_direction(self, ALL_OUTPUT_MASK);
}

static void setup_graphics_mode(T self)
{
  // FUNCTION SET
  // DL=1 8 bit parallel interface
  write_data(self, false, 0x30);

  // DISPLAY ON/OFF
  // D=1 Display ON
  // C=0 Cursor OFF
  // B=0 Blink Off
  write_data(self, false, 0x0C);

  // FUNCTION SET
  // RE=1 extended instruction set
  write_data(self, false, 0x34);

  // FUNCTION SET
  // G=1 graphics display mode ON
  write_data(self, false, 0x36);
}

#undef T
