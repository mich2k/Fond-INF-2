#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void display(int* arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    puts("");
}

void _merge(int* v, int i1, int i2, int last, int size) {
    int* vout = malloc(sizeof(int) * size);
    int i = i1, j = i2, k = i1;
    while (i <= i2 - 1 && j <= last) {
        if (v[i] < v[j])
            vout[k] = v[i++];
        else
            vout[k] = v[j++];
        k++;
    }
    while (i <= i2 - 1) {
        vout[k] = v[i++];
        k++;
    }
    while (j <= last) {
        vout[k] = v[j++];
        k++;
    }
    for (i = i1; i <= last; i++)
        v[i] = vout[i];
    free(vout);
}

void mergeSort(int* v, int first, int last, int size) {
    int mid;
    if (first < last) {
        mid = (last + first) / 2;
        mergeSort(v, first, mid, size);     // partizion
        mergeSort(v, mid + 1, last, size);  // partizion
        _merge(v, first, mid + 1, last, size);  // merge
    }
}

int main(void) {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(*arr);
    printf("Original array: ");
    display(arr, n);
    mergeSort(arr, 0, n - 1, n);
    printf("Sorted array: ");
    display(arr, n);
    return EXIT_SUCCESS;
}