// provided interfaces
#include "sdl2_render_driver.h"
#include <mmi/mmi.h>

// dependencies
#include <base/util.h>
#include <mmi/bitmap.h>
#include <mmi/diagnostics.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char const* DIAGNOSTIC_FONT_TTF_PATH = "assets/firacode.ttf";

typedef struct
{
  int w;
  int h;
} rect_size_t;

typedef struct
{
  TTF_Font* font;
  SDL_Texture* diag_tex[DIAG_NUM_TEXTS];
  bool do_render;
} diag_text_render_data_t;

static void send_to_client(mmi_event_t event);
static void create_virtual_render_texture(void);
static void resize_bitmap(rect_size_t new_size);
static rect_size_t
get_bitmap_size_for_window(int window_width, int window_height);
static void update_diagnostic_text(bool first_time);
static void render_diagnostic_text(void);
static mmi_key_t sdl_keycode_to_key(SDL_Keycode keycode);

mmi_event_handler_t event_handler = NULL;

bmp_t back_buffer;

static int const INITIAL_PIX_WIDTH = 128;
static int const INITIAL_PIX_HEIGHT = 64;

static int const SCREEN_PIX_PER_VIRTUAL_PIX = 4;

#define BACK_COLOR 36, 27, 23, 255
#define FORE_COLOR 219, 200, 175, 255

static const SDL_Color diag_text_fg = {255, 126, 94, 255};
static const SDL_Color diag_text_bg = {0, 0, 0, 128};

// used to track if we really need to send a resize event to the client
rect_size_t previous_tex_size = {0, 0};

// SDL globals
/** Size of texture when drawing virtual bitmap to screen */
SDL_Rect virtual_tex_screen_size = {0, 0, 0, 0};
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* virtual_tex;

diag_text_render_data_t diag_render_data;

#define GET_BIT(integer, n) ((integer) >> (n)) & 0b1

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
      SDL_WINDOW_HIDDEN
      // | SDL_WINDOW_RESIZABLE
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
  diag_render_data.font = TTF_OpenFont(DIAGNOSTIC_FONT_TTF_PATH, 12);
  if (diag_render_data.font == NULL)
  {
    fprintf(stderr, "font not found\n");
    exit(101);
  }

  update_diagnostic_text(true);
  diag_render_data.do_render = true;

  // set up virtual bitmap
  back_buffer.w = INITIAL_PIX_WIDTH;
  back_buffer.h = INITIAL_PIX_HEIGHT;
  back_buffer.width_elems =
      utl_divide_round_up(INITIAL_PIX_WIDTH, BMP_PIX_PER_ELEM);
  back_buffer.buffer =
      malloc((back_buffer.width_elems * back_buffer.h) * sizeof(bmp_elem_t));

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
      back_buffer.w,
      back_buffer.h
  );
  virtual_tex_screen_size.w = back_buffer.w * SCREEN_PIX_PER_VIRTUAL_PIX;
  virtual_tex_screen_size.h = back_buffer.h * SCREEN_PIX_PER_VIRTUAL_PIX;
}

void sdl_main_loop(void)
{
  SDL_ShowWindow(window);

  mmi_event_t ev = {.type = RENDER_EVENT_DRIVER_INITIALIZED};
  send_to_client(ev);

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

          diag_text(DIAG_TEXT_WIN_SIZE, "%d %d", window_w, window_h);

          rect_size_t new_size = get_bitmap_size_for_window(window_w, window_h);

          // Only fire resize events if the size of the virtual bitmap actually
          // changed. Eg. if the window was only resized a couple of
          // screen-pixels, the appropriate bitmap size may stay the same. In
          // this case we do not need to send a resize event to client.
          if (new_size.w != previous_tex_size.w &&
              new_size.h != previous_tex_size.h)
          {
            resize_bitmap(new_size);
            diag_text(DIAG_TEXT_WIN_SIZE_PX, "%d %d", new_size.w, new_size.h);
            diag_text(
                DIAG_TEXT_RENDER_TEX_SIZE,
                "%d %d",
                new_size.w * SCREEN_PIX_PER_VIRTUAL_PIX,
                new_size.h * SCREEN_PIX_PER_VIRTUAL_PIX
            );

            // re-create texture object
            SDL_DestroyTexture(virtual_tex);
            create_virtual_render_texture();

            mmi_event_t ev = {.type = RENDER_EVENT_RESHAPE};
            send_to_client(ev);

            previous_tex_size = new_size;
          }
        }
        break;
      case SDL_MOUSEMOTION:
        diag_text(
            DIAG_TEXT_CURSOR,
            "%d %d",
            event.motion.x / SCREEN_PIX_PER_VIRTUAL_PIX,
            event.motion.y / SCREEN_PIX_PER_VIRTUAL_PIX
        );
        break;
      case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
          diag_render_data.do_render = !diag_render_data.do_render;
        }
        break;
      case SDL_KEYDOWN:
      {
        mmi_key_t key = sdl_keycode_to_key(event.key.keysym.sym);
        if (key != KEY_INVALID)
        {
          mmi_event_t ev = {
              .type = RENDER_EVENT_KEYDOWN,
              .key_event = {.key = key}};
          send_to_client(ev);
        }
      }
      break;
      case SDL_KEYUP:
      {
        mmi_key_t key = sdl_keycode_to_key(event.key.keysym.sym);
        if (key != KEY_INVALID)
        {
          mmi_event_t ev = {
              .type = RENDER_EVENT_KEYUP,
              .key_event = {.key = key}};
          send_to_client(ev);
        }
      }
      break;
      }
    }
    send_to_client((mmi_event_t){.type = RENDER_EVENT_FRAME});

    SDL_SetRenderTarget(renderer, NULL);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, virtual_tex, NULL, &virtual_tex_screen_size);

    update_diagnostic_text(false);
    if (diag_render_data.do_render)
    {
      render_diagnostic_text();
    }

    SDL_RenderPresent(renderer);
  }
}

void sdl_cleanup(void)
{
  SDL_DestroyTexture(virtual_tex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

bmp_t* mmi_get_render_target(void)
{
  return &back_buffer;
}

void mmi_display_refresh(void)
{
  SDL_SetRenderTarget(renderer, virtual_tex);
  SDL_SetRenderDrawColor(renderer, BACK_COLOR);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, FORE_COLOR);

  for (int y = 0; y < back_buffer.h; y++)
  {
    for (int x = 0; x < back_buffer.w; x++)
    {
      bmp_elem_t elem =
          back_buffer
              .buffer[y * back_buffer.width_elems + x / BMP_PIX_PER_ELEM];

      int bit_idx = BMP_PIX_PER_ELEM - x % BMP_PIX_PER_ELEM - 1;
      if (GET_BIT(elem, bit_idx))
      {
        SDL_RenderDrawPoint(renderer, x, y);
      }
    }
  }
}

void mmi_register_event_handler(mmi_event_handler_t handler)
{
  event_handler = handler;
}

void mmi_printf(char* format, ...)
{
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}

static void send_to_client(mmi_event_t event)
{
  if (event_handler != NULL)
  {
    event_handler(event);
  }
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
  back_buffer.w = new_size.w;
  back_buffer.h = new_size.h;

  back_buffer.width_elems =
      utl_divide_round_up(back_buffer.w, BMP_PIX_PER_ELEM);

  back_buffer.buffer = realloc(
      back_buffer.buffer,
      (back_buffer.width_elems * back_buffer.h) * sizeof(bmp_elem_t)
  );
}

static void update_diagnostic_text(bool first_time)
{
  for (int i = 0; i < DIAG_NUM_TEXTS; i++)
  {
    SDL_Surface* surface = TTF_RenderUTF8_Shaded(
        diag_render_data.font,
        diag_text_get(i)->buffer,
        diag_text_fg,
        diag_text_bg
    );

    if (!first_time)
    {
      SDL_DestroyTexture(diag_render_data.diag_tex[i]);
    }
    diag_render_data.diag_tex[i] =
        SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
  }
}

static void render_diagnostic_text(void)
{
  int y = 0;

  for (int i = 0; i < DIAG_NUM_TEXTS; i++)
  {
    SDL_Texture* tex = diag_render_data.diag_tex[i];
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    SDL_Rect dest_rect = {0, y, w, h};
    SDL_RenderCopy(renderer, tex, NULL, &dest_rect);
    y += h;
  }
}

static mmi_key_t sdl_keycode_to_key(SDL_Keycode keycode)
{
  switch (keycode)
  {
  case SDLK_a:
    return KEY_A;
  case SDLK_b:
    return KEY_B;
  case SDLK_c:
    return KEY_C;
  case SDLK_d:
    return KEY_D;
  case SDLK_e:
    return KEY_E;
  case SDLK_f:
    return KEY_F;
  case SDLK_g:
    return KEY_G;
  case SDLK_h:
    return KEY_H;
  case SDLK_i:
    return KEY_I;
  case SDLK_j:
    return KEY_J;
  case SDLK_k:
    return KEY_K;
  case SDLK_l:
    return KEY_L;
  case SDLK_m:
    return KEY_M;
  case SDLK_n:
    return KEY_N;
  case SDLK_o:
    return KEY_O;
  case SDLK_p:
    return KEY_P;
  case SDLK_q:
    return KEY_Q;
  case SDLK_r:
    return KEY_R;
  case SDLK_s:
    return KEY_S;
  case SDLK_t:
    return KEY_T;
  case SDLK_u:
    return KEY_U;
  case SDLK_v:
    return KEY_V;
  case SDLK_w:
    return KEY_W;
  case SDLK_x:
    return KEY_X;
  case SDLK_y:
    return KEY_Y;
  case SDLK_z:
    return KEY_Z;
  case SDLK_SPACE:
    return KEY_SPACE;
  case SDLK_0:
    return KEY_0;
  case SDLK_1:
    return KEY_1;
  case SDLK_2:
    return KEY_2;
  case SDLK_3:
    return KEY_3;
  case SDLK_4:
    return KEY_4;
  case SDLK_5:
    return KEY_5;
  case SDLK_6:
    return KEY_6;
  case SDLK_7:
    return KEY_7;
  case SDLK_8:
    return KEY_8;
  case SDLK_9:
    return KEY_9;
  case SDLK_LEFT:
    return KEY_LEFT;
  case SDLK_RIGHT:
    return KEY_RIGHT;
  case SDLK_UP:
    return KEY_UP;
  case SDLK_DOWN:
    return KEY_DOWN;
  default:
    return KEY_INVALID;
  }
}
