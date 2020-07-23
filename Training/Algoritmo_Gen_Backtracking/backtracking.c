#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void backsubset(uint32_t *nsol, uint32_t i, uint32_t k, uint32_t n, uint32_t *vcurr)
{
    if (i == n)
    {
        (*nsol)++;
        fprintf(stdout, "%d) ", *nsol);
        for (uint32_t r = 0; r < n; ++r)
            fprintf(stdout, "%d ", vcurr[r]);
        puts("");
        return;
    }
    for (uint32_t j = 0; j < k; ++j)
    {
        vcurr[i] = j;
        backsubset(nsol, i + 1, k, n, vcurr);
    }
}

int main(void)
{
    uint32_t n = 4, nsol = 0;
    uint32_t k = 8;
    /*
        VALORI POSSIBILI NOTEVOLI DI k:
            -   (n+1)   stamperà tutte le disposizioni con ripetizione, ovvero  k^(n) soluzioni
            -   2       stamperà soluzioni binarie (1/0), del tipo presenza/assenza
            -   k       in caso volessimo rappresentare (k-1) numeri in uno spazio di n, dovremo dare un input di x
                        EX: 
                          INPUT:  n=  2, k=4:

                            1)   0   0 
                            2)   0   1 
                            3)   0   2 
                            4)   0   3 
                            5)   1   0 
                            6)   1   1 
                            7)   1   2 
                            8)   1   3 
                            9)   2   0 
                            10)  2   1 
                            11)  2   2 
                            12)  2   3 
                            13)  3   0 
                            14)  3   1 
                            15)  3   2 
                            16)  3   3 

    */

    uint32_t *v = calloc(n, sizeof(uint32_t));
    backsubset(&nsol, 0, k, n, v);
    return EXIT_SUCCESS;
}