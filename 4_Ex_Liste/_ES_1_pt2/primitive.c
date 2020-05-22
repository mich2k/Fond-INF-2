#define _CRT_SECURE_NO_WARNINGS
#include "primitive.h"
/*****************************************************************************/
/*                                 Element                                   */
/*****************************************************************************/

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
enum var_types{_is_int = 1, _is_char};

int ElemCompare(const ElemType* e1, const ElemType* e2) {
    uint8_t len = 6; // struct elements

    for(uint8_t len = 6; )

}


ElemType ElemCopy(const ElemType* e) {
    return *e;
}

void ElemDelete(ElemType* e) {}

int ReadElem(FILE* f, ElemType* e) {
    return fscanf(f, "%d", e);
}

int ReadStdinElem(ElemType* e) {
    return ReadElem(stdin, e);
}

void WriteElem(const ElemType* e, FILE* f) {
    printf("%d", *e);
}

void WriteStdoutElem(const ElemType* e) {
    WriteElem(e, stdout);
}

/*****************************************************************************/
/*                          Item & Primitives                                */
/*****************************************************************************/

Item* CreateEmptyList(void) {
    return NULL;
}

Item* InsertHeadList(const ElemType* e, Item* i) {
    Item* t = malloc(sizeof(Item));
    t->value = ElemCopy(e);
    t->next = i;
    return t;
}

bool IsEmptyList(const Item* i) {
    return i == NULL;
}

const ElemType* GetHeadValueList(const Item* i) {
    if (IsEmptyList(i)) {
        printf(
            "ERROR: Alla funzione 'GetHeadList()' e' stata passata una lista "
            "vuota (NULL pointer).\n");
        exit(1);
    } else {
        return &i->value;
    }
}

Item* GetTailList(const Item* i) {
    if (IsEmptyList(i)) {
        printf(
            "ERROR: Alla funzione 'GetTail()' e' stata passata una lista vuota "
            "(NULL pointer).\n");
        exit(2);
    } else {
        return i->next;
    }
}

Item* InsertBackList(Item* i, const ElemType* e) {
    Item* n = InsertHeadList(e, CreateEmptyList());

    if (IsEmptyList(i)) {
        return n;
    }

    Item* tmp = i;
    while (!IsEmptyList(GetTailList(tmp))) {
        tmp = GetTailList(tmp);
    }

    tmp->next = n;
    return i;
}

void DeleteList(Item* i) {
    while (!IsEmptyList(i)) {
        Item* tmp = i;
        i = i->next;
        ElemDelete(&tmp->value);
        free(tmp);
    }
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void WriteList(const Item* i, FILE* f) {
    printf("[");
    while (!IsEmptyList(i)) {
        WriteElem(&i->value, f);
        i = GetTailList(i);
        if (!IsEmptyList(i))
            printf(", ");
    }
    printf("]\n");
}

void WriteStdoutList(const Item* i) {
    WriteList(i, stdout);
}