#ifndef _BASE_CHECK_H_
#define _BASE_CHECK_H_

/** enable/disable asserts for whole project: */
#define CHECK_ENABLE_ASSERTS 0

#if CHECK_ENABLE_ASSERTS
#include <assert.h>
#define ASSERT(x) assert(x)
#else
#define ASSERT(x)
#endif

#endif
