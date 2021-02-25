#include <stdbool.h>
#include <stdlib.h>
#include "tree_int.h"

void rec(Node* t, bool* flag) {
    if (IsEmptyTree(t) || IsLeafTree(t))
        return;
    if(!(t->value > t->left->value && t->value < t->right->value)){
        *flag = false;
        return;
    }
}

bool f(Node* t) {
    bool flag = true;
    rec(t, &flag);
    return flag;
}

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* t = NULL;
    t = CreateRootTree(&arr[4], CreateRootTree(&arr[2], NULL, NULL),
                       CreateRootTree(&arr[5], NULL, NULL));
    stampa_albero(t);
    printf("\n---> %d", f(t));
    return EXIT_SUCCESS;
}