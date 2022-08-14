#include "str.h"
#include "check.h"

#include <stdio.h>
#include <string.h>

#define T str_t

T str_new(char* c_str)
{
  return (T){c_str, strlen(c_str)};
}

T str_chopleft(T str)
{
  return (T){str.ptr + 1, str.len - 1};
}

void str_print(T str)
{
  fwrite(str.ptr, sizeof(char), str.len, stdout);
}

#undef T
