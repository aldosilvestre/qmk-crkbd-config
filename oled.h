#pragma once

#include <stdio.h>

#ifdef OLED_VERTICAL
#define KEYLOG_LEN (49)
#else
#define KEYLOG_LEN (38)
#endif

#define KEYLOG_EOL_LEN (KEYLOG_LEN+1)

extern void add_keylog(uint16_t keycode);
