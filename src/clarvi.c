#include "clarvi.h"

void hex_output(int value)
{
    int *hex_leds = (int *)0x04000080; // define a pointer to the register
    *hex_leds = value;                 // write the value to that address
}

void debug_print(int value)
{
    asm("csrw    0x7B2, %0"
        :
        : "r"(value));
}

int intToBCD(int a)
{
    int a0 = rem(a, 10);
    int a1 = rem(div(a, 10), 10);
    return a0 | (a1 << 4);
}

int get_ms(void)
{
    int time = *((int *)PIO_TIMER_MS);
    return time;
}

int avalon_read(unsigned int address)
{
    volatile int *pointer = (volatile int *)address;
    return pointer[0];
}

void avalon_write(unsigned int address, int data)
{
    volatile int *pointer = (volatile int *)address;
    pointer[0] = data;
}