// https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

// Program to print all combination of size r in an array of size n
#include <stdio.h>
#include <stdlib.h>

void combinationUtil(int arr[],
                     int data[],
                     int start,
                     int end,
                     int index,
                     int r,
                     size_t* cont);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int k, size_t* cont) {
    int *data=malloc(n* sizeof(int));

    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n - 1, 0, k, cont);
    free(data);
}

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(int arr[],
                     int data[],
                     int start,
                     int end,
                     int i,
                     int k,
                     size_t* cont) {
    // Current combination is ready to be printed, print it
    if (i == k) {
        (*cont)++;
        printf("%zu)\t", *cont);
        for (int j = 0; j < k; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    // replace i with all possible elements. The condition
    // "end-i+1 >= r-i" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int j = start; j <= end && end - j + 1 >= k - i; j+=1) {
        data[i] = arr[j];
        combinationUtil(arr, data, j + 1, end, i + 1, k, cont);
    }
}

// Driver program to test above functions
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int k = 3;
    size_t cont = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, n, k, &cont);
}