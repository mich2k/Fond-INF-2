/*Nel file any_loop.c definire la funzione corrispondente alla seguente dichiarazione:

extern bool AnyLoop(list l);
La funzione prende in input una lista di int e deve verificare se questa contiene o meno un ciclo. 
La funzione deve ritornare true se nella lista è presente un ciclo, false altrimenti (compreso il caso in cui la lista è vuota).

Una lista contiene un ciclo se almeno uno dei suoi elementi è raggiungibile da due percorsi differenti.*/

#include "list_int.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern bool AnyLoop(Item* l);

bool AnyLoop(Item* l){

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
    return EXIT_SUCCESS;
}