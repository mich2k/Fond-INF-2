#include <stdbool.h>
#include <stdlib.h>
#include "tree_int.h"
#define true 1
#define false 0

void rec(Node* t1, Node* t2, bool* flag) {
    if (IsEmptyTree(t1) && !IsEmptyTree(t2) ||
        !IsEmptyTree(t1) && IsEmptyTree(t2)) {
        *flag = false;
        return;
    } else if (IsEmptyTree(t1) && IsEmptyTree(t2))
        return;
    if (!IsLeafTree(t1) && !IsLeafTree(t2)) {
        if (*GetRootValueTree(t1) != *GetRootValueTree(t2)) {
            *flag = false;
            return;
        }

    } else if (IsLeafTree(t1) && IsLeafTree(t2)) {
        int a = *GetRootValueTree(t1);
        int b = *GetRootValueTree(t2);
        if (b%a != 0 && a%b != 0) {
            *flag = false;
            return;
        }
    }
    rec(LeftTree(t1), LeftTree(t2), flag);
    rec(RightTree(t1), RightTree(t2), flag);
}

bool Equivalenti(Node* t1, Node* t2) {
    bool* flag = true;
    rec(t1, t2, &flag);
    return flag;
}

/*
    CONDIZIONI:
        I due alberi hanno la stessa struttura;
        I nodi non foglia contengono gli stessi valori.
        I nodi foglia corrispondenti contengono valori uno multiplo dell`altro.
*/

int main(void) {
    Node* t1 = CreateEmptyTree();
    Node* t2 = CreateEmptyTree();
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t1 = CreateRootTree(
        &arr[1],
        CreateRootTree(
            &arr[3],
            CreateRootTree(&arr[1], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[2], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[4],
            CreateRootTree(&arr[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[5], CreateEmptyTree(), CreateEmptyTree())));
    t2 = CreateRootTree(
        &arr[1],
        CreateRootTree(
            &arr[3],
            CreateRootTree(&arr[1], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[2], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[4],
            CreateRootTree(&arr[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[5], CreateEmptyTree(), CreateEmptyTree())));
    Node* t3 = CreateRootTree(
        &arr[6],
        CreateRootTree(
            &arr[5],
            CreateRootTree(&arr[9], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[11], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[1],
            CreateRootTree(&arr[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateEmptyTree()));

    Node* t4 = CreateRootTree(&arr[1], CreateRootTree(&arr[2], NULL, NULL),
                              CreateRootTree(&arr[3], NULL, NULL));
    Node* t5 = CreateRootTree(&arr[1], CreateRootTree(&arr[4], NULL, NULL),
                              CreateRootTree(&arr[1], NULL, NULL));
    stampa_albero(t4);
    stampa_albero(t5);
    printf("\nequivalent check ---> %d (1 = true, 0 = false)\n",
           Equivalenti(t4, t5));
    DeleteTree(t1);
    DeleteTree(t2);
    DeleteTree(t3);
    return EXIT_SUCCESS;
}
