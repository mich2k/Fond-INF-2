#include <stdlib.h>
int Prodotto(int a, int b);
int Prodotto(int a, int b){
    b--;
    if(b>0)
        return a+Prodotto(a, b);
}

void main (void){
    int ris = Prodotto(5,4);
}