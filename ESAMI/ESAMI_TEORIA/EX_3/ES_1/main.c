#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
l Prof. Vincini dispone di un archivio di esercizi d’esame, costruito in
quindici anni di appelli.Ogni anno si sono svolti 6 appelli, ed ogni appello
contiene 4 diverse domande, ciascuna riferita ad un argomento d’esame.Ogni
gruppo  di  domande è  numerata  in  modo progressivo  da  1  a  N,  ed  ogni
compito  è  costituito esattamente da 4 domande, una per ciascuna
tipologia.Scrivere una procedura che mostri a video tutti le possibili prove
d’esame distinte che si possono costruire inserendo una domanda per ciascuna
delle 4 categorie.

*/
void backrec(int k, int i, int n, int done, int* vcurr, int* nsol) {
    if (i == n && done != k)
        return;
    if (done == k) {
        int r = 0;
        for (int h = 0; h < n; h++) {
            if (r > k){
				r=0;
				return;
			}
            if (vcurr[h] == 1)
                r++;
        }
        (*nsol)++;
        printf("%d) ", *nsol);
        for (int h = 0; h < n; h++) {
            if (vcurr[h] == 1)
                printf("%d ", h);
            fflush(stdout);
        }
        r = 0;
        puts("");
        return;
    }
    vcurr[i] = 1;
    backrec(k, i + 1, n, done + 1, vcurr, nsol);
    vcurr[i] = 0;
    backrec(k, i + 1, n, done, vcurr, nsol);
}

int main(void) {
    int n = 15*6;  // COMBINAZIONI DI n ELEMENTI IN k GRUPPI
    int i = 0;
    int k = 4;
    int* vcurr = calloc(n, sizeof(int));
    int nsol = 0;
    backrec(k, 0, n, 0, vcurr, &nsol);
    free(vcurr);
    return EXIT_SUCCESS;
}