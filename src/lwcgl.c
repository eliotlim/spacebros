#include "lwcgl.h"

unsigned int prev_tick = 0;
int wait(void)
{
    while (get_ms() - prev_tick < TICK_DURATION)
    {
        prev_tick = prev_tick;
    }
    return prev_tick = get_ms();
}

void vid_set_pixel(int x, int y, int colour)
{
    // derive a pointer to the framebuffer described as 16 bit integers
    volatile short *framebuffer = (volatile short *)(FRAMEBUFFER_BASE);

    // make sure we don't go past the edge of the screen
    if ((x < 0) || (x > DISPLAY_WIDTH - 1))
        return;
    if ((y < 0) || (y > DISPLAY_HEIGHT - 1))
        return;

    framebuffer[x + y * DISPLAY_WIDTH] = colour;
}

void clear_screen(void)
{
    for (int x = 0; x < DISPLAY_WIDTH; x++)
    {
        for (int y = 0; y < DISPLAY_HEIGHT; y++)
        {
            vid_set_pixel(x, y, PIXEL_BLACK);
        }
    }
}