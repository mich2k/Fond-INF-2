#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Numero;
    float CostoUnitario;
    float Guadagno;
} Azione;

// ! SOLUZIONE ESAUSTIVA

void backrec(int k,
             int i,
             int n,
             int done,
             int* vcurr,
             Azione* a,
             int budget,
             float* best_ratio,
             int* vbest,
             int* len_best) {
    if (i == n && done != k)
        return;
    if (done == k) {
        float curr_ratio;
        int sum = 0;
        for (int h = 0; h < n; h++) {
            if (vcurr[h]) {
                if (sum + ((a + h)->Guadagno) < budget) {
                    sum += (a + h)->Guadagno;
                    curr_ratio += (a + h)->Numero * (a + h)->CostoUnitario;
                } else
                    return;
            }
        }
        curr_ratio = sum / curr_ratio;
        if (curr_ratio > *best_ratio) {
            *len_best = k;
            printf("Migliori potenziali: ");
            for (int h = 0, j = 0; h < n; h++) {
                if (vcurr[h]) {
                    printf(" %d", h);
                    vbest[j++] = h;
                }
            }
            printf(" -->  %f", curr_ratio);
            puts("");
        }
        puts("");
        return;
    }
    vcurr[i] = 1;
    backrec(k, i + 1, n, done + 1, vcurr, a, budget, best_ratio, vbest,
            len_best);
    vcurr[i] = 0;
    backrec(k, i + 1, n, done, vcurr, a, budget, best_ratio, vbest, len_best);
}

Azione* input(int* n) {
    Azione* a = NULL;
    FILE* f = fopen("/home/mich/Scrivania/NEW-FDI2/ESAMI/EX_4/ES_1_ESAUSTIVA/azioni.dat",
                    "r");  // assumo lettura tradotta
    if (ferror(f) || !f)
        return NULL;
    size_t i = 0, ret;
    while (1) {
        if (ferror(f) || feof(f))
            break;
        a = realloc(a, (i + 1) * sizeof(Azione));
        ret = fscanf(f, "%d %f %f", &(a + i)->Numero, &(a + i)->CostoUnitario,
                     &(a + i)->Guadagno);
        if (ret == 3)
            printf("%d %.1f %.1f\n", (a + i)->Numero, (a + i)->CostoUnitario,
                   (a + i)->Guadagno);
        i++;
    }
    *n = i - 1;
    puts("");
    fclose(f);
    return a;
}

int main(void) {
    int n, len_best = 0;
    Azione* a = input(&n);
    int i = 0, k = n;
    float best_ratio = 0;
    int* vcurr = calloc(n, sizeof(int));
    int* vbest = calloc(n, sizeof(int));
    for (; k > 1; k--)
        backrec(k, 0, n, 0, vcurr, a, 4000, &best_ratio, vbest, &len_best);
    printf("La soluzione ESAUSTIVA E\': ");
    for (size_t i = 0; i < len_best; i++)
        printf("%d ", vbest[i]);
    puts("");
    free(vcurr);
    free(vbest);
    free(a);
    return EXIT_SUCCESS;
}