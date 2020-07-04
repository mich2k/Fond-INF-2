#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "list_int.h"
extern Item* OrderedMerge(Item* la, Item* lb);
// BAHs
Item* OrderedMerge(Item* la, Item* lb) {
    if (IsEmptyList(la))
        return lb;
    if (IsEmptyList(lb))
        return la;
    if (IsEmptyList(la) && IsEmptyList(lb))
        return NULL;
    size_t cont_1 = 0, cont_2 = 0;
    Item* root_a = la;
    Item* root_b = lb;
    while (!IsEmptyList(la)) {
        cont_1++;
        la = GetTailList(la);
    }
    while (!IsEmptyList(lb)) {
        cont_2++;
        lb = GetTailList(lb);
    }
    la = root_a;
    lb = root_b;
    ElemType* curr;
    size_t cont = 0;
    while (cont < (cont_1 + cont_2)) {
        la = root_a;
        lb = root_b;
        *curr = *GetHeadValueList(la);
        while (!IsEmptyList(la)) {
            if (*GetHeadValueList(la))
                curr = &la->value;
            la = GetTailList(la);
        }
        while (!IsEmptyList(lb)) {
            if (*GetHeadValueList(lb) <= *curr)
                curr = &lb->value;
            lb = GetTailList(lb);
        }
        printf("%d\n", *curr);
        ++cont;
    }
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
    char* filename = "/home/mich/Scrivania/Fond-INF-2/4_Ex_Liste/data_03.inp";
    Item* l1 = LoadList(filename);
    filename = "/home/mich/Scrivania/Fond-INF-2/4_Ex_Liste/data_02.inp";
    Item* l2 = LoadList(filename);
    WriteStdoutList(l1);
    WriteStdoutList(l2);
    Item* ris = OrderedMerge(l1, l2);
    WriteStdoutList(ris);
    //_CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}