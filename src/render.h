#ifndef _SDL_RENDER_H_
#define _SDL_RENDER_H_

/**
 * Generic platform-agnostic rendering and event loop functions.
 */

#include "bitmap.h"
#include "key.h"

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
  RENDER_EVENT_RESHAPE,
  RENDER_EVENT_KEYUP,
  RENDER_EVENT_KEYDOWN,
  RENDER_EVENT_FRAME
} r_event_type_t;

typedef struct
{
  r_event_type_t type;
  union
  {
    struct
    {
      r_key_t key;
    } key_event;
  };
} r_event_t;


typedef void (*r_event_handler_t)(r_event_t event);

/** Get render buffer. */
bmp_t* r_get_buffer(void);

/** Make renderer push updates to screen */
void r_request_refresh(void);

void r_register_event_handler(r_event_handler_t handler);

#endif
