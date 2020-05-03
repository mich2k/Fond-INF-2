#ifndef GIOIELLI_H
#define GIOIELLI_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codice;
    float peso;
    float prezzo;
} Gioiello;

extern Gioiello* Gioielli(const char* filename, float b, int* ret_size);

#endif  // GIOIELLI_H