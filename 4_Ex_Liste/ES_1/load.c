#include <ctype.h>
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

int main(void) {
    char* filename =
        "/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_00.inp";
    Item* out = LoadList(filename);
    WriteStdoutList(out);
    //_CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}