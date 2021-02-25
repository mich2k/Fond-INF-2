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

void input(Item** l, char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL || ferror(f))
        return;
    while (true) {
        if (ferror(f) || feof(f))
            break;
        char* s;
        int p;
        ElemType* tmp = {malloc(sizeof(char) * 20), p};
        size_t ret = fscanf("%s %d", s, &p);
        // InsertBackList(*l, );
    }
}

int main(void) {
    Item* l = CreateEmptyList();
    char* filename =
        "/home/mich/Scrivania/NEW-FDI2/ESAMI/EX_5/ES_2/magazzino.txt";
    // input(&l, filename);
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Item* m = CreateEmptyList();
    m = insord(&arr[3], m);
    m = insord(&arr[1], m);
    m = insord(&arr[9], m);
    m = insord(&arr[8], m);
    m = insord(&arr[9], m);
    m = insord(&arr[6], m);
    m = insord(&arr[7], m);
    m = insord(&arr[2], m);


    WriteStdoutList(m);
    return EXIT_SUCCESS;
}