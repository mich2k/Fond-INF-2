#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

void Ombrelloni(unsigned int, unsigned int, unsigned, bool *, unsigned *);
uint32_t pot(uint32_t, uint32_t);

uint32_t pot(uint32_t x, uint32_t y)
{
    while (y > 1)
        return x * pot(x, --y);
}

void main(void)
{
    unsigned int n = 4, k = 2;
    bool *vcurr = calloc(n, sizeof(bool));
    unsigned soluz = 1;
    Ombrelloni(n, 0, k, vcurr, &soluz);
    free(vcurr);
    return;
}

void Ombrelloni(unsigned int n, unsigned i, unsigned int k, bool *vcurr, unsigned *nsol)
{
    if (i == n)
    { // stampa soluzione
        // NB: LA SOLUZIONE ANDRA SOLO NEI PRIMI N
        // SLOT DELL ARRAY -> ALLOCA n*sizeof(bool) SOLAMENTE
        short cont = 0;
        for (unsigned j = 0; j < n; ++j)
        {
            if (n - j + 1 < cont)
                return;
            if (vcurr[j] == true)
            {
                ++cont;
                if (j != 0 && vcurr[j - 1] == true)
                    return;
            }
        }
        if (cont != k)
            return;
        printf("%d- ", *nsol);
        (*nsol)++;
        for (int j = 0; j < n; j++)
        {
            printf("%d ", vcurr[j]);
        }
        puts("");
        return;
    }

    for (unsigned j = 0; j < k; ++j)
    {
        vcurr[i] = j;
        Ombrelloni(n, i + 1, k, vcurr, nsol); // ATTENZIONE: SCRIVERE 'i+1' NON i++ || ++1 NON FUNZIONA, SEGM. FAULT
    }
}

// ALTERNATIVAMENTE:
/* CONTROINDICATO QUANDO SI HA UN k ELEVATO
        vcurr[i] = 0;
        Ombrelloni(n, i + 1, k, vcurr, nsol);
        vcurr[i] = 1;
        Ombrelloni(n, i + 1, k, vcurr, nsol);
    
    */

// Ombrelloni(n, i + 1, k, vcurr, nsol);

/*void BacktrackTutte(int n, int i, int k, int vcurr[], int *nsol)
{
    if (i == n)
    { // stampa soluzione
        printf("%d) ", *nsol);
        (*nsol)++;
        for (int j = 0; j < n; j++)
        {
            printf("%d ", vcurr[j]);
        }
        printf("\n");
        return;
    }
    for (int j = 0; j < k; j++)
    {
        vcurr[i] = j; // scelta del valore j (da 0 a k-1)
        // per il passo i (da 0 a n-1)
        BacktrackTutte(n, i + 1, k, vcurr, nsol);
    }
}*/
