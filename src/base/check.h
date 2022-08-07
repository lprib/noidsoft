#ifndef _CHECK_H_
#define _CHECK_H_

/**
 * Per-file assertion enable/disable.
 *
 * To enable assertions for file:
 *
 * #define CHECK_ENABLE_ASSERTS
 * #include "check.h"
 */

#ifdef CHECK_ENABLE_ASSERTS
#include <assert.h>
#define ASSERT(x) assert(x)
#else
#define ASSERT(x)
#endif

#endif
