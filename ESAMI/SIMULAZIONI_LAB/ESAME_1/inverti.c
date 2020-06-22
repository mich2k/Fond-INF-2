/*
Nel file inverti.c definire la funzione corrispondente alla seguente
dichiarazione:

extern void Inverti(int *v, int v_size);

La funzione accetta un vettore di interi (v), anche vuoto, e la sua
dimensione(v_size) e deve scambiare ricorsivamente gli elementi di
v per posizionarli in ordine inverso rispetto alla posizione iniziale.
Se, ad esempio, il vettore v contenesse gli elementi 0 1 2 3 4 5, al
termine dell’esecuzione della funzione Inverti dovrebbe contenere gli
elementi 5 4 3 2 1 0. Si consiglia l’utilizzo di una funzione ausiliaria
per realizzare la ricorsione. N.B. Non sarà considerata valida nessuna
soluzione che non faccia uso della ricorsione per scorrere gli elementi
del vettore.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern void Inverti(int* v, int v_size);

void InvertRec(int* v, int* arr, int v_size, int size, int i) {
    if (i == v_size)
        return;
    v[i] = arr[size];
    InvertRec(v, arr, v_size, size - 1, i + 1);
}

void Inverti(int* v, int v_size) {
    int* arr = malloc(4 * v_size);
    for (int i = 0; i < v_size; ++i)
        arr[i] = v[i];
    InvertRec(v, arr, v_size, v_size - 1, 0);
    free(arr);
    return;
}

int main(void) {
    int arr[] = {1, 2, 3};
    Inverti(arr, 3);
    for (int i = 0; i < v_size; ++i)
        printf("%d\n", v[i]);
    return EXIT_SUCCESS;
}