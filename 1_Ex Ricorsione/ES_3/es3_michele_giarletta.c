#include <stdio.h>
#include <stdlib.h>

int Minimo(int *vec, int len);

int Minimo(int *vec, int len){
    int _min;
    --len;
    if(len == 0)
        return *(vec);
    _min = Minimo(vec,len);
    if(_min < vec[len])
        return _min;
    return vec[len];
}
void main ( void ){
    int data [] = {
        17,  2,  3
        };
    int ris = Minimo(data, 3);
}