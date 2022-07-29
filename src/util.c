#include "util.h"

int utl_divide_round_up(int numerator, int denominator)
{
  return (numerator - 1) / denominator + 1;
}
