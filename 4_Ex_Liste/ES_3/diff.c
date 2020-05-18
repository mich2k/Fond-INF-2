#include <ctype.h>
#include <stdlib.h>

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

Item* Diff(const Item* i1, const Item* i2) {
    if (i1 == NULL || i2 == NULL)
        return NULL;
    Item* ris_list = NULL;
    while(true){
        
    }
    
}

int main(void) {
    Item* first =
        LoadList("/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_00.inp");
    Item* second =
        LoadList("/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_01.inp");
    Diff(first, second);
    return EXIT_SUCCESS;
}