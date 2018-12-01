#ifndef CLARVI_H
#define CLARVI_H

#include "asmfunctions.h"

#define TICKS_SEC 50000000

// AVALON MEMORY ADDRESSES
// Theses are offsets from the base of the Clarvi address space
#define FRAMEBUFFER_BASE 0x08000000
#define FRAMEBUFFER_LENGTH 2 * 480 * 272
#define PIO_LED_BASE 0x04000000
#define PIO_HEX_BASE 0x04000080
#define PIO_ROTARY_L 0x04000100
#define PIO_ROTARY_R 0x04000200
#define PIO_BUTTONS 0x04000300
#define PIO_TIMER_MS 0x04000400
#define DEBUG_PRINT 0x07000000

#define ADDR_MASK ((1 << 26) - 1)

#define BUTTONS_MASK_B 0x8000
#define BUTTONS_MASK_A 0x4000
#define BUTTONS_MASK_Y 0x2000
#define BUTTONS_MASK_X 0x1000
#define BUTTONS_MASK_SPARE0 0x800
#define BUTTONS_MASK_TOUCH_IRQ 0x400
#define BUTTONS_MASK_SPARE1 0x200
#define BUTTONS_MASK_SPARE2 0x100
#define BUTTONS_MASK_NAV_U 0x80
#define BUTTONS_MASK_NAV_L 0x40
#define BUTTONS_MASK_NAV_R 0x20
#define BUTTONS_MASK_NAV_D 0x10
#define BUTTONS_MASK_NAV_CLICK 0x8
#define BUTTONS_MASK_DIALR_CLICK 0x4
#define BUTTONS_MASK_DIALL_CLICK 0x2
#define BUTTONS_MASK_TEMP_ALARM 0x1

int avalon_read(unsigned int address);

void avalon_write(unsigned int address, int data);

void hex_output(int value);
void debug_print(int value);
int intToBCD(int a);

int get_ms();

#endif // CLARVI_H