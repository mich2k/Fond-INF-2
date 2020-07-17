#include <stdlib.h>
#include "list_int.h"

#include <ctype.h>

void del_nodes(Item* l) {
    Item* temp = CreateEmptyList();
    size_t cont = 0;
    while (!IsEmptyList(l)) {
        if (cont != 0) {
            if (!IsEmptyList(l->next)) {
                if (l->valore == (l->prev->valore + l->next->valore)) {
                    l->prev->next = l->next;
                    l = GetTailList(l);
                }
            } else {  // ultimo elem, solo predecessore
                if (l->valore == l->prev->valore) {
                    l->prev->next = (Item*)NULL;
                    l = GetTailList(l);
                }
            }
        } else {  // primo elemento, solo successore
            if (l->valore == l->next->valore) {
                l = GetTailList(l);
                l->prev = (Item*)NULL;
            }
        }
    }
}

// !! ESERCIZIO CONCETTUALE, DEFINIZIONI DIFFERENTI, NON REPLICABILE NEL
// COMPILATORE

int main(void) {
    Item* l1 =
        LoadList("/home/mich/Scrivania/Fond-INF-2/4_Ex_Liste/data_02.inp");
    Item* l2 =
        LoadList("/home/mich/Scrivania/Fond-INF-2/4_Ex_Liste/data_03.inp");
    WriteStdoutList(l1);
    WriteStdoutList(l2);
    //_CrtDumpMemoryLeaks();
    return EXIT_SUCCESS;
}