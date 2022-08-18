#ifndef _AVR_DIO_H_
#define _AVR_DIO_H_

/**
 * Digital IO abstraction.
 */

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

/** An IO control register */
typedef uint8_t volatile* register_t;

/* clang-format off */

typedef enum
{
  DIO_PIN_A0, DIO_PIN_A1, DIO_PIN_A2, DIO_PIN_A3, DIO_PIN_A4, DIO_PIN_A5, DIO_PIN_A6, DIO_PIN_A7,
  DIO_PIN_B0, DIO_PIN_B1, DIO_PIN_B2, DIO_PIN_B3, DIO_PIN_B4, DIO_PIN_B5, DIO_PIN_B6, DIO_PIN_B7,
  DIO_PIN_C0, DIO_PIN_C1, DIO_PIN_C2, DIO_PIN_C3, DIO_PIN_C4, DIO_PIN_C5, DIO_PIN_C6, DIO_PIN_C7,
  DIO_PIN_D0, DIO_PIN_D1, DIO_PIN_D2, DIO_PIN_D3, DIO_PIN_D4, DIO_PIN_D5, DIO_PIN_D6, DIO_PIN_D7,
  DIO_PIN_E0, DIO_PIN_E1, DIO_PIN_E2, DIO_PIN_E3, DIO_PIN_E4, DIO_PIN_E5, DIO_PIN_E6, DIO_PIN_E7,
  DIO_PIN_F0, DIO_PIN_F1, DIO_PIN_F2, DIO_PIN_F3, DIO_PIN_F4, DIO_PIN_F5, DIO_PIN_F6, DIO_PIN_F7,
  DIO_PIN_G0, DIO_PIN_G1, DIO_PIN_G2, DIO_PIN_G3, DIO_PIN_G4, DIO_PIN_G5, DIO_PIN_G6, DIO_PIN_G7,
  DIO_PIN_H0, DIO_PIN_H1, DIO_PIN_H2, DIO_PIN_H3, DIO_PIN_H4, DIO_PIN_H5, DIO_PIN_H6, DIO_PIN_H7,
  DIO_PIN_J0, DIO_PIN_J1, DIO_PIN_J2, DIO_PIN_J3, DIO_PIN_J4, DIO_PIN_J5, DIO_PIN_J6, DIO_PIN_J7,
  DIO_PIN_K0, DIO_PIN_K1, DIO_PIN_K2, DIO_PIN_K3, DIO_PIN_K4, DIO_PIN_K5, DIO_PIN_K6, DIO_PIN_K7,
  DIO_PIN_L0, DIO_PIN_L1, DIO_PIN_L2, DIO_PIN_L3, DIO_PIN_L4, DIO_PIN_L5, DIO_PIN_L6, DIO_PIN_L7,
} dio_pin_t;

typedef enum
{
  DIO_BANK_A, DIO_BANK_B, DIO_BANK_C, DIO_BANK_D, DIO_BANK_E, DIO_BANK_F,
  DIO_BANK_G, DIO_BANK_H, DIO_BANK_J, DIO_BANK_K, DIO_BANK_L, DIO_NUM_BANKS
} dio_bank_t;

/* clang-format on */

extern register_t const dio_ddr_regs[DIO_NUM_BANKS];
extern register_t const dio_port_regs[DIO_NUM_BANKS];
extern register_t const dio_pin_regs[DIO_NUM_BANKS];

static inline register_t dio_ddr(dio_pin_t pin)
{
  return dio_ddr_regs[pin >> 3];
}

static inline register_t dio_port(dio_pin_t pin)
{
  return dio_port_regs[pin >> 3];
}

static inline register_t dio_pin(dio_pin_t pin)
{
  return dio_pin_regs[pin >> 3];
}

static inline uint8_t dio_mask(dio_pin_t pin)
{
  return 1 << (pin & 0b111);
}

static inline void dio_set_direction(dio_pin_t pin, bool output)
{
  if (output)
  {
    *dio_ddr(pin) |= dio_mask(pin);
  }
  else
  {
    *dio_ddr(pin) &= ~dio_mask(pin);
  }
}

static inline void dio_set(dio_pin_t pin, bool value)
{
  if (value)
  {
    *dio_port(pin) |= dio_mask(pin);
  }
  else
  {
    *dio_port(pin) &= ~dio_mask(pin);
  }
}

static inline bool dio_get(dio_pin_t pin)
{
  return *dio_pin(pin) & dio_mask(pin);
}

#endif
