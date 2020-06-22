
/*
Nel file filtra.c definire la funzione corrispondente alla seguente
dichiarazione:

extern list Filtra(list l, const char *citta);

La funzione prende in input una lista di indirizzi (anche vuota) e una citta e
costruisce una nuova lista contenente tutti gli indirizzi che non fatto parte di
quella città. Gli elementi della lista di output devono essere nello stesso
ordine di quella di input. Se la lista è una lista vuota la funzione deve
ritornare NULL. N.B. quando fate la sottomissione della soluzione non dovete
caricare il codice delle primitive, ma solo il codice della funzione Filtra e di
eventuali funzioni ausiliarie.

Per la risoluzione di questo esercizio avete a disposizione le seguenti
definizioni:

typedef struct indirizzo {
  char via[50]; int civico; char citta[30];
} indirizzo;

typedef indirizzo element;

typedef struct list_element {
  element value;
  struct list_element *next;
} item;

typedef item* list;

e le seguenti primitive:

list EmptyList();
list Cons(const element *e, list l);
bool IsEmpty(list l);
element Head(list l);
list Tail(list l);
element Copy(const element *e);
void FreeList(list l);
list InsertBack(list l, const element *e);*/

#include <stdio.h>
#include <stdlib.h>

#include "list_int.h"

typedef struct indirizzo {
    char via[50];
    int civico;
    char citta[30];
} indirizzo;

typedef indirizzo element;

typedef struct list_element {
    element value;
    struct list_element* next;
} item;

extern list Filtra(list, const char*);

list Filtra(list l, const char* citta) {

    if(IsEmptyList(l))
        return NULL;
    

}

int main(void) {
    indirizzo primo = {"via gennaro", 69, "Napoli"};
    indirizzo secondo = {"via esposito", 69, "Modena"};
    indirizzo terzo = {"via ", 69, "Bolo"};

}