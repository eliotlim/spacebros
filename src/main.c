#include "asmfunctions.h"

#define TICKS_SEC 50000000

void hex_output(int value) {
    int *hex_leds = (int *) 0x04000080;  // define a pointer to the register
    *hex_leds = value;                   // write the value to that address
}

void debug_print(int value) {
    asm ("csrw    0x7B2, %0" : : "r" (value) );
}

int myfunction(int x, int y) {
    return x+y;
}

int intToBCD(int a) {
    int a0 = rem(a, 10);
    int a1 = rem(div(a, 10), 10);
    return a0 | (a1 << 4);
}

#define CLOCK 1
#ifdef CLOCK
int main(void) {
    // declare some variables
    int x=12, y=34, z;

    z = myfunction(x,y);
    debug_print(z);
    debug_print(intToBCD(1));
    debug_print(intToBCD(2));
    debug_print(intToBCD(4));
    debug_print(intToBCD(8));
    debug_print(intToBCD(16));
    debug_print(intToBCD(32));
    debug_print(intToBCD(64));
    debug_print(intToBCD(128));
    debug_print(intToBCD(256));

    while (1) {
        unsigned int time_cs = div(get_time(), TICKS_SEC / 100);
        debug_print(time_cs);

        int cs = intToBCD(rem(time_cs, 100));

        int seconds = div(time_cs, 100);
        int s = rem(seconds, 60);
        int ss = intToBCD(s);
        int m = rem(div(seconds, 60), 60);
        int mm = intToBCD(m);
        int h = rem(div(seconds, 60 * 60), 12);
        int hh = intToBCD(h);

        int timeBCD = (hh << 24) | (mm << 16) | (ss << 8) | cs;
        hex_output(timeBCD);
    }

    return z;
}
#else // CLOCK
int main(void) {
    int a0 = 0b0011;
    int a1 = 1;
    debug_print(div(a0, a1));
}
#endif

