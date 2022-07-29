#ifndef _SDL_RENDER_H_
#define _SDL_RENDER_H_

/**
 * Generic platform-agnostic rendering functions
 */

#include <stdint.h>

typedef struct
{
  /** width in pixels */
  int width;

  /** height in pixels */
  int height;

  /** width of buffer in bytes. Total buffer size is width_bytes*height. Buffer
   * width is the minimum amount of bytes to hold `width` pixels. Ie. there may
   * be padding.
   */
  int width_bytes;

  /* buffer */
  uint8_t* buffer;

} r_bmp_t;

typedef enum
{
  RENDER_EVENT_RESHAPE,
  RENDER_EVENT_KEYPRESS,
  RENDER_EVENT_FRAME
} r_event_type_t;

typedef struct
{
  r_event_type_t type;
  union
  {
    struct
    {
      // TODO
      char key;
    } keypress;
  };
} r_event_t;

typedef void (*r_event_handler_t)(r_event_t event);

/** Get render buffer. */
r_bmp_t* r_get_buffer(void);

/** Make renderer push updates to screen */
void r_request_refresh(void);

void r_register_event_handler(r_event_handler_t handler);

#endif
