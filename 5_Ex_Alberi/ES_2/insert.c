#include <stdlib.h>

#include "tree_int.h"

extern Node* BstInsert(const ElemType*, Node*);
extern void BstInsertRec(const ElemType* e, Node* n);

void BstInsertRec(const ElemType* e, Node* n) {

    // NON FUNZIONA

    if (ElemCompare(e, GetRootValueTree(n)) >= 0) {
        BstInsertRec(e, RightTree(n));
        if (IsEmptyTree(n)) {
            ElemType r = *GetRootValueTree(n);
            n->right = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
            return;
        }
    } else {
        BstInsertRec(e, LeftTree(n));
        if (IsEmptyTree(n)) {
            n->left = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
            return;
        }
    }
}

Node* BstInsert(const ElemType* e, Node* n) {
    if (IsEmptyTree(n))
        return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
    else {
        Node* root_pos = n;
        BstInsertRec(e, n);
        return root_pos;
    }
}

// INPUT ALBERO BST

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Node* tree = CreateRootTree(
        &v[12],
        CreateRootTree(
            &v[4], CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[11], CreateRootTree(&v[7], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[8], CreateEmptyTree(), CreateEmptyTree())));

    WriteStdoutInOrderTree(tree);  // BST
    BstInsert(&v[10], tree);
    WriteStdoutInOrderTree(tree);  // BST
    DeleteTree(tree);
    return EXIT_SUCCESS;
}