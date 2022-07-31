#ifndef _DIAGNOSTICS_H_
#define _DIAGNOSTICS_H_

#define DIAG_MAX_TEXT_LEN 100

typedef struct
{
  char buffer[DIAG_MAX_TEXT_LEN];
} diag_text_t;

#define DIAG_TEXT_LIST(selector) \
  selector(cursor_virt_pix_coord) \
  selector(window_true_size) \
  selector(window_pix_size) \
  selector(window_pix_size_x) \

#define DIAG_TEXT_ENUM_VARIANT(name) DIAG_TEXT_##name,

typedef enum
{
  DIAG_TEXT_LIST(DIAG_TEXT_ENUM_VARIANT)

      DIAG_NUM_TEXTS
} diag_text_type_t;

void diag_text(diag_text_type_t type, char* format, ...);

diag_text_t* diag_text_get(int idx);

#endif
