#include "tree_int.h"
#include <stdlib.h>
extern void ExpressionTree(Node* t);

typedef struct element {
    char op; 
    int  vl;

    bool is_op;
}element;

void ExpressionTree(Node* t){

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
    ElemType max = *BstTreeMax(tree);
    DeleteTree(tree);
    return EXIT_SUCCESS;
}