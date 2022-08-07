#ifndef _UTIL_H_
#define _UTIL_H_

typedef struct
{
  int x;
  int y;
  int w;
  int h;
} rect_t;

int utl_divide_round_up(int numerator, int denominator);

#endif
