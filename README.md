# Monochrome rendering and UI

## File Structure
- **`bdf_to_c`** - Script to convert BDF font files to C source that defines the font. See `src/mmi/font.h` for internal font format.
- **`Makefile`** - Builds the project. Supported targets are default (`make`) and clean (`make clean`).
- **`src/`** C sources and headers.
  - **`src/platform_interface`** - Interface that each platform must implement
  - **`src/linux`** - platform\_interface implementation for linux
  - **`src/avr`** - platform\_interface implementation for avr
  - **`src/base/`** - Base utilities.
  - **`src/render/`** - Mostly generic drawing utilities (windows, bitmaps, fonts, etc), and some keyboard input handling.
  - **`src/ui/`** - High-level UI components.
- **`assets/`** - Assets (only fonts for now).
- **`out/`** - Compilation output.
  - **`out/main`** - Main executable.

## Architecture
To implement a platform interface, you must implement all of the headers in
`src/platform_interface`. All other modules only depend on this interface.

There should never be any dependency on platform specific code outside of that
platform's module.

## Header file template
```c
#ifndef _MODULENAME_HEADERNAME_H_
#define _MODULENAME_HEADERNAME_H_

/**
 * Module overview/documentation.
 */

#include "internal_header_1.h"
#include "internal_header_2.h"

#include <mod1/external_header_1.h>
#include <mod2/external_header_2.h>

#include <system_header_1.h>
#include <system_header_2.h>

#define T mainstruct_t /* Optional: only if this module is class-like */

/**
 * Function documentation
 */
void modulename_functionname(T self);

#undef T /* Optional: only if this module is class-like */
#endif
```
