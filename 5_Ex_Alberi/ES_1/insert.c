#include <stdlib.h>

#include "tree_int.h"

extern Node* BstInsert(const ElemType* e, Node* n);

Node* BstInsert(const ElemType* e, Node* n) {
    if (IsEmptyTree(n)) {
        return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
    }

    Node* root_pos = n;

    while (!IsEmptyTree(n)) {
        if (ElemCompare(e, GetRootValueTree(n)) <= 0) {
            if (IsEmptyTree(LeftTree(n))) {
                n->left = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
                return root_pos;
            }
            n = LeftTree(n);
        } else {
            if (IsEmptyTree(RightTree(n))) {
                n->right = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
                return root_pos;
            }
            n = RightTree(n);
        }
    }
}

int main(void) {

    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(
        &v[1],
        CreateRootTree(
            &v[2], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateEmptyTree()),
        CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()));

    BstInsert(&v[10], tree);

    WriteStdoutInOrderTree(tree);

    return EXIT_SUCCESS;
}