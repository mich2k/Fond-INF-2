#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int* Monete(int* t, int size, int b) {
    if (b <= 0)
        return NULL;
    int* ris = calloc(size, sizeof(int));
    uint32_t sum = 0;
    for (int i = 0; i < size; i++) {  // scorre tutte le monete possibili
        while (sum + t[i] <=
               b) {  // vede fino a quanto può usare la moneta corrente
            ris[i] += 1;
            sum += t[i];
        }
    }
    // printf("%d", sum);
    return ris;
}

int main(void) {
    int v[] = {50, 20, 10, 5, 2, 1};
    int n = sizeof(v) / sizeof(*v);
    int* ris = Monete(v, n, 164);
    for (uint32_t j = 0; j < n; ++j)
        printf("%d ", *(ris + j));
    return EXIT_SUCCESS;
}

/*
    è necessario sia già ordinato in modo decrescente
    complessità da non ordinato O(nlogn)
    complessità da ordinato O(n)
*/