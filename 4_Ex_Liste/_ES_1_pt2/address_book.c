#include <stdlib.h>
#include <string.h>

//#include "list_int.h"
#include "primitive.h"



/*const ElemType* Find(const Item* i, const char* name) {
    if (IsEmptyList(i))
        return NULL;
    while (true) {
        char* curr_name = (i->value).name;
        if (strcmp(name, curr_name))
            return i;
        i = GetHeadValueList(i);
    }
}
*/

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
    ElemType* e1 = {"Gennaro", "a" , 1, "napoli", NULL, "83100"};
    ElemType* e2 = {"Gennaro", "pasqale", 1, "napoli", "NAP", "83100"};
    bool culo = ElemCompare(&e1,e2);
    ElemType* ulo  = ElemCopy(&e1);
    printf("\n%s\n", ulo.city);
    ElemDelete(&ulo);
        printf("\n%s\n", ulo.city);

    return EXIT_SUCCESS;
}