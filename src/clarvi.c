#include "clarvi.h"

void hex_output(int value) {
    int *hex_leds = (int *) 0x04000080;  // define a pointer to the register
    *hex_leds = value;                   // write the value to that address
}

void debug_print(int value) {
    asm ("csrw    0x7B2, %0" : : "r" (value) );
}

int intToBCD(int a) {
    int a0 = rem(a, 10);
    int a1 = rem(div(a, 10), 10);
    return a0 | (a1 << 4);
}