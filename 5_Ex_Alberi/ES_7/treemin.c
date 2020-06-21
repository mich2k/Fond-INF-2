#include "tree_int.h"
#include <stdlib.h>

extern const ElemType* MinTree(const Node*);
void TreeMinRec(const Node*, ElemType*);

void TreeMinRec(const Node* n, ElemType* min){
    if(IsEmptyTree(n))
        return;
    if(n->value < *min)
        *min = (ElemType) n->value;
    TreeMinRec(LeftTree(n), min);
    TreeMinRec(RightTree(n), min);
}

const ElemType* MinTree(const Node* n){     // In realtà è MinTree e non TreeMin, moortacci tua grana padano
    if(IsEmptyTree(n))
        return NULL;
    ElemType* min = (ElemType*) GetRootValueTree(n);
    TreeMinRec(n,min);
    return min;
}


// ALBERO NON BST, COME RICHIESTO DALLA TRACCIA

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
    ElemType min = *TreeMin(tree);
    DeleteTree(tree);
    return EXIT_SUCCESS;
}