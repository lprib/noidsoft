#ifndef _PLATFORM_INTERFACE_ERROR_CHECK_H_
#define _PLATFORM_INTERFACE_ERROR_CHECK_H_

/**
 * Due to the differing interfaces between linux and AVR, we have to use ifdefs
 * here instead of proper dependency swapping.
 *
 * AVR cannot use baked in __FILE__ strings due to progmem usage.
 */

#include <stdbool.h>

/** enable/disable asserts for whole project: */
#define ERROR_CHECK_ENABLE 1

#if ERROR_CHECK_ENABLE
#define CHECK(expr) priv_ERROR_CHECK_INTERNAL((expr), #expr, __FILE__, __LINE__)
#else
#define CHECK(expr)
#endif

#if PLATFORM_LINUX
#include <stdio.h>
#include <stdlib.h>
#define priv_ERROR_CHECK_INTERNAL(expr, expr_string, file, line) \
  do \
  { \
    if (!(expr)) \
    { \
      fprintf( \
          stderr, \
          "Error check failed %s:%d:\n%s\n", \
          file, \
          line, \
          expr_string \
      ); \
      exit(1); \
    } \
  } while (0)
#endif

#if PLATFORM_AVR
#include <avr/usart.h>
// ASSUMPTION: USART0 is used for stdout and is already initialized.
#define priv_ERROR_CHECK_INTERNAL(expr, expr_string, file, line) \
  do \
  { \
    if (!(expr)) \
    { \
      usart_write_string(usart_get_from_number(0), "Error check failed\n"); \
      while (1) \
      { \
      } \
    } \
  } while (0)
#endif

#endif
