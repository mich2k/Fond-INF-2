/*
Nel file sortlist.c definire la funzione corrispondente alla seguente
dichiarazione:

extern list SortList(list l);
La funzione prende in input una lista di int e deve ordinarne i suoi elementi
per valore crescente e ritornare la testa della lista ordinata. Se la lista l è
vuota deve essere ritornata una lista vuota. Non ci sono vincoli sull’algoritmo
di ordinamento, ovvero potete scegliere l’algoritmo che preferite. Suggerimento:
per scambiare due elementi della lista è sufficiente scambiarne i valori, senza
dover aggiornare i puntatori.

Per la risoluzione di questo esercizio avete a disposizione le seguenti
definizioni:

typedef int element; typedef struct list_element { element value; struct
list_element *next; } item; typedef item* list; e le seguenti primitive:

http://imagelab.ing.unimore.it/OLJ2/esami/materiale/20201002_esame/list_int/list__int_8h.html
*/

#include <stdlib.h>
#include "list_int.h"

extern Item* SortList(Item*);

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void quick_sort(int* v, int first, int last) {
    int i, j, pivot;
    if (first < last) {
        i = first;
        j = last;
        pivot = v[(first + last) / 2];
        do {
            while (v[i] < pivot)
                i++;
            while (v[j] > pivot)
                j--;
            if (i <= j) {
                swap(&v[i], &v[j]);
                i++, j--;
            }
        } while (i <= j);
        quick_sort(v, first, j);
        quick_sort(v, i, last);
    }
}

Item* SortList(Item* l) {
    if (IsEmptyList(l))
        return CreateEmptyList();
    Item* root_pos = CreateEmptyList();
    Item* ris_list = CreateEmptyList();
    root_pos = l;
    size_t cont = 0;
    ElemType* v = NULL;
    while (!IsEmptyList(l)) {
        v = realloc(v, sizeof(ElemType) * (cont + 1));
        v[cont] = *GetHeadValueList(l);
        l = GetTailList(l);
        ++cont;
    }
    quick_sort(v, 0, cont - 1);
    for (int i = 0; i < cont; ++i) {
        ris_list = InsertBackList(ris_list, &v[i]);
    }
    WriteStdoutList(ris_list);
    return ris_list;
}

Item* LoadList(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        return NULL;
    if (!isprint(fgetc(f))) {
        fclose(f);
        return NULL;
    }
    fseek(f, -1, SEEK_CUR);
    Item* list = CreateEmptyList();
    ElemType x;
    while (true) {
        x = ReadElem(f);
        list = InsertHeadList(&x, list);
        if (feof(f) || ferror(f))
            break;
    }
    fclose(f);
    return list;
}

int main(void) {
    Item* l =
        LoadList("/home/mich/Scrivania/Fond-INF-2/4_Ex_Liste/data_03.inp");
    WriteStdoutList(l);
    SortList(l);
    return EXIT_SUCCESS;
}