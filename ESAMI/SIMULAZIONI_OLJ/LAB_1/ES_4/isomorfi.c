#include <stdlib.h>
#include "tree_int.h"
extern bool Isomorfi(const Node* t1, const Node* t2);

bool iso_check(const Node* t1, const Node* t2) {
    if ((t1->right != NULL || t2->right != NULL) &&
        !StessaStruttura(t1->right, t2->right))
        return false;
    if ((t1->left != NULL || t2->left != NULL) &&
        !StessaStruttura(t1->left, t2->left))
        return false;
    return true;
}

bool Isomorfi(const Node* t1, const Node* t2) {
    if (IsEmptyTree(t1) && IsEmptyTree(t2))
        return true;
    if (IsEmptyTree(t1) && !IsEmptyTree(t2))
        return false;
    if (!IsEmptyTree(t1) && IsEmptyTree(t2))
        return false;
    return iso_check(LeftTree(t1), LeftTree(t2), RightTree(t1), RightTree(t2));
}
