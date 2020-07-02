/*Nel file any_loop.c definire la funzione corrispondente alla seguente
dichiarazione:

extern bool AnyLoop(list l);
La funzione prende in input una lista di int e deve verificare se questa
contiene o meno un ciclo. La funzione deve ritornare true se nella lista è
presente un ciclo, false altrimenti (compreso il caso in cui la lista è vuota).

Una lista contiene un ciclo se almeno uno dei suoi elementi è raggiungibile da
due percorsi differenti.*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_int.h"

#include <ctype.h>  // LoadList()

extern bool AnyLoop(Item* l);

bool AnyLoop(Item* l) {
    Item* root_pos = l;
    Item* curr_pos = l;
    Item* second_pos = l;
    for (uint8_t i = 0; !IsEmptyList(curr_pos); i += 1) {
        for (uint8_t j = 0; !IsEmptyList(second_pos); j += 1) {
            if (true) {
                if (&second_pos->value == &curr_pos->value)
                    return true;
            }
            second_pos = GetTailList(second_pos);
        }
        second_pos = root_pos;
        curr_pos = GetTailList(curr_pos);
    }
    return false;
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
    printf("\n--->  %d\n", AnyLoop(l)); // TORNA CORRETT. FALSE
    GetTailList(l)->next = l->next; // GENERO IL LOOP
    printf("\n--->  %d\n", AnyLoop(l)); // TORNA CORRETT. TRUE
}