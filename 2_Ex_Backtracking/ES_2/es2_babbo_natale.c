#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

void BabboNatale(int p, int const *pacchi, int n, unsigned i, bool *vcurr, bool *vbest, unsigned *max, unsigned cnt, unsigned sum, unsigned *max_weight)
{
    if (i == n)
    {
        for (unsigned j = 0; j < n; j++)
        {
            if (vcurr[j] == true)
            {
                sum += pacchi[j];
                cnt++;
                if (sum > p)
                    return;
            }
        }
        if (cnt >= (*max) && sum >= (*max_weight))
        {
            (*max) = cnt;
            (*max_weight) = sum;
            for (unsigned j = 0; j < n; ++j)
                vbest[j] = vcurr[j];
        }
        return;
    }
    for (unsigned j = 0; j < 2; ++j)
    {
        vcurr[i] = j;
        BabboNatale(p, pacchi, n, i + 1, vcurr, vbest, max, 0, 0, max_weight);
    }
}

void main(void)
{
    uint32_t p = 30;
    uint32_t pacchi[] = {10, 11, 1, 3, 3, 1 , 2, 3, 7, 13};
    unsigned short n = sizeof(pacchi) / sizeof(*pacchi);
    bool *vcurr = calloc(n, sizeof(bool));
    bool *vbest = calloc(n, sizeof(bool));
    unsigned max = 0;
    unsigned max_weight = 0;
    BabboNatale(p, pacchi, n, 0, vcurr, vbest, &max, 0, 0, &max_weight);
    printf("\t");
    for (unsigned j = 0; j < n; ++j)
        fprintf(stdout, " %d ", vbest[j]);
    printf("\n\n  ---corrispondente peso pacchi--- \n\n\t");
    for (unsigned j = 0; j < n; ++j)
    {
        if (vbest[j] == true)
            fprintf(stdout, " %d ", pacchi[j]);
        else
            fprintf(stdout, " N ");
    }
    printf("\n\n\t  ---stats--- \n\n");
    fprintf(stdout, "\tPacchi trasportati: %d/%d\n\tPeso trasportato: %d/%d\n\n", max, n, max_weight, p);
    free(vcurr);
    free(vbest);
    return;
}
