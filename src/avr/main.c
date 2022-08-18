#define F_CPU 16000000UL

#include "avr_mmi.h"
#include "dio.h"

#include <ui/ui_main.h>

#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

int main(void)
{
  avrmmi_init();
  ui_init();
  avrmmi_main_loop();
}
