#include <stdlib.h>
#include "list_int.h"

void sorted_insert( Item** root, 
                   Item* new_element) 
{ 
    Item* current; 
    if (*root == NULL 
        || (*root)->value 
               >= new_element->value) { 
        new_element->next = *root; 
        *root = new_element; 
    } 
    else { 
        current = *root; 
        while (current->next != NULL            // CERC0 IL PRIMO VALORE DOVE (valore_nuovo < current), LO
               && current->next->value < new_element->value) {        // DEVO QUINDI INSERIRE PRIMA DI QUELLO
            current = current->next; 
        } 
        new_element->next = current->next;             // UNA VOLTA TROVATO VADO A SWITCHARE
        current->next = new_element;                   // LE POSIZIONI PUNTATE INSERENDOLO
    } 
} 

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Item* m = CreateEmptyList();
    m = sorted_insert(&arr[3], m);
    m = sorted_insert(&arr[9], m);
    m = sorted_insert(&arr[8], m);
    m = sorted_insert(&arr[1], m);
    m = sorted_insert(&arr[9], m);
    m = sorted_insert(&arr[6], m);
    m = sorted_insert(&arr[7], m);
    m = sorted_insert(&arr[2], m);
    WriteStdoutList(m);
    return EXIT_SUCCESS;
}
