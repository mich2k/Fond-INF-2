#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void backsubset(uint32_t i, uint32_t k, uint32_t n, uint32_t *vcurr)
{
    if (i == n)
    {
        for (uint32_t r = 0; r < n; ++r)
            fprintf(stdout, "%d ", vcurr[r]);
        return;
    }
    for (uint32_t j = 0; j < k; ++j)
        vcurr[i] = j;
} 

int main(void)
{
    uint32_t n = 5;
    uint32_t *v = calloc(n, sizeof(uint32_t));
    backsubset(0, n + 1, n, v);
    return EXIT_SUCCESS;
}