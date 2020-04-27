#include "torrecartoni.h"

typedef struct{
    unsigned a;
    int *c_ids; // Id cartoni --> 0, 2, 1 significa che la torre è costruita con i pacchi in 
                // posizione 0, 2 e 1 e in particolare il pacco 0 è in cima alla torre e quello
                // di indice 1 si trova alla base
    int size;
} torre;

void Backtracking(cartone *c, int n, int i, torre *vcurr, torre *vbest, bool *usati)
{
    if (i == n) {
        for(int i = 0; i < n; ++i){
           // printf("%i", vcurr->(c_idsi)+i);
        }
        puts("");
        if (vcurr->a > vbest->a) {
            vbest->a = vcurr->a;
            vbest->size = vcurr->size;
            memcpy(vbest->c_ids, vcurr->c_ids, vcurr->size * sizeof(int));
        }

        return;
    }

    unsigned p = 0; 
    for (int j = 0; j < vcurr->size; ++j) {
        p += c[vcurr->c_ids[j]].p;
    }

    for (int j = 0; j < n; ++j) {
        if (!usati[j]) {
            if (p <= c[j].l) {
                vcurr->a += c[j].a;
                vcurr->c_ids[vcurr->size] = j;
                vcurr->size++;
                usati[j] = 1;

                Backtracking(c, n, i + 1, vcurr, vbest, usati);

                vcurr->a -= c[j].a;
                vcurr->size--;
                usati[j] = 0;

            }
            else {
                Backtracking(c, n, n, vcurr, vbest, usati);
            }
        }
    }

    
}


void TorreCartoni(cartone *c, int n)
{
    bool *usati = calloc(n, sizeof(n));
    torre vcurr = { .a = 0,.c_ids = malloc(n * sizeof(int)),.size = 0 };
    torre vbest = { .a = 0,.c_ids = malloc(n * sizeof(int)),.size = 0 };

    Backtracking(c, n, 0, &vcurr, &vbest, usati);

    for (int i = 0; i < vbest.size; ++i) {
        printf("%4i\n", vbest.c_ids[i]);
    }
    printf("Altezza: %i cm\n", vbest.a);

    free(usati);
    free(vcurr.c_ids);
    free(vbest.c_ids);
}

int main(void) // main / input
{
    cartone c[] = {
        {.p = 25, .a = 20, .l = 50},
        {.p = 10, .a = 10, .l = 8},
        {.p = 9, .a = 3, .l = 5},
        {.p = 5, .a = 20, .l = 200},
        {.p = 10, .a = 10, .l = 202},
    };
    int n = sizeof(c) / sizeof(*c);
    TorreCartoni(c, n);
    // 4 digits 0-3          -> sol. tot 4^3=64
    //backtrack(0, n, arr);
    return EXIT_SUCCESS;
}