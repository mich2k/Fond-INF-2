/*
Nel file stringhe.c definire la procedura corrispondente alla seguente
dichiarazione:

extern void BacktrackStr(int n);

la procedura prende in input un intero n e deve stampare a video (standard
output), utilizzando un approccio di backtracking, tutte le possibili stringhe
di lunghezza n che è possibile costruire utilizzando le prime n lettere
minuscole dell’alfabeto inglese. L’output dovrà avere il seguente formato:

{ xx…x }, { xx…x }, { xx…x }, … { xx…x },

Se n<=0 o n>26 la funzione non deve stampare nulla. Le stringhe devono essere
stampate in ordine alfabetico.

Si consiglia di utilizzare una funzione ausiliaria per la risoluzione
dell’esercizio. N.B. Non sarà considerata valida nessuna soluzione che non
faccia uso del backtracking.

Esempio:
input: 	 n = 2
output: { aa }, { ab }, { ba }, { bb },
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern void BacktrackStr(int);

void backtrack_rec(uint32_t* vcurr, uint32_t i, uint32_t n, char* alf) {
    if (i == n) {  // caso base
        for (uint32_t k = 0; k < n; ++k)
            printf("%c", alf[vcurr[k]]);
        puts("");
        return;
    }
    for (uint32_t j = 0; j < n; ++j) {
        vcurr[i] = j;
        backtrack_rec(vcurr, i + 1, n, alf);
    }
}

void BacktrackStr(int n) {
    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    uint32_t* vcurr = malloc(n * sizeof(uint32_t));
    backtrack_rec(vcurr, 0, n, alfabeto);
    free(vcurr);
    return;
}

int main(void) {
    BacktrackStr(2);
    return EXIT_SUCCESS;
}