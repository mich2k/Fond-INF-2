/** @file
In questo file sono definite le primitive delle liste disponibili 
per la simulazione del 29/05/2019
*/
#ifndef LISTE_INDIRIZZO_H_
#define LISTE_INDIRIZZO_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct indirizzo {
    char via[50];
    int civico;
    char citta[30];
}indirizzo;

typedef indirizzo element;

typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item* list;

/** @brief La funzione Emptylist ritorna una lista vuota (NULL).
 
@returns Lista vuota (NULL).

*/
list EmptyList();


/** @brief La funzione Cons aggiunge un nuovo elemento in testa ad una list.

@param e Elemento da aggiugnere.
@param l Lista da aggiornare con il nuovo elemento, puo' essere una lista vuota (NULL).

@returns Lista aggiornata.
*/
list Cons(const element *e, list l);

/** @brief Controlla se una lista e' vuota.

@param l Lista da controllare.

@returns true se la lista e' vuota, false altrimenti.
*/
bool IsEmpty(list l);

/** @brief Ritorna l'elemento in testa ad una lista senza eliminarlo.

@param l Lista da cui estrarre l'elemento in testa. Non puo' essere una lista vuota.

@returns Elemento in testa alla lista.
*/
element Head(list l);

/** @brief Ritorna una lista privata dell'elemento in testa. N.B. la funzione non dealloca la memoria occupata dall'elemento head della lista.

@param l Lista da cui eliminare l'elemento in testa. Non puo' essere una lista vuota.

@return Lista ottenuta dopo l'eliminazione dell'elemento in testa. Puo' essere una lista vuota.
*/
list Tail(list l);

/** @brief Ritorna una copia di un elemento e.

@param e Elemento da copiare.

@returns Copia dell'elemento.
*/
element Copy(const element *e);

/** @brief Aggiunge un elemento in coda ad una lista (anche vuota) e 
ritorna la lista risultante.

@param l Lista a cui aggiungere l'elemento. Può essere una lista vuota (NULL).
@param e Elemento da aggiungere alla lista l.

@returns Lista ottenuta aggiungendo l'elemento e alla lista l.
*/
list InsertBack(list l, const element *e);

/** @brief Libera la memoria occupata da un lista.

@param l Lista di cui liberare la memoria.
*/
void FreeList(list l);

#endif // !LISTE_INDIRIZZO_H_

