#include <ctype.h>
#include <stdlib.h>
// stdbool.h già definita in list_int.h
#include "list_int.h"

// ! NO PRIMITIVE ALLOWD

typedef int Element;

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

bool Lookup(const Item* list, Element* x) {
    while (list) {
        if (*x == (Element)list->value)
            return true;
        list = list->next;
    }
    return false;
}

Item* Diff(const Item* i1, const Item* i2) {
    if (i1 == NULL || i2 == NULL)
        return NULL;
    Item* ris_list = NULL;
    size_t i = 0;
    while (i1) {
        Element* current_value = (Element*)&i1->value;
        if (!Lookup(i2, current_value)) {
            ris_list = calloc(i + 1, sizeof(Item));
            ris_list->value = *current_value;
            ris_list->next = (ris_list + i);
            i += 1;
        }
        i1 = i1->next;
    }
    WriteStdoutList(ris_list);
    return ris_list;
}

int main(void) {
    Item* first =
        LoadList("/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_00.inp");
    Item* second =
        LoadList("/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_01.inp");
    Diff(first, second);
    return EXIT_SUCCESS;
}