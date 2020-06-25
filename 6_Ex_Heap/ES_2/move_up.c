#include "minheap_int.h"
#include <stdlib.h>
#include <string.h>

/*
    La moveup si utilizza principalmente quando si vuole aggiungere un nodo
    mentre la movedown quando se ne elimina uno
    entrambe sono necessarie per preservare le proprietà dell Heap
*/

void MoveUpMinHeapRec(Heap*h, int i);
 
void MoveUpMinHeapRec(Heap*h, int i){
    if(i==0)
        return;
    if(ElemCompare())
}

int main(void) {  // per simulare un heap costruiamo un vettore

    ElemType v[] = {4, 6, 1, 2, 12, 23};
    size_t v_size = sizeof(v) / sizeof(v[0]);
    MoveUpMinHeapRec(v, v_size);
    return EXIT_SUCCESS;
}
