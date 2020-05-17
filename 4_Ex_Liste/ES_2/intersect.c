#include <stdlib.h>
#include <ctype.h>
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

Item* Intersect(const Item* i1, const Item* i2) {
    if (IsEmptyList(i1) || IsEmptyList(i2))
        return NULL;
    Item* ris_list = CreateEmptyList();
    Item* first_elem_pointer =(Item*) i2;
    while (true) {
        ElemType* first_elem = (int*)GetHeadValueList(i1);
        i2 = first_elem_pointer;
        while (!IsEmptyList(i2)) {
            ElemType* second_elem = (int*)GetHeadValueList(i2);
            if (ElemCompare(first_elem, second_elem) == 0)
                ris_list = InsertHeadList((const ElemType)first_elem, ris_list);
            i2 = GetTailList(i2);
        }
        i1 = GetTailList(i1);
        if (IsEmptyList(i1))
            break;
    }
    WriteStdoutList(ris_list);
    return ris_list;
}

int main(void) {
    Item* first = LoadList(
        "/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_00.inp");
    Item* second = LoadList(
        "/home/mich/Scrivania/UNI/Fond-INF-2/4_Ex_Liste/data_01.inp");
    Intersect(first, second);
}