/*
Nel file savetree.c definire la funzione corrispondente alla seguente
dichiarazione:

extern bool SaveTree(tree t, const char *filename);

La funzione prende in input un albero di interi t e il nome di un file filename.
Dopo aver aperto il file in modalità scrittura non tradotta, la funzione deve
scorrere l’albero in pre-ordine e scrivere sul file i valori contenuti nei suoi
nodi. I numeri devono essere scritti in formato testuale decimale, nell’ordine
in cui vengono visitati e separati da <spazio>. Se la scrittura va a buon fine
la funzione deve ritornare true. Se non è possibile aprire il file la funzione
deve ritornare false.
*/

#include <stdlib.h>
#include "tree_int.h"  //stdio & stdbool già incluse

void rec_tree(Node* t, FILE* f) {
    if (IsEmptyTree(t))
        return;
    fprintf(f, "%i ", *GetRootValueTree(t));
    rec_tree(LeftTree(t), f);
    rec_tree(RightTree(t), f);
}

bool SaveTree(Node* t, const char* filename) {
    if (!filename)
        return false;
    FILE* f = fopen(filename, "w");
    if (f == NULL || ferror(f))
        return false;
    rec_tree(t, f);
    fclose(f);
    return true;
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
    SaveTree(tree, "file.txt");
    DeleteTree(tree);
    return EXIT_SUCCESS;
}