#include <stdlib.h>
#include <stdio.h>
extern void FrazioneEgizia(int n, int d);


void rec(int n, int d){
    if(d%n==0)
        return;
    int under = d/n;

}

void FrazioneEgizia(int n, int d){
    if(n<=0 || d<=0 || n>=d){
        printf("\n Impossibile convertire la frazione data in frazione egizia.");
        return;
    }
    puts("casca");
    return;
}