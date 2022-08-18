# Monochrome rendering and UI

## File Structure
- **`bdf_to_c`** - Script to convert BDF font files to C source that defines the font. See `src/mmi/font.h` for internal font format.
- **`Makefile`** - Builds the project. Supported targets are default (`make`) and clean (`make clean`).
- **`src/`** C sources and headers.
  - **`src/linux`** - Linux specific mmi drivers.
  - **`src/avr`** - AVR specific mmi drivers.
  - **`src/base/`** - Base utilities.
  - **`src/mmi/`** - Mostly generic drawing utilities (windows, bitmaps, fonts, etc).
  - **`src/ui/`** - High-level UI components.
- **`assets/`** - Assets (only fonts for now).
- **`out/`** - Compilation output.
  - **`out/main`** - Main executable.

## Architecture
To implement a platform interface, you must implement the `src/mmi/mmi.h`
header for the platform. All other UI and event handling is based upon this
header.

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
