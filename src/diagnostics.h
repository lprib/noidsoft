#ifndef _DIAGNOSTICS_H_
#define _DIAGNOSTICS_H_

/**
 * Diagnostic utilities. First define a diagnostic type in the DIAG_TEXT_LIST x-macro.
 * Use diag_text to update the text.
 */

#define DIAG_MAX_TEXT_LEN 100

typedef struct
{
  char buffer[DIAG_MAX_TEXT_LEN];
} diag_text_t;

/* Add new diagnositc text here. */
// clang-format off
#define DIAG_TEXT_LIST(selector) \
  selector(CURSOR, "cursor") \
  selector(WIN_SIZE, "win size (screen)") \
  selector(WIN_SIZE_PX, "win size (pix)") \
  selector(RENDER_TEX_SIZE, "render tex size") \
// clang-format on

#define DIAG_TEXT_ENUM_VARIANT(ident, name) DIAG_TEXT_##ident,

typedef enum
{
  DIAG_TEXT_LIST(DIAG_TEXT_ENUM_VARIANT)

      DIAG_NUM_TEXTS
} diag_text_type_t;

/**
 * Set the diagnostic text for the specified diag text type. Uses printf args
 * after type.
 */
void diag_text(diag_text_type_t type, char* format, ...);

/**
 * Get the idx'th diagnostic text string.
 */
diag_text_t* diag_text_get(int idx);

#endif
