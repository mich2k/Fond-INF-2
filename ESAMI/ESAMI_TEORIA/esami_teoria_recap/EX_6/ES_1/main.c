#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tipologia;
    int Kcal;
    char nome[20];
} piatto;

void backrec(int k, int i, int n, int done, int* vcurr, int* nsol, piatto* piatti, int limit) {
    if (i == n && done != k)
        return;
    if (done == k) {
        size_t typ_check = 1, kcal_sum =0;
        for (int h = 0; h < n; h++) {
            if (vcurr[h] == 1){
                typ_check *= (piatti+h)->tipologia;
                kcal_sum += (piatti+h)->Kcal;
            }
        }
        if(typ_check != 6 || kcal_sum > 700)
            return;
        (*nsol)++;
        printf("\n%d) ", *nsol);
        for(int h = 0; h < n; h++){
            if(vcurr[h])
                printf("\n ID: %d, NOME: %s, KCAL: %d, TIP: %d", h, (piatti+h)->nome, (piatti+h)->Kcal, (piatti+h)->tipologia);
        }
        puts("");
        return;
    }
    vcurr[i] = 1;
    backrec(k, i + 1, n, done + 1, vcurr, nsol, piatti, limit);
    vcurr[i] = 0;
    backrec(k, i + 1, n, done, vcurr, nsol,piatti,limit);
}

int main(void) {
    piatto piatti[] = {{1, 200, "pasta san gennaro"}, {2, 100, "carne posillipo"}, {1, 100, "pasta e vongole"},
                       {2, 100, "salsiccia e friarielli dal vomero"}, {1, 220, "riso in bianco con glutammato monosodico"}, {2, 300, "sangue di san gennaro"},
                       {3, 500, "olio di palma grezzo"}};
    int nsol = 0, k = 3, n = 10;
    int* vcurr = malloc(sizeof(int) * n);
    backrec(k, 0, n, 0, vcurr, &nsol,piatti,700);
    return EXIT_SUCCESS;
}