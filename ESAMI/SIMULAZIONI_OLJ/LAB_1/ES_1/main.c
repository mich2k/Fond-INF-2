#include <stdlib.h>
#include <stdio.h>
extern void FrazioneEgizia(int n, int d);


int main(void){

    int
        n = 2,
        d = 4;

    FrazioneEgizia(n,d);
    return EXIT_SUCCESS;
}