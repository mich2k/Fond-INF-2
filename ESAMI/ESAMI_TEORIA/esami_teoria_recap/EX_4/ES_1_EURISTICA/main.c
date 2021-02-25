#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Numero;
    float CostoUnitario;
    float Guadagno;
} Azione;

// ! SOLUZIONE EURISTICA
// !!! SICCOME NELLE TRACCE DI VINCINI IL PROBLEMA MAGGIORE E\' DECIFRARE LA
// TRACCIA IN QUESTA TRACCIA NON SI CAPISCE SE INTENDE LA MIGLIOR COMBINAZIONE
// DI AZIONI O LA SEMPLICE SCELTA DI UN PACCHETTO RISPETTO LE ALTRE


Azione* input(int* n) {
    Azione* a = NULL;
    FILE* f = fopen("/home/mich/Scrivania/NEW-FDI2/ESAMI/EX_4/ES_1/azioni.dat",
                    "r");  // assumo lettura tradotta
    if (ferror(f) || !f)
        return NULL;
    size_t i = 0, ret;
    while (1) {
        if (ferror(f) || feof(f))
            break;
        a = realloc(a, (i + 1) * sizeof(Azione));
        ret = fscanf(f, "%d %f %f", &(a + i)->Numero, &(a + i)->CostoUnitario,
                     &(a + i)->Guadagno);
        if (ret == 3)
            printf("%d %.1f %.1f\n", (a + i)->Numero, (a + i)->CostoUnitario,
                   (a + i)->Guadagno);
        i++;
    }
    *n = i - 1;
    puts("");
    fclose(f);
    return a;
}

int greedy(Azione* a, int n, int budget) {
    int sum = 0, best = -1;
    float best_app = -1, curr_app;
    for (int i = 0; i < n; i++) {
        curr_app =
            (a + i)->Guadagno / ((a + i)->Numero * (a + i)->CostoUnitario);
        printf(" %d app: %f \n", i, curr_app);
        if (sum + (a + i)->Numero * (a + i)->CostoUnitario <= budget &&
            curr_app > best_app) {
            best_app = curr_app;
            best = i;
        }
    }
    printf("\nBest Ratio -- > %f", best_app);
    return best;
}

int main(void) {
    int n;
    Azione* a = input(&n);
    int budget = 1000;
    int best = greedy(a, n, budget);
    printf("\nLa soluzione ESAUSTIVA E\': %d\nOvvero: \n %d\n %.2f\n %.2f\n", best, (a+best)->Numero, (a+best)->CostoUnitario, (a+best)->Guadagno);
    puts("");
    free(a);
    return EXIT_SUCCESS;
}