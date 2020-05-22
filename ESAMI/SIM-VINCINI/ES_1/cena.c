/*
  Maria deve preparare la cena per la sua famiglia, composta da lei, il marito e
  4 figli. Ciascuno deve introdurre 700 Kcal ed ha a disposizione un elenco di N
  (costante) piatti, ciascuno caratterizzato dalla tipologia (1= primo,
  2=contorno, 3=secondo), dal valore di Kcal e dal nome. Aiutate Maria nella
  scelta della cena, mostrando a video tutte le possibili terne di piatti (uno
  solo per ciascuna categoria) che permettono di somministrare le esatte calorie
  a ciascun commensale.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
struct {
    int tipologia;
    int Kcal;
    char nome[20];
} piatto;

void backtrack(struct piatto, size_t n, size_t i, size_t k, uint32_t* vcurr) {
    if (i == n) {

        for (uint32_t j = 0; j < n; ++j)
            printf("%d ", vcurr[j]);
        puts("");
        return;
    }
    for (uint32_t r = 0; r < k; ++r) {
        vcurr[i] = r;
        backtrack(n, i + 1, k, vcurr);
    }
}

int main(void) {
    size_t k = 2;  // binario
    size_t N = 5;
    size_t n_piatti = 3;
    uint32_t* vcurr = malloc(N * 32);
    backtrack(struct x, n_piatti, 0, 2, vcurr);
}