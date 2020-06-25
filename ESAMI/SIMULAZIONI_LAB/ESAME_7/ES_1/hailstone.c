/*
Dato un numero nnn positivo la sequenza di Hailstone, definita dal matematico
tedesco Lothar Collatz, si ottiene a partire da nnn procedendo come segue:

Se n è pari il prossimo elemento della sequenza si ottiene facendo n/2
Se n è dispari l'elemento successivo è dato da 3*n + 1
Il procedimento si ripete per il nuovo n. Ad esempio, la sequenza ottenuta a
partire da n = 5 è la seguente: 5, 16, 8, 4, 2, 1, 4, 2, 1,.... O ancora, se n =
11 abbiamo: 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1, 4, 2, 1,....
Come si può notare, una volta arrivati ad 1 la sequenza si ripete all'infinito.

Nel file hailstone.c definire la funzione corrispondente alla seguente
dichiarazione:

extern size_t Hailstone(int n);
La funzione prende in input un numero n e deve stampare a video (stdout) la
sequenza di Hailstone costruita ricorsivamente a partire da n. La funzione deve
interrompersi quando viene incontrato il primo 1 della sequenza e deve ritornare
il numero di elementi che compongono la sequenza stessa.

Il formato dell'output deve essere il seguente: ogni elemento fatta eccezione
per l'ultimo, deve essere seguito dai caratteri <virgola> e <spazio>.

Se il valore n passato alla funzione è minore o uguale di zero la funzione non
deve stampare nulla e deve ritornare 0.
*/

#include <stdio.h>
#include <stdlib.h>

extern size_t Hailstone(int n);

size_t HailstoneRec(int n, size_t* t) {
    ++(*t);
    printf("%d ", n);
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return HailstoneRec(n / 2, t);
    else
        return HailstoneRec(3 * n + 1, t);
}

size_t Hailstone(int n) {
    if(n<=0)
        return 0;
    size_t t = 0;
    HailstoneRec(n, &t);
    return t;
}

int main(void) {
    printf("\n -> %d", (int)Hailstone(5));
    return EXIT_SUCCESS;
}