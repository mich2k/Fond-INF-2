#include <stdlib.h>
#include "list_int.h"

void list_edit(Item** l) {
    Item* head = *l;
    if (IsEmptyList((*l)->next) || IsEmptyList((*l)->next->next))
        return;
    while (!IsEmptyList((*l)->next->next)) {
        if ((*l)->next->value ==  (*l)->value + (*l)->next->next->value) {
            (*l)->next = (*l)->next->next;
            continue;
        }
        *l = GetTailList(*l);
    }
    *l = head;
    return;
}

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Item* l =NULL;
    l = InsertBackList(l, &arr[2]);
    l = InsertBackList(l, &arr[6]);
    l = InsertBackList(l, &arr[4]);
    l = InsertBackList(l, &arr[2]);
    WriteStdoutList(l);
    list_edit(&l);
    WriteStdoutList(l);
    return EXIT_SUCCESS;
}