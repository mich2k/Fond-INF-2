#include "gioielli.h"

bool readline(Gioiello* x, FILE* f) {
    uint32_t i;
    uint32_t cont;
    for (cont = 1;; cont++) {
        char isvalid = fgetc(f);
        if (cont != 1 && !(isprint(isvalid)) || (feof(f) || ferror(f))) {
            if (isvalid == '\n')
                break;
            else
                fseek(f, -1, SEEK_CUR);
        } else
            fseek(f, -1, SEEK_CUR);
        char* s = NULL;
        i = 0;
        for (; !isspace(fgetc(f)); ++i) {
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
    }
}

int main(void) {
    char* filename = "gioielli_1.inp";
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        return EXIT_FAILURE;
    // <codice><spazio><peso><spazio><prezzo><a capo>
    Gioiello* x = malloc(sizeof(Gioiello));
    readline(x, f);

    return EXIT_SUCCESS;
}