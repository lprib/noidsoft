#define F_CPU 16000000UL

#include "dio.h"
#include "mmi_manager.h"

#include <ui/ui_main.h>

#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

int main(void)
{
  dio_set_direction(DIO_PIN_B7, true);
  mmimanager_init();
  ui_init();
  mmimanager_run_loop();
}
