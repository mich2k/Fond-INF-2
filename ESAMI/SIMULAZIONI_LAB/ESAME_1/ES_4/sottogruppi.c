/*
        Nel file sottogruppi.c definire la funzione corrispondente alla seguente
        dichiarazione:

        extern int Sottogruppi(const char *filename, int k);

        La funzione prende in input il nome di un file di testo (filename) e un
   intero k. Il file contenente i nomi degli alunni di una classe separati da
   \n. Il file contiene in totale n nomi (senza spazi) i quali sono costituiti
   al massimo da 19 caratteri. Il numero n non è noto a priori, ma si deve
   determinare leggendo il file. La funzione deve aprire il file e leggerne il
   contenuto e, utilizzando un algoritmo di backtracking ricorsivo, individuare
   tutti i possibili sottogruppi di K studenti con i seguenti vincoli:

           1. due nomi che iniziano con la stessa lettera non devono mai
   appartenere allo stesso sottogruppo. Esempio: Andrea e Aldo hanno la stessa
   iniziale “A”, quindi non possono appartenere allo stesso sottogruppo.
           2. due nomi con iniziali consecutive non devono mai appartenere allo
   stesso gruppo. Esempio: Bianca e Alfredo hanno iniziali consecutive
   nell’alfabeto, quindi non possono mai appartenere allo stesso sottogruppo.
           3. l’ordine è significativo. Esempio (k = 2) i gruppi { Andrea, Carlo
   } e { Carlo, Andrea } sono da considerarsi gruppi distinti e quindi
   dovrebbero comparire entrambi nella soluzione.

        La funzione deve stampare su standard output tutti i possibili
   sottogruppi, uno per riga con il seguente formato:

        { Nome1, Nome2, …, NomeK }

        La funzione deve quindi ritornare il numero di soluzioni trovate. Se non
   è possibile aprire il file o se il valore k in input è minore o uguale a 0 o
        maggiore di n la funzione deve ritornare -1.

        Si consiglia di utilizzare una funzione ausiliaria per implementare il
        backtracking. Si consiglia inoltre di leggere i dati da file fuori dalla
        funzione ricorsiva.
*/

extern int Sottogruppi(const char*, int);

#define NAME_LEN 19

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isvalid(uint32_t* vcurr, int size) {
    bool* check = calloc(10, sizeof(bool));
    for (uint32_t i = 0; i < size; i += 1) {
        if (check[vcurr[i]]) {
            free(check);
            return false;
        }
        check[vcurr[i]] = true;
    }
    free(check);
    return true;
}

bool req_check(uint32_t* v, char** nomi, int n) {
    for (uint32_t i = 0; i < n; ++i) {
        char lett = nomi[v[i]][0];
        for (uint32_t j = 0; j < n; ++j) {
            char new_lett = nomi[v[j]][0];
            if (i == j)
                continue;
            if (new_lett == lett || ((int)new_lett == (int)lett - 1) ||
                ((int)new_lett == (int)lett + 1))
                return false;
        }
    }
    return true;
}

void backtrack(uint32_t i,
               uint32_t k,
               uint32_t n,
               uint32_t* vcurr,
               char** nomi,
               uint32_t* nsol) {
    if (i == n) {
        if (!isvalid(vcurr, n))
            return;
        if (!req_check(vcurr, nomi, n))
            return;
        for (uint32_t r = 0; r < n; ++r)
            fprintf(stdout, "%s ", nomi[vcurr[r]]);
        puts("");
        (*nsol)++;
        return;
    }
    for (uint32_t j = 0; j < k; ++j) {
        vcurr[i] = j;
        backtrack(i + 1, k, n, vcurr, nomi, nsol);
    }
}

int Sottogruppi(const char* filename, int k) {
    if (k <= 0)
        return -1;
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        return -1;
    char** nomi = NULL;
    uint32_t nsol = 0;
    uint32_t n = 0;
    char* tmp = malloc(NAME_LEN * sizeof(char));
    while (true) {
        if (feof(f) || ferror(f))
            break;
        fscanf(f, "%s", tmp);
        if (n == 0 || (n > 0 && strcmp(tmp, nomi[n - 1]) != 0)) {
            if ((strlen(tmp) != 0 && tmp != NULL)) {
                ++n;
                nomi = realloc(nomi, sizeof(*nomi) * n);
                *(nomi + (n - 1)) = malloc(sizeof(char) * NAME_LEN);
                strcpy(nomi[n - 1], tmp);
            }
        }
    }
    if (k > n) {
        free(tmp);
        fclose(f);
        for (uint32_t dealloc = 0; dealloc < n; dealloc++)
            free(nomi[dealloc]);
        free(nomi);
        return -1;
    }
    free(tmp);
    uint32_t* v = calloc(n, sizeof(uint32_t));
    backtrack(0, n, k, v, nomi, &nsol);
    for (uint32_t dealloc = 0; dealloc < n; dealloc++)
        free(nomi[dealloc]);
    free(nomi);
    fclose(f);
    return nsol;
}

int main(void) {
    int x = Sottogruppi(
        "/home/mich/Scrivania/Fond-INF-2/ESAMI/SIMULAZIONI_LAB/ESAME_1/ES_4/"
        "es4_input1.inp",
        2);
    printf("%d\n", x);
    return EXIT_SUCCESS;
}