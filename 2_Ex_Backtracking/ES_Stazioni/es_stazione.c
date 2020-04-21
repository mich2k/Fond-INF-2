#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    bool *vbest;
    float costo;
    bool flag;
} soluzione;

void arr_print(soluzione *best, size_t size)
{
    for (uint8_t j = 0; j < size; ++j)
    {
        if (best->vbest[j] == 0)
            continue;
        printf(" %d", j);
    }
}

void bkt_stazioni(double *distanze, double *prezzi, uint8_t i, float consumo,
                  uint8_t capienza, uint8_t n, float autonomia, bool *vcurr, soluzione *best, uint16_t m, uint16_t distsofar)
{
    float costo = 0;
    distsofar = 0;
    if (i == n)
    {
        for (uint8_t j = 0; j < n; ++j)
        {
            distsofar+=distanze[j];
            autonomia -= distanze[j] * consumo;
            if (autonomia < 0)
                return;
            if (vcurr[j] == true)
            {
                costo += (capienza - autonomia) * prezzi[j];
                //costo += autonomia < 0 ? ((capienza + abs(autonomia)) * prezzi[j]) : (capienza - autonomia) * prezzi[j];
                autonomia = capienza;
            }
        }
        if ((best->flag == false && i == n && costo != 0) || (best->costo >= costo && distsofar >= m))
        {
            best->costo = costo;
            best->flag = true;
            for (uint8_t j = 0; j < n; ++j)
                best->vbest[j] = vcurr[j];
        }
        return;
    }
    for (uint8_t j = 0; j < 2; ++j)
    {
        vcurr[i] = j;
        bkt_stazioni(distanze, prezzi, i + 1, consumo, capienza, n, autonomia, vcurr, best, m, distsofar);
    }
}
void StazioniServizio(double m, int n, double *d, double *p)
{
    uint8_t capienza = 30;
    float autonomia = capienza;
    bool *vcurr = calloc(1, n);
    float consumo = 0.05;
    soluzione *best = malloc(sizeof(soluzione));
    best->vbest = calloc(1, n);
    best->costo = 0;
    best->flag = false;
    bkt_stazioni(d, p, 0, consumo, capienza, n, autonomia, vcurr, best,m,0);
    puts("");
    uint8_t r = 0;
    for (uint8_t j = 0; j < n; ++j)
    {
        if (best->vbest[j] == true)
            ++r;
    }
    if (r == 0)
    {
        fprintf(stdout, "Non esistono soluzioni");
        return;
    }
    printf("Soluzione ottimale: ");
    arr_print(best, n);
    printf("\ncon un costo complessivo di %3.f\nconsiderando ", best->costo);
    for (uint8_t j = 0, r = 0; j < n; ++j)
    {
        if (best->vbest[j] == true)
            ++r;
        if (j == n - 1)
            printf("%d", r);
    }
    printf(" stazioni su %d\n\n", n);
    free(vcurr);
    free(best->vbest);
    free(best);
}
void main(void)
{
    double distanze[] = {260, 284, 308, 332, 356};
    double prezzi[] = {35, 35, 33, 29, 23};
    uint16_t n = sizeof(distanze) / sizeof(*distanze), m = 1540;
    StazioniServizio(m, n, distanze, prezzi);
    return;
}
