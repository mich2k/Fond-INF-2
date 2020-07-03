/*
Nel file stringhe.c definire la procedura corrispondente alla seguente
dichiarazione:

extern void BacktrackStr(int n);
la procedura prende in input un int e deve stampare a video (stdout),
utilizzando un approccio di backtracking, tutte le possibili stringhe di
lunghezza n che è possibile costruire utilizzando le prime n lettere minuscole
dell’alfabeto inglese. L’output dovrà avere il seguente formato:

{ xx…x }, { xx…x }, { xx…x }, … { xx…x },
Se n <= 0 o n > 26 la funzione non deve stampare nulla. Le stringhe devono
essere stampate in ordine alfabetico.

Si consiglia di utilizzare una funzione ausiliaria per la risoluzione
dell’esercizio. N.B. Non sarà considerata valida nessuna soluzione che non
faccia uso del backtracking.

Esempio:

input: n = 2 output: { aa }, { ab }, { ba }, { bb },
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
extern void BacktrackStr(int n);

void rec(uint32_t* vcurr, int n, uint32_t i, char* alfa) {
    if (i == n) {
        printf("{ ");
        for (uint32_t k = 0; k < n; k += 1)
            printf("%c", alfa[vcurr[k]]);
        printf(" }, ");
        return;
    }
    // puts("");
    for (uint32_t j = 0; j < n; j += 1) {
        vcurr[i] = j;
        rec(vcurr, n, i + 1, alfa);
    }
}

void BacktrackStr(int n) {
    char alfa[] = "abcdefghijklmnopqrstuvwxyz";
    uint32_t* vcurr = malloc(n * sizeof(uint32_t));
    rec(vcurr, n, 0, alfa);
    free(vcurr);
    return;
}

int main(void) {
    BacktrackStr(2);
    return EXIT_SUCCESS;
}