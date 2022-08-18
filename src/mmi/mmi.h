#ifndef _MMI_MMI_H_
#define _MMI_MMI_H_

/**
 * Low level mmi (rendering output and event input).
 */

#include "bitmap.h"
#include "key.h"

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
  RENDER_EVENT_RESHAPE,
  RENDER_EVENT_DRIVER_INITIALIZED,
  RENDER_EVENT_KEYUP,
  RENDER_EVENT_KEYDOWN,
  RENDER_EVENT_FRAME
} mmi_event_type_t;

typedef struct
{
  mmi_event_type_t type;
  union
  {
    struct
    {
      mmi_key_t key;
    } key_event;
  };
} mmi_event_t;

typedef void (*mmi_event_handler_t)(mmi_event_t event);

/** Get render buffer. */
bmp_t* mmi_get_render_target(void);

/** Make renderer push updates to screen */
void mmi_display_refresh(void);

void mmi_register_event_handler(mmi_event_handler_t handler);

void mmi_printf(char* format, ...);

#endif
