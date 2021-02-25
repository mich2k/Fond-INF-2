#include <stdbool.h>
#include <stdlib.h>
#include "tree_int.h"

void rec(Node* t1, Node* t2, bool* flag) {
    if (IsEmptyTree(t1) && IsEmptyTree(t2))
        return;
    if ((IsEmptyTree(t1) ^ IsEmptyTree(t2)) ||
        (*GetRootValueTree(t1) != *GetRootValueTree(t2))) {
        *flag = false;
        return;
    }
    rec(t1->left, t2->left, flag);
    rec(t1->right, t2->right, flag);
}

bool check_trees(Node* t1, Node* t2) {
    bool flag = true;
    rec(t1, t2, &flag);
    return flag;
}

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* t1 = CreateRootTree(
        &arr[1],
        CreateRootTree(
            &arr[5],
            CreateRootTree(&arr[1], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[3], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[9],
            CreateRootTree(&arr[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[5], CreateEmptyTree(), CreateEmptyTree())));
    Node* t2 = CreateRootTree(
        &arr[1],CreateRootTree(&arr[2],NULL,NULL), CreateRootTree(&arr[3], NULL,NULL));
    stampa_albero(t1);
    stampa_albero(t2);
    printf("\n--> %d", check_trees(t1, t2));
    printf("\n--> %d", check_trees(t1, t1));
    return EXIT_SUCCESS;
}