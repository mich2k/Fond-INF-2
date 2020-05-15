
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void display(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    puts("");
}

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

/**
 *! peggio del naive sort, confronta coppie di elementi alla volta
 *! spingendo in fondo i valori più grandi
 */
int main(void) {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(*arr);
    printf("Original array: ");
    display(arr, n);
    bubble_sort(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return EXIT_SUCCESS;
}