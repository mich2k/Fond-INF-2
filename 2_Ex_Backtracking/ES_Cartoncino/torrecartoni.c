#include "torrecartoni.h"

uint32_t *standard(const uint32_t *v, uint16_t n, unsigned int *cont) // elimina nell array gli elementi non significativi
{
    uint32_t *std = calloc(n, sizeof(uint32_t)); // ex: 0 0 1 2      ->      1 2
    for (uint16_t j = 0; j < n; ++j)
    {
        if (v[j] != false)
        {
            std[*cont] = v[j];
            *(cont) += 1;
        }
    }
    std = realloc(std, (*cont) * sizeof(uint32_t));
    return std;
}

bool check_double(const uint32_t *v, uint16_t n) // screma i sottoinsiemi eliminando apriori le soluzioni
{                                               // con elementi ripetuti
                                                // unlegit:     0011, 1111, 0101, 0221
    bool *vtest = calloc(n + 1, sizeof(bool));
    for (uint16_t i = 0; i < n; ++i)
    {
        uint32_t val = v[i];
        if ((vtest[val]) == false)
            vtest[val] = true;
        else
        {
            free(vtest);
            return false;
        }
    }
    free(vtest);
    return true;
}

bool isvalid(const cartone *c, const uint32_t *v, uint16_t n) // verifica se viene rispettato il limite del cartone
{
    if (n == 1)
        return true;
    uint32_t weight = 0;
    for (int j = n - 1; j != -1; --j)
    {
        if (j >= 0)
        {
            if (j != 0)
            {
                int lim = (c + v[j - 1])->l;
                int w = (c + v[j])->p;
                if (w > lim)
                    return false;
                weight += (c + v[j])->p;
            }
            else
            { //caso j == 0, ovvero ultimo cartone
                if (weight > (c)->l)
                    return false;
            }
        }
    }
    return true;
}

void BactrackSubset(const cartone *c, const int n, int i, uint32_t *v, uint32_t height, // funzione di backtracking
                    uint32_t *mheight, uint32_t *best, unsigned int *leng)
{
    if (i == n)
    {
        unsigned int len = 0;
        uint32_t *std_v = standard(v, n, &len);
        if (len == 0)
            return;
        if ((check_double(std_v, len)) == false)
            return;
        for (uint16_t k = 0; k < len; ++k)
            *(std_v + k) -= 1;
        if (isvalid(c, std_v, len) == true)
        {
            for (int k = len - 1; k != -1; --k)
                height += (c + std_v[k])->a;
            if (height > *mheight)
            {
                *leng = len;
                *mheight = height;
                memcpy(best,std_v, len*sizeof(uint32_t));
            }
        }

        return;
    }
    for (uint16_t j = 0; j < n+1; j++)
    {
        v[i] = j; // scelta del valore i (da 0 a 1) per il passo s (da 0 a n-1)
        BactrackSubset(c, n, i + 1, v, height, mheight, best, leng);
    }
}

void TorreCartoni(cartone *c, int n)
{
    uint32_t *v = calloc(n, sizeof(uint32_t));
    uint32_t *best = calloc(n, sizeof(uint32_t));
    uint32_t mheight = 0;
    unsigned int len;
    BactrackSubset(c, n, 0, v, 0, &mheight, best, &len);
    for (int i = len - 1; i != -1; --i)
        fprintf(stdout, "\n\t%i", best[i]);
    fprintf(stdout, "\n\tcon un altezza max di: %i\n", mheight);
    free(best);
    free(v);
}