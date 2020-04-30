#include "gioielli.h"

Gioiello* read_line(FILE* f, bool* _eof) {
    Gioiello* x = malloc(sizeof(Gioiello));
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
    return x;
}

Gioiello* Gioielli(const char* filename, float b, int* ret_size) {
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        exit(-1);
    Gioiello x[];
    bool _eof = false;
    uint32_t i = 0;
    while (_eof != true) {
        x[i] = read_line(f, &_eof);
        ++i;
    }

    return x;
}

int main(void) {
    int retsize;
    const char* filename = "gioielli_1.inp";
    Gioielli(filename, (float)121, &retsize);
    // <codice><spazio><peso><spazio><prezzo><a capo>
    return EXIT_SUCCESS;
}