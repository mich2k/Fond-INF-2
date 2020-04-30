#include "gioielli.h"

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

    struct foo** fooArray = malloc(sizeof(*fooArray) * 5);
    struct foo* newFoo = malloc(sizeof(2));
    fooArray[0] = newFoo;
    struct foo* newFoo2 = malloc(sizeof(3));
    fooArray[1] = newFoo2;

    if (f == NULL)
        exit(-1);
    bool _eof = false;
    uint32_t lines = totlines(f);
    fseek(f, 0, 0);

    Gioiello** x = calloc(lines,sizeof(Gioiello));  // alloco la dimensione di "lines" puntatori a struct
    for(uint32_t k = 0; k < lines; ++k)
        x[k] = malloc(sizeof(Gioiello));            // faccio puntare a ogni x[k] una struct di dimensione Gioiello, così creando un array di puntatori allocati
    uint32_t i = 0;
    while (_eof != true)
        read_line(f, &_eof, x[i]);
    // inizio
    bool* result = calloc(lines, sizeof(bool));
    float current = 0;
    for(uint32_t j = 0; j < lines; ++j){
        current+=x[j]->prezzo;
        if(current <= b)

    }
    for(uint32_t k = 0; k < lines; ++k)
        free(x[k]);
    free(x);
    return x;
}

int main(void) {
    int retsize;
    const char* filename = "gioielli_1.inp";
    Gioielli(filename, (float)121, &retsize);
    // <codice><spazio><peso><spazio><prezzo><a capo>
    return EXIT_SUCCESS;
}