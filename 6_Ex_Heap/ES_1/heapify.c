#include <stdlib.h>
#include <string.h>  // memcpy

#include "minheap_int.h"

Heap* HeapifyMinHeap(const ElemType* v, size_t v_size);

/*
    Un heap binario è un albero con diverse proprietà
    tipo, ogni nodo è minore/maggiore dei suoi figli
    questo varia se è un minHeap o maxHeap
*/

// in questo corso l heap sarà un vettore e non un bin tree

Heap* HeapifyMinHeap(const ElemType* v,
                     size_t v_size) {  // dato un vettore e la sua dimensione
                                       // dobbiamo costruire un albero heap

    Heap* h = CreateEmptyHeap();                 // creo un heap vuoto
    h->size = v_size;                            // numero elementi in un Heap
    h->data = calloc(v_size, sizeof(ElemType));  // Alloco lo spazio per l heap
    memcpy(h->data, v, sizeof(ElemType) * v_size);  // copio v in h->data
    WriteStdoutHeap(h);

    for (int i =v_size; i >= 0; i-=1)
        MoveDownMinHeap(h, i);
    WriteStdoutHeap(h);
    return h;
}

int main(void) {  // per simulare un heap costruiamo un vettore

    ElemType v[] = {4, 6, 1, 2, 12, 23};
    size_t v_size = sizeof(v) / sizeof(v[0]);
    HeapifyMinHeap(v, v_size);
    return EXIT_SUCCESS;
}