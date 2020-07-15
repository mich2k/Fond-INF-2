#include <stdlib.h>
#include "list_int.h"

Item* CreaDaMinori(const Item* i, int v) {
    Item* n = CreateEmptyList();
    while (!IsEmptyList(i)) {
        if (*GetHeadValueList(i) < v)
            n = InsertBackList(n, (const ElemType*)GetHeadValueList(i));
        i = GetTailList(i);
    }
    return n;
}
