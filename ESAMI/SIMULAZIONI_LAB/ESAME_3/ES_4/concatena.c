/*
Nel file concatena.c definire la funzione corrispondente alla seguente
dichiarazione:

extern list Concatena(list l1, list l2, list l3);

La funzione prende in input tre liste l1, l2, l3 che deve concatenare a partire
dalla prima. Le liste possono essere liste vuote. La funzione deve ritornare la
lista risultante, ovvero l’indirizzo della sua testa.

Se tutte le liste sono vuote, la funzione deve ritornare una lista vuota.

Per la risoluzione di questo esercizio avete a disposizione le stesse
definizioni e le stesse primitive fornite per l’esercizio 2.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_int.h"
extern Item* Concatena(Item* l1, Item* l2, Item* l3);

Item* Concatena(Item* l1, Item* l2, Item* l3) {
    Item* ris = CreateEmptyList();
    ElemType tmp;
    while (!IsEmptyList(l1)) {
        ris = InsertBackList(ris, GetHeadValueList(l1));
        l1 = GetTailList(l1);
    }
    while (!IsEmptyList(l2)) {
        ris = InsertBackList(ris, GetHeadValueList(l2));
        l2 = GetTailList(l2);
    }
    while (!IsEmptyList(l3)) {
        ris = InsertBackList(ris, GetHeadValueList(l3));
        l3 = GetTailList(l3);
    }
    return ris;
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
    char* filename = "/home/mich/Scrivania/Fond-INF-2/4_Ex_Liste/data_03.inp";
    Item* l1 = LoadList(filename);
    Item* l2 = LoadList(filename);
    Item* l3 = LoadList(filename);
    Item* ris = Concatena(l1, l2, l3);
    WriteStdoutList(ris);
    //_CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}