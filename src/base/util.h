#ifndef _UTIL_H_
#define _UTIL_H_

#include <stddef.h>

typedef struct
{
  int x;
  int y;
  int w;
  int h;
} rect_t;

int utl_divide_round_up(int numerator, int denominator);

#define container_of(ptr, type, member) \
  ({ \
    const typeof(((type*)0)->member)* __mptr = (ptr); \
    (type*)((char*)__mptr - offsetof(type, member)); \
  })

#endif
