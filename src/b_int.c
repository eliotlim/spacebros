#include "b_int.h"

void inc(struct b_int *i)
{
    if (i->val + 1 <= i->max)
        i->val++;
}
void dec(struct b_int *i)
{
    if (i->val - 1 >= i->min)
        i->val--;
}