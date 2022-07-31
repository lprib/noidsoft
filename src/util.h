#ifndef _UTIL_H_
#define _UTIL_H_

int utl_divide_round_up(int numerator, int denominator);

#ifdef UTIL_ENABLE_ASSERTS
#define ASSERT(x) assert(x)
#else
#define ASSERT(x)
#endif

#endif
