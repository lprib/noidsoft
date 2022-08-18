#include "diagnostics.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static diag_text_t texts[DIAG_NUM_TEXTS];

#define TO_STRING_LIST(ident, name) name,
static char const* const diag_names[DIAG_NUM_TEXTS] = {
    DIAG_TEXT_LIST(TO_STRING_LIST)};

void diag_text(diag_text_type_t type, char* format, ...)
{
  int prefix_len = snprintf(
      texts[type].buffer,
      DIAG_MAX_TEXT_LEN - 1,
      "%s: ",
      diag_names[type]
  );

  va_list args;
  va_start(args, format);
  vsnprintf(
      texts[type].buffer + prefix_len,
      DIAG_MAX_TEXT_LEN - prefix_len - 1,
      format,
      args
  );
  va_end(args);
}

diag_text_t* diag_text_get(int idx)
{
  return &texts[idx];
}
