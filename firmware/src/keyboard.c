#include "bsp/board_api.h"
#include "hardware/gpio.h"

#include "keyboard.h"

void kbd_init(void) {
    for (size_t i = 0; i < N_COLS; i++) {
        gpio_init(col_to_gpio[i]);
        gpio_set_dir(col_to_gpio[i], GPIO_IN);
        gpio_pull_up(col_to_gpio[i]);
    }
    
    for (size_t i = 0; i < N_ROWS; i++) {
        gpio_init(row_to_gpio[i]);
        gpio_set_dir(row_to_gpio[i], GPIO_OUT);
        gpio_put(row_to_gpio[i], 1);
    }
}

bool kbd_update(uint8_t *keycodes) {
    for (size_t i = 0; i < 6; i++) {
        keycodes[i] = 0;
    }

    uint8_t index = 0;
    bool changed = false;
    for (size_t i = 0; i < N_ROWS; i++) {
        if (index >= 6) {
            break;
        }

        gpio_put(row_to_gpio[i], 0);
        sleep_us(5);

        for (size_t j = 0; j < N_COLS; j++) {
            if (gpio_get(col_to_gpio[j]) != 0)
                continue;

            keycodes[index] = layout[i][j];
            changed = true;
            index++;
            if (index >= 6) {
                break;
            }
        } 

        gpio_put(row_to_gpio[i], 1);
    }

    return changed;
}
