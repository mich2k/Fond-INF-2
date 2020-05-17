#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include "list_int.h"

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

ElemType MaxElement(const Item* i) {
    ElemType* max = (int*)&i->value;
    while (!IsEmptyList(i)) {
        if (ElemCompare(max, &i->value) < 0)
            *max = i->value;
        i = GetTailList(i);
    }
    return *max;
}

int main(void) {
    char* filename =
        "/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_00.inp";
    Item* out = LoadList(filename);
    ElemType max = MaxElement(out);
    WriteStdoutList(out);
    fprintf(stdout, "Max element: %d", max);
    return EXIT_SUCCESS;
}