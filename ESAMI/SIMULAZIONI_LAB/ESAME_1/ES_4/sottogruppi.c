/*
        Nel file sottogruppi.c definire la funzione corrispondente alla seguente
        dichiarazione:
        
        extern int Sottogruppi(const char *filename, int k);
        
        La funzione prende in input il nome di un file di testo (filename) e un intero
        k. Il file contenente i nomi degli alunni di una classe separati da \n. Il file
        contiene in totale n nomi (senza spazi) i quali sono costituiti al massimo da 19
        caratteri. Il numero n non è noto a priori, ma si deve determinare leggendo il
        file. La funzione deve aprire il file e leggerne il contenuto e, utilizzando un
        algoritmo di backtracking ricorsivo, individuare tutti i possibili sottogruppi
        di K studenti con i seguenti vincoli:
        
           1. due nomi che iniziano con la stessa lettera non devono mai appartenere
        allo stesso sottogruppo. Esempio: Andrea e Aldo hanno la stessa iniziale “A”,
        quindi non possono appartenere allo stesso sottogruppo.
           2. due nomi con iniziali consecutive non devono mai appartenere allo stesso
        gruppo. Esempio: Bianca e Alfredo hanno iniziali consecutive nell’alfabeto,
        quindi non possono mai appartenere allo stesso sottogruppo.
           3. l’ordine è significativo. Esempio (k = 2) i gruppi { Andrea, Carlo } e {
        Carlo, Andrea } sono da considerarsi gruppi distinti e quindi dovrebbero
        comparire entrambi nella soluzione.
        
        La funzione deve stampare su standard output tutti i possibili sottogruppi, uno
        per riga con il seguente formato:
        
        { Nome1, Nome2, …, NomeK }
        
        La funzione deve quindi ritornare il numero di soluzioni trovate. Se non è
        possibile aprire il file o se il valore k in input è minore o uguale a 0 o
        maggiore di n la funzione deve ritornare -1.
        
        Si consiglia di utilizzare una funzione ausiliaria per implementare il
        backtracking. Si consiglia inoltre di leggere i dati da file fuori dalla
        funzione ricorsiva.
*/

extern int Sottogruppi(const char*, int);

#define NAME_LEN 19

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

int Sottogruppi(const char* filename, int k) {
    if (k <= 0)
        return -1;
    FILE* f = fopen(filename, 'r');
    if (f == NULL)
        return -1;
    char** nomi = NULL;
    uint32_t n = 0;
    while(true){
        //fgetc(f);
        if(feof(f) || ferror(f))
            break;
        //fseek(f,-1, SEEK_CUR);
        ++n;
        nomi = realloc(nomi, sizeof(*nomi) * n);
        *(nomi + (n-1)) = malloc(sizeof(char) * NAME_LEN);
        fscanf(f, "%s", nomi[n-1]);
    }
    return k;
}

int main(void) {
    Sottogruppi("/home/mich/Scrivania/Fond-INF-2/ESAMI/SIMULAZIONI_LAB/ESAME_1/ES_4/es4_input1.inp", 1);
    return EXIT_SUCCESS;
}