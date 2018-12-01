#include "lwcgl.h"
#include "b_int.h"

int clear = 0;
int left = 0, left_prev = 0;
int right = 0, right_prev = 0;
struct b_int x = {
    .min = 0,
    .max = DISPLAY_WIDTH,
    .val = 0,
};
struct b_int y = {
    .min = 0,
    .max = DISPLAY_HEIGHT,
    .val = 0,
};

void process_input();

int game_main(void)
{

    int x_prev = 0, y_prev = 0;
    while (1)
    {

        process_input();

        if (x_prev != x.val || y_prev != y.val)
            vid_set_pixel(x.val, y.val, PIXEL_WHITE);

        if (clear)
        {
            clear_screen();
        }
    }
}

void process_input()
{
    left_prev = left;
    right_prev = right;
    left = avalon_read(PIO_ROTARY_L);
    right = avalon_read(PIO_ROTARY_R);
    clear = avalon_read(PIO_BUTTONS) & (BUTTONS_MASK_DIALL_CLICK | BUTTONS_MASK_DIALR_CLICK);

    if (left_prev != left)
    {
        if (left == 0 && left_prev == 255)
            inc(&x);
        else if (left == 255 && left_prev == 0)
            dec(&x);
        else if (left > left_prev)
            inc(&x);
        else
            dec(&x);
    }
    if (right_prev != right)
    {
        if (right == 0 && right_prev == 255)
            inc(&y);
        else if (right == 255 && right_prev == 0)
            dec(&y);
        else if (right > right_prev)
            inc(&y);
        else
            dec(&y);
    }
}