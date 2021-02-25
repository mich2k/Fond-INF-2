#include "tree_int.h"
#include <stdbool.h>
#include <stdlib.h>

void same_root_check(Node* t1, Node* t2, bool* flag){
    // assumo che i due alberi siano già equivalenti, or inutile
    if(IsEmptyTree(t1) || IsEmptyTree(t2))
        return;
    if(*GetRootValueTree(t1) != *GetRootValueTree(t2))
        *flag = false;
    same_root_check(LeftTree(t1), LeftTree(t2), flag);
    same_root_check(RightTree(t1),RightTree(t2), flag);
}


int main(void) {
    Node* t1 = CreateEmptyTree();
    Node* t2 = CreateEmptyTree();
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t1 = CreateRootTree(
        &arr[1],
        CreateRootTree(
            &arr[3],
            CreateRootTree(&arr[1], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[2], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[4],
            CreateRootTree(&arr[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[5], CreateEmptyTree(), CreateEmptyTree())));
    t2 = CreateRootTree(
        &arr[1],
        CreateRootTree(
            &arr[3],
            CreateRootTree(&arr[1], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[2], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[4],
            CreateRootTree(&arr[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[5], CreateEmptyTree(), CreateEmptyTree())));
    Node* t3 = CreateRootTree(
        &arr[6],
        CreateRootTree(
            &arr[5],
            CreateRootTree(&arr[9], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[11], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[1],
            CreateRootTree(&arr[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[5], CreateEmptyTree(), CreateEmptyTree())));
    stampa_albero(t1);
    stampa_albero(t2);
    bool* flag = true;  
    same_root_check(t1,t2,&flag);       // t1 && t2 renderanno flag true, ovvero same root
    printf("\nsame root check ---> %d (1 = true, 0 = false)\n", flag);
    DeleteTree(t1);
    DeleteTree(t2);
    DeleteTree(t3);
    return EXIT_SUCCESS;
}
