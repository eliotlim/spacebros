#include "lwcgl.h"

unsigned int prev_tick = 0;
int wait(void) {
    while (get_ms() - prev_tick < TICK_DURATION) {
        prev_tick = prev_tick;
    }
    return prev_tick = get_ms();
}