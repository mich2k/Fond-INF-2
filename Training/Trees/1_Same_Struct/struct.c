#include <stdlib.h>
#include "tree_int.h"

bool same_struct(Node* t1, Node* t2) {
	if ((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL)) return false;
	if ((t1->right != NULL || t2->right != NULL) && !same_struct(t1->right, t2->right)) return false;
	if ((t1->left != NULL || t2->left != NULL) && !same_struct(t1->left, t2->left)) return false;
	return true;
}

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* t1 = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[3], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())));

    Node* t2 = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[3], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())));
    printf("\n---->%d\n", same_struct(t1, t2));
    DeleteTree(t1);
    DeleteTree(t2);
    return EXIT_SUCCESS;
}