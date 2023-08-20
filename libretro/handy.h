#include <stdlib.h>
#include <libretro.h>

#include "system.h"
#include "lynxdef.h"

#define HANDYVER    "0.97"
#define ROM_FILE    "lynxboot.img"

extern "C" void handy_log(enum retro_log_level level, const char *format, ...);
