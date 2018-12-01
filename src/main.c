#include "clarvi.h"
#include "lwcgl.h"

int main(void) {

    // Count to 5 seconds
    while (wait() <= 5000) {
        unsigned int time_cs = div(get_ms(), 10);
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

    return 0;
}

