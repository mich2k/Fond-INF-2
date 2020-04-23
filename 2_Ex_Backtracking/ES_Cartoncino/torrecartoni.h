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

extern void TorreCartoni(cartone *c, int n);
extern void BactrackSubset(const cartone *c, const int n, int i, uint32_t *v, uint32_t height, uint32_t *mheight, uint32_t *best, unsigned int *leng);
extern uint32_t *standard(const uint32_t *v, uint16_t n, unsigned int *cont);
extern bool check_double(const uint32_t *v, uint16_t n);
extern bool isvalid(const cartone *c, const uint32_t *v, uint16_t n);



#endif // TORRE_CARTONI_H
