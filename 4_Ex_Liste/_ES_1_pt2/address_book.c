#include <stdlib.h>
#include <string.h>

//#include "list_int.h"
#include "primitive.h"



const ElemType* Find(const Item* i, const char* name) {
    if (IsEmptyList(i))
        return NULL;
    while (true) {
        char* curr_name = (i->value).name;
        if (strcmp(name, curr_name))
            return i;
        i = GetHeadValueList(i);
    }
}

int main(void) {
    return EXIT_SUCCESS;
}