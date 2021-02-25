#include <stdlib.h>
#include "tree_int.h"

void rec(Node* t, int* count){
    if(IsEmptyTree(t))
        return;
    if(!IsLeafTree(t) && *GetRootValueTree(t) > (*GetRootValueTree(LeftTree(t))) + (*GetRootValueTree(RightTree(t))))
        (*count)++;
    rec(LeftTree(t),count);
    rec(RightTree(t), count);
}

int ContaDominanti(Node* t){
    int count = 0;
    rec(t,&count);
    return count;
}

int main(void) {
    Node* t = CreateEmptyTree();
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t = CreateRootTree(
        &arr[1],
        CreateRootTree(
            &arr[5],
            CreateRootTree(&arr[1], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[2], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[9],
            CreateRootTree(&arr[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[5], CreateEmptyTree(), CreateEmptyTree())));
    stampa_albero(t);
    printf("\n---> %d", ContaDominanti(t));
    return EXIT_SUCCESS;
}
