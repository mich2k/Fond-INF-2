#include <ctype.h>
#include <stdlib.h>

#include "list_int.c"
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
    size_t ret;
    while (ret) {
        ret = fscanf(f, "%d", &x);
        if(ret)
            list = InsertHeadList(&x, list);
    }
    return list;
}

int main(void) {
    char* filename =
        "/home/mich/Scrivania/UNI/Fond-INF-2/Training/Struttura Gen. "
        "Liste/data_00.inp";
    Item* out = LoadList(filename);
    //_CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}

/*


*/