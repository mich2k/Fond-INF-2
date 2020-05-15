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

void naive_sorting(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}
/**
 * ! blocca un pivot che viene
 * ! operativamente incrementato
 */

int main(void) {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(*arr);
    printf("Original array: ");
    display(arr, n);
    naive_sorting(arr, n);
    printf("Sorted array: ");
    display(arr, n);
    return EXIT_SUCCESS;
}