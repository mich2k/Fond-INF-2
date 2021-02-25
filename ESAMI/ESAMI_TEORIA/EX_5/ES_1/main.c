#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int input;
    int output;
} cavo;

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

void backrec(int k, int i, int n, int* vcurr, int* nsol, cavo* l) {
    if (i == n) {
        if (!isvalid(vcurr, k))
            return;
        for (int h = 0; h < n; h++) {
            if (h == 0 && ((l + vcurr[h])->output != (l + vcurr[h + 1])->input))
                return;
            if (h != 0 && (l + vcurr[h])->input != (l + vcurr[h - 1])->output)
                return;
        }
        (*nsol)++;
        printf("%d) ", *nsol);
        for (int h = 0; h < n; h++)
            printf("%d ", vcurr[h]);
        puts("");
        return;
    }
    for (int j = 0; j < k; ++j) {
        vcurr[i] = j;
        backrec(k, i + 1, n, vcurr, nsol, l);
    }
}

int main(void) {
    int n = 4;
    int k = 4;
    int* vcurr = malloc(n * sizeof(int));
    int nsol = 0;
    cavo l[] = {{0, 1}, {1, 2}, {2, 1}, {2, 0}};
    backrec(k, 0, n, vcurr, &nsol, l);
    free(vcurr);
    return EXIT_SUCCESS;
}