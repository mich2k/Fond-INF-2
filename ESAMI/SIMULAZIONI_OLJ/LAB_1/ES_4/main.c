#include <stdbool.h>
#include <stdlib.h>
#include "tree_int.h"
extern bool Isomorfi(const Node* t1, const Node* t2);

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[7], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[1], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())));
    Node* tree_2 = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[1], CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[2], CreateRootTree(&v[10], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[7], CreateEmptyTree(), CreateEmptyTree())));
    WriteStdoutInOrderTree(tree);
    WriteStdoutInOrderTree(tree_2);
    printf("\n\n-> %d\n", StessaStruttura(tree, tree_2));
    return EXIT_SUCCESS;
}