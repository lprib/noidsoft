// provided interfaces
#include "sdl2_render_driver.h"
#include "render.h"

// dependencies
#include "SDL_render.h"
#include "SDL_video.h"
#include "util.h"

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int w;
  int h;
} rect_size_t;

static void create_virtual_render_texture(void);
static void resize_bitmap(rect_size_t new_size);
static rect_size_t get_bitmap_size_for_window(int window_width, int window_height);

r_event_handler_t event_handler = NULL;

bmp_t bitmap;

static int const INITIAL_PIX_WIDTH = 128;
static int const INITIAL_PIX_HEIGHT = 64;

static int const SCREEN_PIX_PER_VIRTUAL_PIX = 8;

#define BACK_COLOR 36, 27, 23, 255
#define FORE_COLOR 219, 200, 175, 255

// used to track if we really need to send a resize event to the client
rect_size_t previous_tex_size = {0, 0};

// SDL globals
/** Size of texture when drawing virtual bitmap to screen */
SDL_Rect virtual_tex_screen_size = {0, 0, 0, 0};
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* virtual_tex;

#define BIT(byte, n) ((byte) >> (n)) & 0b1

#define TRY_EVENT_HANDLER(event) \
  do \
  { \
    if (event_handler) \
      event_handler(event); \
  } while (0);

void sdl_init(void)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    exit(100);
  }

  window = SDL_CreateWindow(
      "test",
      0,
      0,
      INITIAL_PIX_WIDTH * SCREEN_PIX_PER_VIRTUAL_PIX,
      INITIAL_PIX_HEIGHT * SCREEN_PIX_PER_VIRTUAL_PIX,
      SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE
  );
  SDL_SetWindowMaximumSize(
      window,
      INITIAL_PIX_WIDTH * SCREEN_PIX_PER_VIRTUAL_PIX,
      INITIAL_PIX_HEIGHT * SCREEN_PIX_PER_VIRTUAL_PIX
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  // set up virtual bitmap
  bitmap.width = INITIAL_PIX_WIDTH;
  bitmap.height = INITIAL_PIX_HEIGHT;
  bitmap.width_elems = utl_divide_round_up(INITIAL_PIX_WIDTH, BMP_PIX_PER_ELEM);
  bitmap.buffer = malloc((bitmap.width_elems * bitmap.height) * sizeof(*bitmap.buffer));

  // Set previous so event loop knows when to resize
  previous_tex_size.w = INITIAL_PIX_WIDTH;
  previous_tex_size.h = INITIAL_PIX_HEIGHT;

  create_virtual_render_texture();
}

/** Must destroy the texture first before calling if it already exists */
static void create_virtual_render_texture(void)
{
  virtual_tex = SDL_CreateTexture(
      renderer,
      SDL_PIXELFORMAT_RGB888,
      SDL_TEXTUREACCESS_TARGET,
      bitmap.width,
      bitmap.height
  );
  virtual_tex_screen_size.w = bitmap.width * SCREEN_PIX_PER_VIRTUAL_PIX;
  virtual_tex_screen_size.h = bitmap.height * SCREEN_PIX_PER_VIRTUAL_PIX;
}

void sdl_main_loop(void)
{
  SDL_ShowWindow(window);
  while (1)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        return;
        break;

      case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_RESIZED)
        {
          int window_w = event.window.data1;
          int window_h = event.window.data2;

          rect_size_t new_size = get_bitmap_size_for_window(window_w, window_h);

          // Only fire resize events if the size of the virtual bitmap actually changed.
          // Eg. if the window was only resized a couple of screen-pixels, the
          // appropriate bitmap size may stay the same. In this case we do not
          // need to send a resize event to client.
          if (new_size.w != previous_tex_size.w && new_size.h != previous_tex_size.h)
          {
            resize_bitmap(new_size);

            // re-create texture object
            SDL_DestroyTexture(virtual_tex);
            create_virtual_render_texture();

            r_event_t ev = {.type = RENDER_EVENT_RESHAPE};
            TRY_EVENT_HANDLER(ev);

            previous_tex_size = new_size;
          }
        }
        break;
      }
    }

    TRY_EVENT_HANDLER((r_event_t){.type = RENDER_EVENT_FRAME});

    SDL_SetRenderTarget(renderer, NULL);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, virtual_tex, NULL, &virtual_tex_screen_size);
    SDL_RenderPresent(renderer);
  }
}

void sdl_cleanup(void)
{
  SDL_DestroyTexture(virtual_tex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

bmp_t* r_get_buffer(void)
{
  return &bitmap;
}

void r_request_refresh(void)
{
  SDL_SetRenderTarget(renderer, virtual_tex);
  SDL_SetRenderDrawColor(renderer, BACK_COLOR);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, FORE_COLOR);

  for (int y = 0; y < bitmap.height; y++)
  {
    for (int x = 0; x < bitmap.width; x++)
    {
      // TODO need to check if out of bounds?
      bmp_elem_t byte = bitmap.buffer[y * bitmap.width_elems + x / BMP_PIX_PER_ELEM];

      // TODO reverse?
      int bit_idx = x % BMP_PIX_PER_ELEM;
      if (BIT(byte, bit_idx))
      {
        SDL_RenderDrawPoint(renderer, x, y);
      }
    }
  }
}

void r_register_event_handler(r_event_handler_t handler)
{
  event_handler = handler;
}

static rect_size_t get_bitmap_size_for_window(int window_width, int window_height)
{
  return (rect_size_t
  ){.w = window_width / SCREEN_PIX_PER_VIRTUAL_PIX,
    .h = window_height / SCREEN_PIX_PER_VIRTUAL_PIX};
}

static void resize_bitmap(rect_size_t new_size)
{
  bitmap.width = new_size.w;
  bitmap.height = new_size.h;

  bitmap.width_elems = utl_divide_round_up(bitmap.width, BMP_PIX_PER_ELEM);

  bitmap.buffer =
      realloc(bitmap.buffer, (bitmap.width_elems * bitmap.height) * sizeof(*bitmap.buffer));
}
