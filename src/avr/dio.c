#include "dio.h"

register_t const dio_ddr_regs[DIO_NUM_BANKS] = {
    &DDRA,
    &DDRB,
    &DDRC,
    &DDRD,
    &DDRE,
    &DDRF,
    &DDRG,
    &DDRH,
    &DDRJ,
    &DDRK,
    &DDRL,
};

register_t const dio_port_regs[DIO_NUM_BANKS] = {
    &PORTA,
    &PORTB,
    &PORTC,
    &PORTD,
    &PORTE,
    &PORTF,
    &PORTG,
    &PORTH,
    &PORTJ,
    &PORTK,
    &PORTL,
};

register_t const dio_pin_regs[DIO_NUM_BANKS] = {
    &PINA,
    &PINB,
    &PINC,
    &PIND,
    &PINE,
    &PINF,
    &PING,
    &PINH,
    &PINJ,
    &PINK,
    &PINL,
};
