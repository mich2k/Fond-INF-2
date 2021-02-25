#include "tree_int.h"
#include <stdlib.h>


void count(Node* tree, size_t n){
    if(IsEmptyTree(tree))
        return;
    int val = *GetRootValueTree(tree);
    if(IsLeafTree(tree) && *GetRootValueTree(tree) > n)
        printf("%d", *GetRootValueTree(tree));
    count(LeftTree(tree), n + 1);
    count(RightTree(tree), n + 1);
}

int main(void){
    ElemType arr[] = {0,1,2,3,4,5,6,7,8,9,10};
    Node* tree = CreateRootTree(&arr[1],
        CreateRootTree(&arr[3],CreateRootTree(&arr[1],CreateEmptyTree(),CreateEmptyTree()),CreateRootTree(&arr[2],CreateEmptyTree(),CreateEmptyTree())),
        CreateRootTree(&arr[4],CreateRootTree(&arr[3],CreateEmptyTree(),CreateEmptyTree()),CreateRootTree(&arr[5],CreateEmptyTree(),CreateEmptyTree())));
    WriteStdoutPreOrderTree(tree);
    stampa_albero(tree);
    size_t n = 0;
    puts("");
    count(tree, 0);
    return EXIT_SUCCESS;
}