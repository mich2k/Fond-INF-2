#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int media_voto;
    char* nome;
}classe;

void backrec(int k,int i, int n, int done, int* vcurr, int* nsol, float media_classe, classe* a) {
    if (i == n && done != k)
        return;
    if (done == k) {
        float curr_avg = 0;
        for (int h = 0; h < n; h++) {
            if (vcurr[h] == 1){
                if((a+h)->media_voto < media_classe)
                    return;
            }
               
        }
        (*nsol)++;
        printf("\n%d)\n", *nsol);
        for (int h = 0; h < n; h++) {
            if (vcurr[h] == 1){
                    printf("%d  -> %s, %d", h, (a+h)->nome, (a+h)->media_voto);
            }
            puts("");
        }
        puts("");
        return;
    }
    vcurr[i] = 1;
    backrec(k,i + 1, n, done + 1, vcurr, nsol, media_classe,a);
    vcurr[i] = 0;
    backrec(k,i + 1, n, done, vcurr, nsol, media_classe,a);
}


int main(void) {
    int i = 0;
    int k = 4;
    classe a []= {{9, "Gennaro"}, {7, "Ciro"}, {6, "Ebreo"}, {7, "Wang"}, {1, "Bruce"}, {7, "Xi"}, {7, "Carmelina"}, {7, "Salvatore"}, {7, "Esposito"}}; 
    int n = sizeof(a)/sizeof(classe);
    int* vcurr = calloc(n, sizeof(int));
    int nsol = 0;
    float media_classe;
    for(size_t i = 0; i < n; i++){
        media_classe+= a[i].media_voto;
    }
    media_classe /= n;
    printf("class avg: %f\n", media_classe);
    backrec(k,0, n, 0, vcurr, &nsol, media_classe, a);
    free(vcurr);
    return EXIT_SUCCESS;
}