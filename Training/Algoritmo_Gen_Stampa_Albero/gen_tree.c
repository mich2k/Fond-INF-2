#include "tree_int.h"
#include <stdlib.h>

void ricorsione(Node* n) {
    if (IsEmptyTree(n)) {
        return;
    }

    ricorsione(LeftTree(n));

    printf("\t %d", *GetRootValueTree(n));

    fflush(stdout);

    ricorsione(RightTree(n));
}

//  ALGORITMO ESPLORAZIONE ALBERO INTERO:

/*
        SE L ALBERO E VUOTO
            RITORNA

        RICORSIONE (LEFT)

        RICORSIONE (RIGHT)
*/


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
    ricorsione(tree);
    return EXIT_SUCCESS;
}

/*
!
    La ricorsione è l unico modo per stampare o considerare un albero ambo
    le foglie / sotto alberi
    Un approccio procedurale è considerabile solo in un algoritmo selettivo

*/