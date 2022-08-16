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
static uint8_t read_data(T self, bool rs, uint8_t data);
static void wait_busy(T self);

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
    write_data(self, 1, ' ');
  }

  while (*string)
  {
    write_data(self, 1, *string);
    string++;
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

static uint8_t read_data(T self, bool rs, uint8_t data)
{
  return 0;
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

#undef T
