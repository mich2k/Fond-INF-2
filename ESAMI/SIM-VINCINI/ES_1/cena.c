/*
  Maria deve preparare la cena per la sua famiglia, composta da lei, il marito e
  4 figli. Ciascuno deve introdurre 700 Kcal ed ha a disposizione un elenco di N
  (costante) piatti, ciascuno caratterizzato dalla tipologia (1= primo,
  2=contorno, 3=secondo), dal valore di Kcal e dal nome. Aiutate Maria nella
  scelta della cena, mostrando a video tutte le possibili terne di piatti (uno
  solo per ciascuna categoria) che permettono di somministrare le esatte calorie
  a ciascun commensale.
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tipologia;
    int Kcal;
    char nome[20];
} piatto;

typedef uint32_t u32;

bool _isValid(u32* arr,const size_t* n) {
    for (u32 j = 0; j < *n; ++j) {
        if (arr[j] == 0)
            return false;
    }
    bool* check = calloc(3, sizeof(bool));
    for (u32 j = 0; j < *n; ++j) {
        if (check[arr[j]] == false)
            check[arr[j]] = !check[arr[j]];
        else
            return false;
    }
    return true;
}

void backtrack(piatto* arr, size_t n, size_t i, size_t k, u32* vcurr) {
    if (i == n) {
        if (!_isValid(vcurr, &n))
            return;
        bool _first_check = false;
        bool _second_check = false;
        bool _third_check = false;

        for (u32 j = 0; j < n; ++j)
            printf("%d ", vcurr[j]);
        u32 kcal_sum = 0;
        /* for (u32 j = 0; j < n; j += 1) {
             // if(vcurr[j] == true)
             fprintf(stdout, "%d %d %s \n", arr[j].tipologia, arr[j].Kcal,
                     arr[j].nome);
         }*/
        puts("");
        return;
    }
    for (u32 r = 0; r < k; ++r) {
        vcurr[i] = r;
        backtrack(arr, n, i + 1, k, vcurr);
    }
}

int main(void) {
    size_t k = 2;          // binario
    size_t n_persone = 6;  // quante terne di piatti;
    size_t n_piatti = 3;   // numero piatti per ogni terna
    u32* vcurr = malloc(n_piatti * sizeof(u32));

    // array struct di N elementi / piatti

    piatto arr[] = {{1, 200, "pasta"},     {2, 100, "meat"},
                    {2, 350, "candies"},   {1, 150, "pizza"},
                    {2, 170, "meatballs"}, {3, 150, "cake"}};

    backtrack(arr, n_piatti, 0, 4, vcurr);
    return EXIT_SUCCESS;
}