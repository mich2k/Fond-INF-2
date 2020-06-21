#include <stdlib.h>
#include "tree_int.h"

extern int CountDominant (const Node*);

extern int CountDominant (const Node* t){


}




int main(void) {

    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(
        &v[1],
        CreateRootTree(
            &v[2], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateEmptyTree()),
        CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()));

    
    WriteStdoutInOrderTree(tree);

    return EXIT_SUCCESS;
}