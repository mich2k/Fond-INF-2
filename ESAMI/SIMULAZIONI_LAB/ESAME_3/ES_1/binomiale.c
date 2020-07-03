/*
Nel file binomiale.c definire la funzione corrispondente alla seguente
dichiarazione:

extern int Binomiale(int n, int k);

La funzione prende in input due numeri interi n e k e deve ritornare il
coefficiente binomiale calcolato utilizzando la ricorsione. Se la funzione
riceve in input un valore n minore di 0 deve ritornare -1. La formula ricorsiva
per il calcolo del coefficiente binomiale è la seguente:
*/
#include <stdlib.h>
#include <stdio.h>

extern int Binomiale(int n, int k);

int factor(int val, int r) {
    if (val == 1)
        return r;
    r *= val;
    factor(val-1,r);
}

int Binomiale(int n, int k) {
    int nom = factor(n,1);
    //int den = factor(k,1) * factor(n-k,1);
    return nom;
}

int main(void) {
    int x= Binomiale(5, 2);
    printf("%d",x);
    return EXIT_SUCCESS;
}