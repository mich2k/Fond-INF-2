#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void display(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    puts("");
}

void insertion_sort(int* arr, int n) {
    int i, j, key;
    for(i = 0; i < n; i++) {
        j = i - 1;
        key = arr[i];
        /* Move all elements greater than key to one position */
        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        /* Find a correct position for key */
        arr[j + 1] = key;
    }
}

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