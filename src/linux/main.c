#include "linux_mmi.h"

#include <ui/ui_main.h>

#include <execinfo.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void segfault_handler(int sig)
{
  void* array[10];
  size_t size;

  size = backtrace(array, 10);
  fprintf(stderr, "Segfault %d", sig);
  backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

int main(int argc, char* argv[])
{
  signal(SIGSEGV, &segfault_handler);

  linuxmmi_init();
  ui_init();
  linuxmmi_main_loop();
  linuxmmi_cleanup();
  return 0;
}
