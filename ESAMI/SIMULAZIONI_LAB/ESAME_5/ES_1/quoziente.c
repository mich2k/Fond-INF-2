#include <stdlib.h>
extern int Quoziente(size_t x, size_t y);

void quoz_rec(size_t x, size_t y, int* ris) {
    if (x < y)
        return;
    *ris += 1;
    quoz_rec(x - y, y, ris);
}

int Quoziente(size_t x, size_t y) {
    if (y <= 0)
        return -1;
    int ris = 0;
    quoz_rec(x, y, &ris);
    return ris;
}

int main(void) {
    size_t x = 81, y = 9;
    printf("\n%d\n", Quoziente(x, y));
    return EXIT_SUCCESS;
}