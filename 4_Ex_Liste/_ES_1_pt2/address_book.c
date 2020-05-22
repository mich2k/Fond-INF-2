#include <stdlib.h>
#include <string.h>

//#include "list_int.h"
#include "primitive.h"

const ElemType* Find(const Item* i, const char* name) {
    if (IsEmptyList(i))
        return NULL;
    char* curr_name = NULL;
    while (true) {
        curr_name = realloc(curr_name,40 * sizeof(char));
        memcpy(curr_name, &(i->value).name, 40);
        if (strcmp(name, curr_name) == 0) {
            free(curr_name);
            return &i->value;
        }
        i = GetTailList(i);
    }
    free(curr_name);
    return NULL;
}

Item* recDelete(const ElemType* e, Item* i) {
    if (IsEmptyList(i)) {
        return i;
    }
    if (ElemCompare(e, GetHeadValueList(i)) == 0) {
        Item* tmp = GetTailList(i);
        free(i);
        return tmp;
    }
    Item* tmp = InsertHeadList(GetHeadValueList(i), recDelete(e, GetTailList(i)));
    free(i);
    return tmp;
}

Item* Delete(Item* i, const char* name) {
    if (IsEmptyList(i)) {
        return i;
    }
    ElemType* e = (ElemType*) Find(i, name);
    Item* tmp = recDelete(e, i);
    return tmp;
}


/*

    struct Address {
        char name[40];
        char street[50];
        int number;
        char city[30];
        char province[3];
        char postal_code[6];
    };

*/

int main(void) {
    // ElemType* e1 = {"Gennaro", "a", 1, "napoli", "NAP", "83100"};
    // ElemType* e2 = {"Pasqua", "pasqale", 1, "napoli", "NAP", "83100"};

    ElemType e1 = {"Gennaro", "via garibaldi", 1212, "Napoli", "nap", "1211"};
    ElemType e2 = {"Pasqua", "via garibaldi", 1111, "Napoli", "nap", "1211"};
    Item* i = CreateEmptyList();
    i = InsertHeadList(&e1, i);
    i = InsertHeadList(&e2, i);
    Find(i, "Gennaro");
    i = Delete(i, "Pasqua");
    return EXIT_SUCCESS;
}