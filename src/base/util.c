#include "util.h"

int utl_divide_round_up(int numerator, int denominator)
{
  return numerator / denominator + (numerator % denominator != 0);
}
