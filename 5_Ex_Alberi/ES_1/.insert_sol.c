#include "tree_int.h"

#include "tree_int.h"

Node* BstInsert(const ElemType *e, Node *n)
{
    if (IsEmptyTree(n)) {
        return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
    }

    Node *root = n;

    while (!IsEmptyTree(n)) {
        if (ElemCompare(e, GetRootValueTree(n)) <= 0) {
            if (IsEmptyTree(LeftTree(n))) {
                n->left = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
                n = LeftTree(n);
            }
            n = LeftTree(n);
        }
        else {
            if (IsEmptyTree(RightTree(n))) {
                n->right = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
                n = RightTree(n);
            }
            n = RightTree(n);
        }
    }

    return root;
}

int main(void) 
{
    ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Node* n = CreateRootTree(&v[5], 
        CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()),
        CreateRootTree(&v[10], CreateEmptyTree(), CreateEmptyTree())
        );


    DeleteTree(n);
}

