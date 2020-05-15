#include <stdlib.h>
#include <ctype.h>
#include "list_int.h"

Item* LoadList(const char*filename){
    FILE* f = fopen(filename, "r");
    if(f == NULL)
        return NULL;
    if(!inprint(fgetc(f))){
        fclose(f);
        return NULL;
    }
    

}

int main ( void ){
    char* filename = 
}

/*
    

*/