#include <stdlib.h>
#include "tree_int.h"

void vmedio(Node* t, size_t n, int path_sum) {
    if (IsEmptyTree(t))
        return;
    if (IsLeafTree(t))
        printf("\n%f", (float)path_sum / n);
    else
        path_sum += *GetRootValueTree(t);
    vmedio(LeftTree(t), n + 1, path_sum);
    vmedio(RightTree(t), n + 1, path_sum);
}

int main(void) {
    Node* t = CreateEmptyTree();
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    t = CreateRootTree(
        &arr[1],
        CreateRootTree(
            &arr[3],
            CreateRootTree(&arr[1], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[2], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &arr[4],
            CreateRootTree(&arr[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&arr[5], CreateEmptyTree(), CreateEmptyTree())));
    stampa_albero(t);
    vmedio(t, 0, 0);
    return EXIT_SUCCESS;
}
