#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern void GolaCresta(size_t n);

void backtrack(uint32_t* vcurr, size_t n, size_t i) {
    if (i == n) {
        for (size_t j = 0; j < n; j += 1) {
            if (j + 2 >= n)
                break;
            if (!((vcurr[j] < vcurr[j + 1] && vcurr[j + 2] < vcurr[j + 1]) ||
                  (vcurr[j] > vcurr[j + 1] && vcurr[j + 1] < vcurr[j + 2])))
                return;
        }
        for (size_t j = 0; j < n; j += 1)
            printf("%d ", vcurr[j]);
        puts("");
        return;
    }
    for (size_t k = 0; k < 3; k += 1) {
        vcurr[i] = k;
        backtrack(vcurr, n, i + 1);
    }
}

void GolaCresta(size_t n) {
    uint32_t* vcurr = malloc(n * sizeof(uint32_t));
    backtrack(vcurr, n, 0);
    free(vcurr);
    return;
}

int main(void) {
    GolaCresta(4);
    return EXIT_SUCCESS;
}
