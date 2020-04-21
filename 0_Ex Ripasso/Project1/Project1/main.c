#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void main(int argc, char* argv[])
{
    uint64_t a = strtol(argv[1], NULL, 10);
    uint64_t b = strtol(argv[2], NULL, 10);
    fprintf(stdout, "%lu", a > b ? a : b);
    return;
}
