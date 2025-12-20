#ifndef LAYOUT_H
#define LAYOUT_H

#include "class/hid/hid.h"

#define N_COLS 3
#define N_ROWS 2

static const uint8_t layout[N_ROWS][N_COLS] = {
    { HID_KEY_Q, HID_KEY_W, HID_KEY_E },
    { HID_KEY_A, HID_KEY_S, HID_KEY_D }
};

#endif // LAYOUT_H
