#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isvalid(int* vcurr, int size) {
    bool* check = calloc(10, sizeof(bool));
    for (int i = 0; i < size; i += 1) {
        if (check[vcurr[i]]) {
            free(check);
            return false;
        }
        check[vcurr[i]] = true;
    }
    free(check);
    return true;
}

void backrec(int k, int i, int n, int* vcurr, int* nsol) {
    if (i == n) {
        if(!isvalid(vcurr,k))
            return;
        (*nsol)++;
        printf("%d) ", *nsol);
        for (int h = 0; h < n; h++) {
            printf("%d", vcurr[h]);
        }
        puts("");
        return;
    }
    for (int j = 0; j < k; ++j) {
        vcurr[i] = j;
        backrec(k, i + 1, n, vcurr, nsol);
    }
}

int main(void) {
    int n = 4;  // COMBINAZIONI DI n ELEMENTI IN k GRUPPI
    int i = 0;
    int k = 3;
    int* vcurr = calloc(n, sizeof(int));
    int nsol = 0;
    backrec(k, 0, n,vcurr, &nsol);
    free(vcurr);
    return EXIT_SUCCESS;
}