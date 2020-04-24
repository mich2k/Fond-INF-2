#include "torrecartoni.h"
#include "torrecartoni.c"

void main(void) // main / input
{
    cartone c[] = {
        {.p = 25, .a = 20, .l = 50},
        {.p = 10, .a = 10, .l = 8},
        {.p = 9, .a = 3, .l = 5},
        {.p = 5, .a = 20, .l = 200},
        {.p = 10, .a = 10, .l = 202},
        {.p = 10, .a = 10, .l = 202},
        {.p = 10, .a = 10, .l = 202},
        {.p = 10, .a = 10, .l = 202}
    };
    int n = sizeof(c) / sizeof(*c);
    TorreCartoni(c, n);
    // 4 digits 0-3          -> sol. tot 4^3=64
    //backtrack(0, n, arr);
    return;
}