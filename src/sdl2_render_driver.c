// provided interfaces
#include "sdl2_render_driver.h"
#include "bitmap.h"
#include "render.h"

// dependencies
#include "SDL_render.h"
#include "SDL_video.h"
#include "diagnostics.h"
#include "util.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

char const* FONT_PATH = "firacode.ttf";

typedef struct
{
  int w;
  int h;
} rect_size_t;

static void create_virtual_render_texture(void);
static void resize_bitmap(rect_size_t new_size);
static rect_size_t
get_bitmap_size_for_window(int window_width, int window_height);
static void render_diagnostic_text(void);

r_event_handler_t event_handler = NULL;

bmp_t back_buffer;

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

TTF_Font* font;
SDL_Texture* diag_tex;

#define GET_BIT(integer, n) ((integer) >> (n)) & 0b1

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

  renderer = SDL_CreateRenderer(
      window,
      -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );

  // set up diag text
  TTF_Init();
  font = TTF_OpenFont(FONT_PATH, 12);
  if (font == NULL)
  {
    fprintf(stderr, "font not found\n");
    exit(101);
  }

  // set up virtual bitmap
  back_buffer.width = INITIAL_PIX_WIDTH;
  back_buffer.height = INITIAL_PIX_HEIGHT;
  back_buffer.width_elems =
      utl_divide_round_up(INITIAL_PIX_WIDTH, BMP_PIX_PER_ELEM);
  back_buffer.buffer = malloc(
      (back_buffer.width_elems * back_buffer.height) * sizeof(bmp_elem_t)
  );

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
      back_buffer.width,
      back_buffer.height
  );
  virtual_tex_screen_size.w = back_buffer.width * SCREEN_PIX_PER_VIRTUAL_PIX;
  virtual_tex_screen_size.h = back_buffer.height * SCREEN_PIX_PER_VIRTUAL_PIX;
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

          // Only fire resize events if the size of the virtual bitmap actually
          // changed. Eg. if the window was only resized a couple of
          // screen-pixels, the appropriate bitmap size may stay the same. In
          // this case we do not need to send a resize event to client. if
          // (new_size.w != previous_tex_size.w && new_size.h !=
          // previous_tex_size.h)
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
      case SDL_MOUSEMOTION:
        diag_text(
            DIAG_TEXT_cursor_pos,
            "%d %d\n",
            event.motion.x,
            event.motion.y
        );
        break;
      }
    }
    TRY_EVENT_HANDLER((r_event_t){.type = RENDER_EVENT_FRAME});

    render_diagnostic_text();

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
  return &back_buffer;
}

void r_request_refresh(void)
{
  SDL_SetRenderTarget(renderer, virtual_tex);
  SDL_SetRenderDrawColor(renderer, BACK_COLOR);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, FORE_COLOR);

  for (int y = 0; y < back_buffer.height; y++)
  {
    for (int x = 0; x < back_buffer.width; x++)
    {
      // TODO need to check if out of bounds?
      bmp_elem_t elem =
          back_buffer
              .buffer[y * back_buffer.width_elems + x / BMP_PIX_PER_ELEM];

      // TODO reverse?
      int bit_idx = x % BMP_PIX_PER_ELEM;
      if (GET_BIT(elem, bit_idx))
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

static rect_size_t
get_bitmap_size_for_window(int window_width, int window_height)
{
  return (rect_size_t
  ){.w = window_width / SCREEN_PIX_PER_VIRTUAL_PIX,
    .h = window_height / SCREEN_PIX_PER_VIRTUAL_PIX};
}

static void resize_bitmap(rect_size_t new_size)
{
  back_buffer.width = new_size.w;
  back_buffer.height = new_size.h;

  back_buffer.width_elems =
      utl_divide_round_up(back_buffer.width, BMP_PIX_PER_ELEM);

  back_buffer.buffer = realloc(
      back_buffer.buffer,
      (back_buffer.width_elems * back_buffer.height) * sizeof(bmp_elem_t)
  );
}

static void render_diagnostic_text(void)
{
  static const SDL_Color fg = {255, 0, 0, 255};
  static const SDL_Color bg = {0, 0, 0, 80};

  SDL_Surface* surface =
      TTF_RenderText_Shaded(font, diag_text_get(0)->buffer, fg, bg);

  // TODO
  // cannot create new textures each time. So store a buffer of them, and only
  // update them when the diagnostic text updates.
}
