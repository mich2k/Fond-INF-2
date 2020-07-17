#include <stdbool.h>
#include <stdlib.h>
#include "tree_int.h"

void rec(Node* t, bool* ret) {
    if(IsLeafTree(t) || *ret == false)
        return;
    //printf("%d ", *GetRootValueTree(t));
    if (!IsEmptyTree(t->left)) {
        if (!(t->left->value <= t->value))
            *ret = false;
    }
    if (!IsEmptyTree(t->right)) {
        if (!(t->right->value > t->value))
            *ret = false;
    }
    rec(LeftTree(t),ret);
    rec(RightTree(t),ret);
}

bool bst_check(Node* t) {
    bool ret = true;
    rec(t, &ret);
    return ret;
}

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(  // albero NON BST
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[7], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[3], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())));
    Node* bst_tree = CreateRootTree(  // albero NON BST
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[1], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[7], CreateRootTree(&v[6], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())));
    WriteStdoutInOrderTree(tree);
    printf("\n--> %d\n", bst_check(tree));
    WriteStdoutInOrderTree(bst_tree);
    printf("\n--> %d\n", bst_check(bst_tree));
    DeleteTree(tree);
    return EXIT_SUCCESS;
}