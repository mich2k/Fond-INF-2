#include <stdlib.h>

#include "tree_int.h"

extern int CountDominant(const Node*);

extern int CountDominant(const Node* t) {
    if (IsEmptyTree(t) || IsLeafTree(t))
        return 0;
    int dom_cont = 0;
    if (!IsEmptyTree(t->right) && !IsEmptyTree(t->left)) {
        ElemType l = t->left->value;
        ElemType r = t->right->value;
        if (*GetRootValueTree(t) >= l + r)
            dom_cont = 1;
    }

    return dom_cont + CountDominant(LeftTree(t)) + CountDominant(RightTree(t));
}

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[3], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())));
    int ris = CountDominant(tree);
    WriteStdoutInOrderTree(tree);
    DeleteTree(tree);
    return EXIT_SUCCESS;
}