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
    size_t i = 0;
    while(true) {
        x = ReadElem(f);
        if (feof(f) || ferror(f))
            break;
        list = InsertHeadList(&x, list);
    }
    return list;
}

int main(void) {
    char* filename =
        "/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/ES_1/data_00.inp";
    Item* out = LoadList(filename);
    WriteStdoutList(out);
    //_CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}