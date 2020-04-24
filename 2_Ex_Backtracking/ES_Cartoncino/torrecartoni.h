#ifndef TORRE_CARTONI_H
#define TORRE_CARTONI_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} cartone;

extern void TorreCartoni(cartone *, int);
extern void BactrackSubset(const cartone *, const int, int i, uint32_t*, uint32_t, uint32_t*, uint32_t*, unsigned int*);
extern uint32_t *standard(const uint32_t *, uint16_t, unsigned int*);
extern bool check_double(const uint32_t *, uint16_t );
extern bool isvalid(const cartone *, const uint32_t *, uint16_t n);



#endif // TORRE_CARTONI_H
