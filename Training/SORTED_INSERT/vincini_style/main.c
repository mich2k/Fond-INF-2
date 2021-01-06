#include <stdlib.h>
#include "list_int.h"

Item* VSortedInsert(ElemType* e, Item* l) {
    Item *l1 = NULL, *head = l, *tmp;
    if (IsEmptyList(l) || (!(*GetHeadValueList(l) < *e))) {
        tmp = InsertHeadList( e, l);
        return tmp;
    }
    tmp = InsertBackList(NULL, e);
    while (!IsEmptyList(l) && *GetHeadValueList(l) < *e) {
        l1 = l;
        l = GetTailList(l);
    }
    l1->next = tmp;
    tmp->next = l;
    return head;
}

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Item* m = CreateEmptyList();
    m = VSortedInsert(&arr[3], m);
    m = VSortedInsert(&arr[9], m);
    m = VSortedInsert(&arr[8], m);
    m = VSortedInsert(&arr[1], m);
    m = VSortedInsert(&arr[9], m);
    m = VSortedInsert(&arr[6], m);
    m = VSortedInsert(&arr[7], m);
    m = VSortedInsert(&arr[2], m);
    WriteStdoutList(m);
    return EXIT_SUCCESS;
}
