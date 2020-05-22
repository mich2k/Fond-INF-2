#include <stdlib.h>
#include <string.h>
#include "primitive.h"

const ElemType* Find(const Item* i, const char* name) {
    if (IsEmptyList(i))
        return NULL;
    char* curr_name = NULL;
    while (true) {
        curr_name = realloc(curr_name, 40 * sizeof(char));
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
    Item* tmp =
        InsertHeadList(GetHeadValueList(i), recDelete(e, GetTailList(i)));
    free(i);
    return tmp;
}

Item* Delete(Item* i, const char* name) {
    if (IsEmptyList(i)) {
        return i;
    }
    ElemType* e = (ElemType*)Find(i, name);
    Item* tmp = recDelete(e, i);
    return tmp;
}

void list_bubble_sort(char** arr, size_t n) {
    if (!arr || n <= 1)
        return;
    char* temp = malloc(sizeof(char) * 40);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (j + 1 >= n) {
                free(temp);
                break;
            }
            char* s1 = arr[j];
            char* s2 = arr[j + 1];
            if (strcmp(s1, s2) > 0) {
                strcpy(temp, *(arr + j));
                strcpy(*(arr) + j, *(arr + j + 1));
                strcpy(*(arr + j + 1), temp);
            }
        }
    }
    free(temp);
}

Item* Sort(Item* i) {
    if (IsEmptyList(i))
        return i;
    char** arr = NULL;
    Item* first_elem_pointer = i;
    size_t cont = 0, len = 0;
    while (!IsEmptyList(i)) {
        len = strlen((const char*)&i->value.name);
        arr = realloc(arr, cont + 1);
        arr[cont] = realloc(arr[cont], sizeof(char) * len);
        memcpy(arr[cont], &i->value.name, len);
        ++cont;
        i = GetTailList(i);
    }
    list_bubble_sort(arr, cont);
    i = first_elem_pointer;
    Item* copy = CreateEmptyList();
    for (size_t j = 0; j < cont; ++j) {
        copy = InsertHeadList(&i->value, copy);
        i = GetTailList(i);
    }
    for (size_t r = 0; r < cont; r += 1) {
        char* s = arr[r];
        i = InsertBackList(i, Find(copy, s));
    }
    // DeleteList(copy);
    for (size_t r = 0; r < cont; r += 1)
        free(arr[r]);
    free(arr);
    return i;
}

Item* Filtra(Item* i, const char* city) {
    if (IsEmptyList(i))
        return i;
    Item* ris = CreateEmptyList();
    while (!IsEmptyList(i)) {
        if (strcmp((const char*)&i->value.city, city) == 0)
            ris = InsertHeadList(&i->value, ris);
        i = GetTailList(i);
    }
    return ris;
}

Item* Reverse(const Item* l) {
    if (IsEmptyList(l))
        return (Item*)NULL;
    Item* ris = CreateEmptyList();
    while (!IsEmptyList(l)) {
        ris = InsertHeadList(&l->value, ris);
        l = GetTailList(l);
    }
    return ris;
}

Item* Append(const Item* l1, const Item* l2) {
    if (IsEmptyList(l1) && IsEmptyList(l2))
        return (Item*)NULL;
    if (IsEmptyList(l1)) {
        Item* tmp = CreateEmptyList();
        while (!IsEmptyList(l2)) {
            tmp = InsertBackList(tmp, &l2->value);
            l2 = GetTailList(l2);
        }
        return tmp;
    }
    Item* tmp =
        InsertHeadList(GetHeadValueList(l1), Append(GetTailList(l1), l2));
    return tmp;
}

Item* AppendMod(Item* l1, Item* l2) {
    if (IsEmptyList(l1) && IsEmptyList(l2))
        return (Item*)NULL;
    if (IsEmptyList(l1))
        return l2;
    Item* tmp =
        InsertHeadList(GetHeadValueList(l1), Append(GetTailList(l1), l2));
    free(l1);
    return tmp;
}

int main(void) {
    ElemType e1 = {"Mario", "via garibaldi", 1212, "Bologna", "AAA", "1234"};
    ElemType e2 = {"Giuseppe", "via europa", 1111, "Torino", "BBB", "4311"};
    Item* i = CreateEmptyList();
    i = InsertHeadList(&e1, i);
    i = InsertHeadList(&e2, i);
    Item* i2 = CreateEmptyList();
    i2 = InsertHeadList(&e1, i2);
    i2 = InsertHeadList(&e2, i2);
    Item* ris = Append(i, i2);
    return EXIT_SUCCESS;
}