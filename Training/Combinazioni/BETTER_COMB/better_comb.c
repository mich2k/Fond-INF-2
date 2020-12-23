#include <stdio.h>
#include <stdlib.h>

void backrec(int k,int i, int n, int done, int* vcurr, int* nsol) {
    if (i == n && done != k)
        return;
    if (done == k) {
        (*nsol)++;
        printf("%d) ", *nsol);
        for (int h = 0; h < n; h++) {
            if (vcurr[h] == 1)
                printf("%d", h);
        }
        puts("");
        return;
    }
    vcurr[i] = 1;
    backrec(k,i + 1, n, done + 1, vcurr, nsol);
    vcurr[i] = 0;
    backrec(k,i + 1, n, done, vcurr, nsol);
}

int main(void) {
    int n = 10;      // COMBINAZIONI DI n ELEMENTI IN k GRUPPI
    int i = 0;
    int k = 4;
    int* vcurr = calloc(n, sizeof(int));
    int nsol = 0;
    backrec(k,0, n, 0, vcurr, &nsol);
    free(vcurr);
    return EXIT_SUCCESS;
}