#include "tree_int.h"
#include <stdlib.h>

extern Node* BstInsert(const ElemType*, Node*);
extern Node* BstInsertRec(const ElemType*e, Node*n;

Node* BstInsertRec(const ElemType*e, Node*n){
    
}

Node* BstInsert(const ElemType*e, Node*n){
    if(IsEmptyTree(n))
        return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
    else
        return BstInsertRec(e, n);
}


// INPUT ALBERO BST

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[4], CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[5], CreateRootTree(&v[7], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[8], CreateEmptyTree(), CreateEmptyTree())));

    WriteStdoutInOrderTree(tree);   //BST
    DeleteBstNode(tree, &v[8]);
    WriteStdoutInOrderTree(tree);   //BST
    DeleteTree(tree);
    return EXIT_SUCCESS;
}