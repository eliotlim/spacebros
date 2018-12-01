#ifndef B_INT_H
#define B_INT_H

// Define struct to contain bounded integers
struct b_int
{
    int min;
    int max;
    int val;
};

void inc(struct b_int *i);
void dec(struct b_int *i);

#endif // B_INT_H