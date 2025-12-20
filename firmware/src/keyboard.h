#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "layout.h"

static const uint8_t col_to_gpio[N_COLS] = { 0, 1, 2 };
static const uint8_t row_to_gpio[N_ROWS] = { 3, 4 };

void kbd_init(void);
bool kbd_update(uint8_t *keycodes);

#endif // KEYBOARD_H
