#include <stdio.h>
#include <stdint.h>

int somma(unsigned int n)
{
     if (n<=0) return -1;
     return n+somma(n-1);
    /* ricorsione */
}

int main(void)
{
    unsigned int n = 5;
    uint64_t tot = somma(n);
}
