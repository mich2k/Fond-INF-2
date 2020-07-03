/*
Nel file binomiale.c definire la funzione corrispondente alla seguente
dichiarazione:

extern int Binomiale(int n, int k);

La funzione prende in input due numeri interi n e k e deve ritornare il
coefficiente binomiale calcolato utilizzando la ricorsione. Se la funzione
riceve in input un valore n minore di 0 deve ritornare -1. La formula ricorsiva
per il calcolo del coefficiente binomiale è la seguente:
*/
#include <stdio.h>
#include <stdlib.h>

extern int Binomiale(int n, int k);

void factor(int val, int* r) {
    if (val == 1)
        return;
    *(r) *= val;
    factor(val - 1, r);
}

int Binomiale(int n, int k) {
    if (n < 0)
        return -1;
    if (k > n || k < 0)
        return 0;
    if (k == 0 || k == n)
        return 1;
    int nom = 1, den_1 = 1, den_2 = 1;
    factor(n, &nom);
    factor(k, &den_1);
    factor((n - k), &den_2);
    return nom / (den_1 * den_2);
}

int main(void) {
    int x = Binomiale(2, 3);
    printf("%d", x);
    return EXIT_SUCCESS;
}