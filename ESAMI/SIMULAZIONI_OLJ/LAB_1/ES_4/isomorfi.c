#include <stdlib.h>
#include "tree_int.h"

// mi scoccio

bool StessaStruttura(const Node* t1, const Node* t2) {
    if (IsEmptyTree(t1) && !IsEmptyTree(t2))
        return false;
    if (!IsEmptyTree(t1) && IsEmptyTree(t2))
        return false;
    if (!IsLeafTree(t1) && !IsLeafTree(t2) &&(t1->right->value == t2->left->value) &&

        !StessaStruttura(t1->right, t2->left))
        return false;
    //if ((t1->left != NULL || t2->left != NULL) &&
     //   !StessaStruttura(t1->left, t2->left))
      //  return false;
    return true;
}

bool rec(const Node* t1, const Node* t2) {}

bool Isomorfi(const Node* t1, const Node* t2) {
    if (IsEmptyTree(t1) && IsEmptyTree(t2))
        return true;
    if (IsEmptyTree(t1) && !IsEmptyTree(t2))
        return false;
    if (!IsEmptyTree(t1) && IsEmptyTree(t2))
        return false;
    return rec(t1, t2);
}
