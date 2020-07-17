#include <stdbool.h>
#include <stdlib.h>
#include "tree_int.h"

bool rec(Node* t){
    if(IsLeafTree(t))
        return;
    printf("%d ", *GetRootValueTree(t));
    if(!(t->left->value <= t->value && t->right->value > t->value ))
        return false;
    rec(LeftTree(t));
    rec(RightTree(t));
    return true;
}

bool bst_check(Node* t) {
    return rec(t);
}

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(    // albero NON BST
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[7], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[3], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())));
    printf("\n--> %d\n", bst_check(tree));
    WriteStdoutInOrderTree(tree);
    DeleteTree(tree);
    return EXIT_SUCCESS;
}