#include <stdlib.h>
#include "list_int.h"

Item* SeekAndDestroy(Item* l, int k) {
    Item* head = l;
    if (l->value + l->next->value == k) {
        head = l->next->next;
        ElemDelete(&l->next->value);
        ElemDelete(&l->value);
        return head;
    }
    while (!IsEmptyList(l)) {
        if (l->next->value + l->next->next->value == k) {
            ElemDelete(&l->next->value);
            ElemDelete(&l->next->next->value);
            l->next = l->next->next->next;
            return head;
        }
        l = GetTailList(l);
    }
    return head;
}

int main(void) {
    Item* l = NULL;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l = InsertBackList(l, &arr[1]);
    l = InsertBackList(l, &arr[3]);
    l = InsertBackList(l, &arr[7]);
    l = InsertBackList(l, &arr[2]);
    l = InsertBackList(l, &arr[8]);
    l = InsertBackList(l, &arr[9]);
    l = SeekAndDestroy(l, 10);
    WriteStdoutList(l);
    return EXIT_SUCCESS;
}