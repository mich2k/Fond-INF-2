#include <stdlib.h>
#include <stdio.h>


int* Monete(int*t, int size, int b){


}

int main (void){
    int v[] = {50,20,10,5,2,1};
    int n = sizeof(v)/sizeof(*v);
    int* ris = Monete(v, n, 2);
    return EXIT_SUCCESS;
}

/*
    è necessario sia già ordinato in modo decrescente
    complessità da non ordinato O(nlogn)
    complessità da ordinato O(n)
*/
