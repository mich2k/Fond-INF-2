/*
Nel file concatena.c definire la funzione corrispondente alla seguente dichiarazione: 

extern list Concatena(list l1, list l2, list l3);

La funzione prende in input tre liste l1, l2, l3 che deve concatenare a partire dalla prima. 
Le liste possono essere liste vuote. La funzione deve ritornare la lista risultante, ovvero 
l’indirizzo della sua testa.

Se tutte le liste sono vuote, la funzione deve ritornare una lista vuota.

Per la risoluzione di questo esercizio avete a disposizione le stesse definizioni e le stesse 
primitive fornite per l’esercizio 2.
*/
#include "list_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern Item* Concatena(Item* l1, Item* l2, Item* l3);

Item* Concatena(Item* l1, Item* l2, Item* l3){
    
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
    char* filename =
        "/home/mich/Scrivania/Fond-INF-2/4_Ex_Liste/data_03.inp";
    Item* l1 = LoadList(filename);
    Item* l1 = LoadList(filename);
    Item* l1 = LoadList(filename);
    Item* ris = con
    WriteStdoutList(out);
    //_CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}