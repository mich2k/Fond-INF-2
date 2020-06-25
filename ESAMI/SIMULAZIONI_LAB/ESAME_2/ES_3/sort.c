
/*Nel file sort.c definire la funzione corrispondente alla seguente
dichiarazione:

extern bool BubbleSort(int *v, int v_size);

La funzione prende in input un vettore di interi v e la sua dimensione v_size e
deve ordinare in ordine crescente gli elementi di v. Se v è NULL oppure se la
dimensione del vettore non è strettamente maggiore di 0 la funzione deve
ritornare false e non modificare il vettore di input. In caso contrario la
funzione deve ritornare true al termine dell’ordinamento. La funzione deve
utilizzare l’algoritmo di ordinamento bubble sort. N.B. non sarà considerata
valida nessuna soluzione che ordini il vettore con un algoritmo di ordinamento
diverso dal bubble sort.
*/

#include <stdlib.h>
#include <stdbool.h>

extern bool BubbleSort(int* v, int v_size);

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

bool BubbleSort(int* v, int v_size) {
    if(v == NULL || v_size <=0)
        return false;
    bubble_sort(v, v_size);
    return true;
}


int main(void) {}