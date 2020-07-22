// https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

// Program to print all combination of size r in an array of size n
#include <stdio.h>
#include <stdlib.h>

void comb_backtrack(const int* arr,
                    int* vcurr,
                    int start,
                    int end,
                    int index,
                    int r,
                    size_t* cont);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses comb_backtrack()
void print_combination(int n, int k, size_t* cont) {
    int* vcurr = malloc(k * sizeof(int));
    int* digits = malloc(n * sizeof(int));
    for (size_t arr_cont = 0; arr_cont < n; arr_cont += 1)
        digits[arr_cont] = arr_cont + 1;
    // Print all combination using temprary array 'vcurr[]'
    comb_backtrack(digits, vcurr, 0, n - 1, 0, k, cont);
    free(vcurr);
    free(digits);
}

/* arr[]  ---> Digit Input Array
   vcurr[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in vcurr[]
   r ---> Size of a combination to be printed */
void comb_backtrack(const int* arr,
                    int* vcurr,
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
            printf("%d ", vcurr[j]);
        printf("\n");
        return;
    }

    for (int j = start; j <= end && end - j + 1 >= k - i; j += 1) {
        vcurr[i] = arr[j];
        comb_backtrack(arr, vcurr, j + 1, end, i + 1, k, cont);
    }
}

// Driver program to test above functions
int main() {
    // int arr[] = {1, 2, 3, 4, 5, 6};
    int k = 3;
    int n = 6;
    size_t cont = 0;
    print_combination(n, k, &cont);
    return EXIT_SUCCESS;
}