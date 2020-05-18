#include <ctype.h>
#include <stdlib.h>
// stdbool.h già definita in list_int.h
#include "list_int.h"
// ! NO PRIMITIVE ALLOWD

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

bool Lookup(const Item* list, ElemType* x) {
    while (list) {
        if (*x == (ElemType)list->value)
            return true;
        list = list->next;
    }
    return false;
}

Item* ElemAdd(const ElemType* e, Item* i) {
    Item* t = calloc(1, sizeof(Item));
    t->value = ElemCopy(e);
    t->next = i;
    return t;
}

Item* Diff(const Item* i1, const Item* i2) {
    if (i1 == NULL || i2 == NULL)
        return NULL;
    Item* ris_list = NULL;
    size_t i = 0;
    while (i1) {
        ElemType* current_value = (ElemType*)&i1->value;  // ReadElem(i1);
        if (!Lookup(i2, current_value))
            ris_list = ElemAdd(current_value, ris_list);
        i1 = i1->next;
    }
    WriteStdoutList(ris_list);
    return ris_list;
}

int main(void) {
    Item* first =
        LoadList("/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_00.inp");
    Item* second =
        LoadList("/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_02.inp");
    Diff(first, second);
    return EXIT_SUCCESS;
}