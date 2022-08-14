#ifndef _BASE_STR_H_
#define _BASE_STR_H_

#include <stdlib.h>

#define T str_t

typedef struct
{
  char* ptr;
  size_t len;
} T;

T str_new(char* c_str);

T str_chopleft(T str);

void str_print(T str);

#undef T
#endif
