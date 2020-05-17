#include "list_int.h"
#include <stdlib.h>

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

Item *Intersect (const Item* i1, const Item* i2){
    if(IsEmptyList(i1) || IsEmptyList(i2))
        return NULL;
    Item* list = CreateEmptyList();
    while(true){

    }
    //InsertBackList();

}

int main(void){
    Item* first = LoadList("/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/ES_2/data_00.inp");
    Item* second = LoadList("/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/ES_2/data_01.inp");
    Intersect(first, second);

}