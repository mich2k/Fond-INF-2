/*
  Maria deve preparare la cena per la sua famiglia, composta da lei, il marito e
  4 figli. Ciascuno deve introdurre 700 Kcal ed ha a disposizione un elenco di N
  (costante) piatti, ciascuno caratterizzato dalla tipologia (1= primo,
  2=contorno, 3=secondo), dal valore di Kcal e dal nome. Aiutate Maria nella
  scelta della cena, mostrando a video tutte le possibili terne di piatti (uno
  solo per ciascuna categoria) che permettono di somministrare le esatte calorie
  a ciascun commensale.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int tipologia;
    int Kcal;
    char nome[20];
} piatto;

typedef uint32_t u32;

void backtrack(piatto* arr, size_t n, size_t i, size_t k, u32* vcurr) {
    if (i == n) {
        // for (u32 j = 0; j < n; ++j)
        //    printf("%d ", vcurr[j]);
        u32 kcal_sum = 0;
        for (u32 j = 0; j < n; j += 1) {
            // if(vcurr[j] == true)
            fprintf(stdout, "%d %d %s \n", arr[j].tipologia, arr[j].Kcal,
                    arr[j].nome);
        }
        puts("");
        return;
    }
    for (u32 r = 0; r < k; ++r) {
        vcurr[i] = r;
        backtrack(arr, n, i + 1, k, vcurr);
    }
}

int main(void) {
    size_t k = 2;         // binario
    size_t N = 2;         // quante terne di piatti;
    size_t n_piatti = 3;  // numero piatti per ogni terna
    u32* vcurr = malloc(n_piatti * sizeof(u32));

    // array struct

    piatto arr[] = {{1, 200, "primo"}, {2, 300, "secondo"}, {3, 150, "terzo"},
                    {1, 200, "primo"}, {2, 300, "secondo"}, {3, 150, "terzo"}};

    /*for (size_t r = 0; r < N * n_piatti; r += 1)
        fprintf(stdout, "%d %d %s \n", arr[r].tipologia, arr[r].Kcal,
                arr[r].nome);
    */
    backtrack(arr, n_piatti, 0, 2, vcurr);
    return EXIT_SUCCESS;
}