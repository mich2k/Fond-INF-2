/*
extern tree Tree2Bst(tree t);

La funzione prende in input un albero binario di interi t. La funzione deve
attraversare l’albero t utilizzando una visita in pre-ordine e costruire con i
suoi elementi un nuovo albero binario BST (Binary Search Tree) sempre di interi
con il seguente criterio: i figli di sinistra di un nodo devono essere sempre
minori del padre, i figli di destra devono essere maggiori o uguali al padre. Se
l’albero t è vuoto la funzione deve ritornare un BST vuoto.

*/
#include <stdlib.h>

#include "tree_int.h"

extern tree Tree2Bst(tree t);

// la soluzione è nelle librerie vecchie dei prof

tree bst_insert(const element *e, tree t) {
    if (IsEmpty(t)) {
        return ConsTree(e, EmptyTree(), EmptyTree());
    }
    tree root = t;

    while (true) {
        if (*e < *GetRoot(t)) {
            if (IsEmpty(Left(t))) {
                t->left = ConsTree(e, EmptyTree(), EmptyTree());
                break;
            }
            else {
                t = Left(t);
            }
        }
        else {
            if (IsEmpty(Right(t))) {
                t->right = ConsTree(e, EmptyTree(), EmptyTree());
                break;
            }
            else {
                t = Right(t);
            }
        }
    }

    return root;
}


int main(void) {
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    tree dx = ConsTree(&v[3], ConsTree(&v[6], EmptyTree(), EmptyTree()),
                       ConsTree(&v[8], EmptyTree(), EmptyTree()));
    tree sx = ConsTree(&v[9], EmptyTree(), EmptyTree());
    tree nodo = ConsTree(&v[5], sx, dx);
}