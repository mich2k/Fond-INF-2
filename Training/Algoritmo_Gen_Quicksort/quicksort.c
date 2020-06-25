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

int main(void) {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(*arr);
    printf("Original array: ");
    display(arr, n);
    quick_sort(arr, 0, n - 1);
    printf("Sorted array: ");
    display(arr, n);
    return EXIT_SUCCESS;
}