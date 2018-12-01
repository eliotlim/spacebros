#ifndef CLARVI_H
#define CLARVI_H

#include "asmfunctions.h"

#define TICKS_SEC 50000000
#define TIMER_MS 0x04000400

void hex_output(int value);
void debug_print(int value);
int  intToBCD(int a);

int  get_ms();

#endif // CLARVI_H