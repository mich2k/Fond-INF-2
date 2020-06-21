#include <stdlib.h>

#include "tree_int.h"

extern const ElemType* BstTreeMin(const Node*);

const ElemType* BstTreeMin(const Node* n) {
    if(IsEmptyTree(n))
        return NULL;
    ElemType* min;
    while(!IsLeafTree(n)){
        n=LeftTree(n);
        min = (ElemType*)GetRootValueTree(n);
    }
    return min;
}

// WARNING:   L ALBERO IN ESEMPIO IN QUESTO MAIN, NON E BST!

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
    ElemType min = *BstTreeMin(tree);
    DeleteTree(tree);
    return EXIT_SUCCESS;
}