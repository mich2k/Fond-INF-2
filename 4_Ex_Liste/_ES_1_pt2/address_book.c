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
        if (strcmp(&i->value.city, city) == 0)
            ris = InsertHeadList(&i->value, ris);
        i = GetTailList(i);
    }
    return ris;
}

Item* Reverse(const Item* l) {
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
        while (!IsEmptyListI(l2)) {
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
    Item* tmp = InsertHeadList(GetHeadValueList(l1), Append(GetTailList(l1), l2));
}

int main(void) {
    // ElemType* e1 = {"Gennaro", "a", 1, "napoli", "NAP", "83100"};
    // ElemType* e2 = {"Pasqua", "pasqale", 1, "napoli", "NAP", "83100"};

    ElemType e1 = {"Pasqua", "via garibaldi", 1212, "Napoli", "nap", "1211"};
    ElemType e2 = {"Gennaro", "via garibaldi", 1111, "Napoli", "nap", "1211"};
    Item* i = CreateEmptyList();
    i = InsertHeadList(&e1, i);
    i = InsertHeadList(&e2, i);
    Find(i, "Gennaro");
    // i = Delete(i, "Pasqua");
    // Sort(i);
    Item* ris = Reverse(i);

    return EXIT_SUCCESS;
}