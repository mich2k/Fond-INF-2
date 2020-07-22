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

bool _isValid(u32* v, int n) {
    bool* check_arr = calloc(10, sizeof(bool));
    for (size_t r = 0; r < n; r += 1) {
        if (check_arr[v[r]])
            return false;
        else
            check_arr[v[r]] = true;
    }
    free(check_arr);
    return true;
}

// 4200 Kcal tot
void backtrack(u32* vcurr, int n, int i, u32 N_PIATTI, size_t* cont) {
    if (i == n) {
        if (!_isValid(vcurr, n))
            return;
        (*cont)++;
        printf("%d)\t", *cont);
        for (size_t k = 0; k < n; k += 1)
            printf("%d ", *(vcurr + k));
        fflush(stdout);
        puts("");
        return;
    }
    for (u32 j = 1; j <= N_PIATTI;
         j += 1) {  // 0 < avrò 0/n-1, mentre 1 <= avrò, 1/n, !IMPORTANTE
        vcurr[i] = j;
        backtrack(vcurr, n, i + 1, N_PIATTI, cont);
    }
}

int main(void) {
    size_t k = 2;          // binario, NON questo caso
    size_t n_persone = 6;  // quante terne di piatti;
    size_t terna = 3;      // numero piatti per ogni terna
    u32* vcurr = malloc(terna * sizeof(u32));

    // array struct di N elementi / piatti

    piatto arr[] = {{1, 200, "pasta"},     {2, 100, "meat"},
                    {2, 350, "candies"},   {1, 150, "pizza"},
                    {2, 170, "meatballs"}, {3, 150, "cake"}};

    u32 N = sizeof(arr) / sizeof(arr[0]);
    size_t cont = 0;
    backtrack(vcurr, 3, 0, N, &cont);
    return EXIT_SUCCESS;
}