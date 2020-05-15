#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void display(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    puts("");
}

void insertion_sort(int* arr, int n) {
    for (int i = 1; i <= n - 1; ++i) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(&arr[j], &arr[j - 1]);
            j -= 1;
        }
    }
}
/**
 * ! posiziona ogni elemento nella
 * ! posizione giusta alla i esima iterazione
*/

int main(void) {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(*arr);
    printf("Original array: ");
    display(arr, n);
    insertion_sort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return EXIT_SUCCESS;
}