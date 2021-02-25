#include <stdlib.h>
#include "list_int.h"

void list_rem(Item** l, int val) {
    Item* head = *l;
    if((*l)->value + (*l)->next->value == val){
        *l = head->next->next;
        return;
    }
    while(!IsEmptyList((*l)->next)){
        if((*l)->next->value + (*l)->next->next->value == val){
            (*l)->next = (*l)->next->next->next;
            *l = head;
            return;
        }
        (*l) = GetTailList(*l);
    }
    return;
}

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Item* l = CreateEmptyList();
    l = InsertBackList(l,&arr[1]);
    l = InsertBackList(l,&arr[5]);
    l = InsertBackList(l,&arr[3]);
    l = InsertBackList(l,&arr[3]);
    l = InsertBackList(l,&arr[2]);
    WriteStdoutList(l);
    list_rem(&l,5);
    WriteStdoutList(l);
    return EXIT_SUCCESS;

}