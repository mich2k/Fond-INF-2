/*Nel file sort.c definire la funzione corrispondente alla seguente dichiarazione:

extern bool QuickSort(int *v, int v_size, int first, int last);

La funzione prende in input un vettore di interi v, la sua dimensione v_size e due
indici first e last e deve ordinare in ordine crescente gli elementi di v che si
trovano tra l’indice first e l’indice last compresi. Se l’indice first è minore
di 0, se l’indice last è maggiore o uguale a v_size, se last è minore di first, o 
se v è NULL la funzione deve ritornare false e non modificare il vettore di input. 
In caso contrario la funzione deve ritornare true al termine dell’ordinamento. La 
funzione deve utilizzare l’algoritmo di ordinamento quicksort. 

N.B. non sarà considerata valida nessuna soluzione che ordini il vettore con un 
algoritmo di ordinamento diverso dal quicksort.*/


#include <stdlib.h>
#include <stdbool.h>

extern bool QuickSort(int *v, int v_size, int first, int last);

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}


void quick_sort(int* v, int first, int last) {
    int i, j, pivot;
    if (first < last) {
        i = first;
        j = last;
        pivot = v[(first + last) / 2];
        do {
            while (v[i] < pivot)
                i++;
            while (v[j] > pivot)
                j--;
            if (i <= j) {
                swap(&v[i], &v[j]);
                i++, j--;
            }
        } while (i <= j);
        quick_sort(v, first, j);
        quick_sort(v, i, last);
    }
}

bool QuickSort(int *v, int v_size, int first, int last){
    if(first < 0 || last >= v_size || v == NULL || first > last)
        return false;
    quick_sort(v, first, last);
    return true;
}

int main (void){
    int v[] = {7,6,32,432,2};
    QuickSort(&v, 5,0, 2);
    return EXIT_SUCCESS;
}