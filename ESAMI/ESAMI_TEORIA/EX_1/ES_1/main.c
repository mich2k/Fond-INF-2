#include <stdio.h>
#include <stdlib.h>
// SAVE : COMBINAZIONI, SCELTA SOLUZIONE OTTIMALE
void backrec(int k, int i, int n, int done, int* vcurr, int* vbest, int* quotazioni, int* vittorie,int budget, float* best_ratio) {
    if (i == n && done != k)
        return;
    if (done == k) {
        int sum = 0, vit = 0;
        float curr_ratio;
        for (int h = 0; h < n; h++) {
            if (vcurr[h]){
                if(sum + quotazioni[h]> budget)
                    return;
                sum += quotazioni[h];
                vit += vittorie [h];
            }
            }
            for(int h = 0; h < n; h++){
            if(vcurr[h])
                printf("%d ", h);
        }
            curr_ratio = (float) vit/sum;
            printf(" -> %f\n", curr_ratio);
            fflush(stdout);     
            if(curr_ratio > *best_ratio){
                *best_ratio = curr_ratio;
                for(int h = 0,  j = 0; h < n; h++ ){
                    if(vcurr[h])
                        vbest[j++] = h;
                }
        }
        puts("");
        return;
    }
    vcurr[i] = 1;
    backrec(k, i + 1, n, done + 1, vcurr, vbest, quotazioni, vittorie, budget, best_ratio);
    vcurr[i] = 0;
    backrec(k, i + 1, n, done, vcurr, vbest, quotazioni, vittorie, budget, best_ratio);
}

int main(void) {
    int quotazioni[] = {1200, 122, 1000, 544, 555, 666, 123, 6543, 100, 1000};
    int vittorie[] = {23, 10, 11, 15, 17, 63, 45, 2, 1, 5};
    int n_cav = 10;
    float best_ratio = 0;
    int k = 4;
    int* vcurr = malloc(
        n_cav *
        sizeof(int));  //!!!! VCURR SI ALLOCA PER TUTTI GLI ELEMENTI POSSIBILI
    int* vbest = malloc(k * sizeof(int));
    backrec(k, 0, n_cav, 0, vcurr, vbest, quotazioni, vittorie, 1200, &best_ratio);
    puts("");
    for(int i = 0; i < k; i++){
        printf("%d: %d - %d\n", vbest[i], quotazioni[vbest[i]], vittorie[vbest[i]]);
    }
    free(vcurr);
    free(vbest);
    return EXIT_SUCCESS;
}