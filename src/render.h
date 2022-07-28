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

} render_bitmap_t;

typedef enum
{
  RENDER_EVENT_RESHAPE,
  RENDER_EVENT_KEYPRESS,
  RENDER_EVENT_FRAME
} render_event_type_t;

typedef struct
{
  render_event_type_t type;
  union
  {
    struct
    {
      // TODO
      char key;
    } keypress;
  };
} render_event_t;

typedef void (*render_event_handler_t)(render_event_t event);

/** Get render buffer. */
render_bitmap_t* render_get_buffer(void);

/** Make renderer push updates to screen */
void render_request_refresh(void);

void render_register_event_handler(render_event_handler_t handler);

#endif
