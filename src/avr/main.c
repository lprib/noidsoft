#define F_CPU 16000000UL

#include "mmi_manager.h"

#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

int main(void)
{
  mmimanager_init();
  mmimanager_run_loop();
}
