#include "tree_int.h"
#include <stdlib.h>

extern Node* DeleteBstNode(Node*, const ElemType*);

Node* DeleteBstNode(Node*n, const ElemType*key){


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

    
    DeleteTree(tree);
    return EXIT_SUCCESS;
}