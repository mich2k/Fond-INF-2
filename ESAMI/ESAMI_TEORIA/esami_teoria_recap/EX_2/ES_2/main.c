#include "list_int.h"
#include <stdlib.h>
// SAVE : SORTED INSERT IN LISTA
void sortedInsert( Item** root, 
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

void f(Item* lista){
    //le liste non vanno per puntatori ma per ritorno di puntatori       //oppure per doppi puntatori
    size_t n = 4;
    float avg = 0;
    for(size_t i = 0; i < n; i++){
            int val;
            printf("Inserire %d valore: ", i + 1);
            scanf(" %d", &val);
            avg+=val;
            sortedInsert(&lista, InsertBackList(CreateEmptyList(), &val));
    } 
    avg/=n;
    WriteStdoutList(lista);
    printf("-- > media: %f\n", avg);
    for(size_t i = 0; i < n; i++){
        if(*GetHeadValueList(lista) > avg)
            printf("%d\n", *GetHeadValueList(lista));
        lista=GetTailList(lista);
    }
}

int main(void){
    f(NULL);
    return EXIT_SUCCESS;
}