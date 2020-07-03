#include "tree_int.h"
#include <stdlib.h>
#include <stdio.h>
extern int PreOrder(Node* t);

/*
Nel file preorder.c definire la funzione corrispondente alla seguente dichiarazione:

extern int PreOrder(tree t);
La funzione prende in input un albero di int che deve essere attraversato in pre-ordine e stampato a video (stdout). La funzione deve ritornare la somma delle chiavi contenute nell'albero. Il formato dell'output deve essere il seguente:

key1 <spazio> key2 <spazio> key3 <spazio> ...
Sia dato ad esempio l'albero seguente:


La funzione dovrebbe produrre l'output 6 12 7 4 5 e ritornare 34.
*/

void recPreOrder(Node*t, int* ris){
    if(IsEmptyTree(t))
        return;
    printf("%d ", *GetRootValueTree(t));
    *(ris)+=*GetRootValueTree(t);
    recPreOrder(LeftTree(t), ris);
    recPreOrder(RightTree(t), ris);
}

int PreOrder(Node* t){
    int ris = 0;
    recPreOrder(t, &ris);
    return ris;
}

int main(void) {
    ElemType v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* tree = CreateRootTree(
        &v[6],
        CreateRootTree(
            &v[2], CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[9], CreateEmptyTree(), CreateEmptyTree())),
        CreateRootTree(
            &v[3], CreateRootTree(&v[4], CreateEmptyTree(), CreateEmptyTree()),
            CreateRootTree(&v[3], CreateEmptyTree(), CreateEmptyTree())));
    WriteStdoutPreOrderTree(tree);
    WriteStdoutInOrderTree(tree);
    printf("\ntot:\t%d\n", PreOrder(tree));
    DeleteTree(tree);
    return EXIT_SUCCESS;
}
