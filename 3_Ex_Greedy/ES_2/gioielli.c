#include "gioielli.h"

void _greedysort(Gioiello* x, uint32_t lines){
    for(uint32_t i = 0; i < lines; ++i){
        
    }
}

uint32_t totlines(FILE* f) {
    uint32_t lines = 0;
    while (true) {
        char c = fgetc(f);
        if (c == '\n')
            ++lines;
        if (feof(f) || ferror(f))
            return lines + 1;
    }
}

void read_line(FILE* f, bool* _eof, Gioiello* x) {
    uint32_t i;
    uint32_t cont = 1;
    while (true) {
        char isvalid = fgetc(f);
        if (cont != 1 && !(isprint(isvalid)) || (feof(f) || ferror(f))) {
            if (isvalid == '\n')
                break;
            else if (feof(f) || ferror(f)) {
                *_eof = true;
                break;
            }
        } else
            fseek(f, -1, SEEK_CUR);
        char* s = NULL;
        i = 0;
        for (; !isspace(fgetc(f)); ++i) {
            if ((feof(f) || ferror(f))) {
                *_eof = true;
                break;
            }
            fseek(f, -1, SEEK_CUR);
            s = realloc(s, i + 1);
            s[i] = fgetc(f);
        }
        switch (cont) {
            case 1:
                x->codice = (int)strtol(s, NULL, 10);
                break;
            case 2:
                x->peso = (int)strtol(s, NULL, 10);
                break;
            case 3:
                x->prezzo = (int)strtol(s, NULL, 10);
                break;
            default:
                break;
        }
        ++cont;
    }
    return;
}

Gioiello* Gioielli(const char* filename, float b, int* ret_size) {
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        exit(-1);
    bool _eof = false;
    uint32_t lines = totlines(f);
    fseek(f, 0, 0);

    Gioiello* sorted = calloc(lines,sizeof(Gioiello));  
    Gioiello* unsorted = calloc(lines,sizeof(Gioiello));  
    Gioiello* curr = calloc(1,sizeof(Gioiello));
    uint32_t i = 0;
    float current = 0;
    while (_eof != true){
        read_line(f, &_eof, curr);
        if(current + curr->prezzo <= b){    //SVOLGIMENTO ALG. GREEDY
            current += curr->prezzo;
            sorted[i] = *curr;
            ++i;
            printf("%d \n", curr->codice);
        }
    }
    
    free(sorted);
    free(curr);
    return sorted;
}

int main(void) {
    int retsize;
    const char* filename = "gioielli_1.inp";
    Gioielli(filename, (float)121, &retsize);
    return EXIT_SUCCESS;
}