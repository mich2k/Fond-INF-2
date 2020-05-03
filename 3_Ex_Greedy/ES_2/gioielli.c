#include "gioielli.h"

void _greedysort(Gioiello* x, uint32_t lines) {
    Gioiello* temp = malloc(lines * sizeof(Gioiello));

    for (uint32_t i = 0; i < lines; i++) {
        for (uint32_t j = 0; j < lines - i; j++) {
            float app_curr = (x + j)->peso / (x + j)->prezzo;
            float app_next = (x + j + 1)->peso / (x + j + 1)->prezzo;
            if (app_curr > app_next) {
                memcpy((temp), (x + j), sizeof(Gioiello));
                memcpy((x + j), (x + j + 1), sizeof(Gioiello));
                memcpy((x + j + 1), temp, sizeof(Gioiello));
            }
        }
    }
    free(temp);
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
        while (true) {
            char c = fgetc(f);
            if(c == '\n')
                c = fgetc(f);
            if (!(isprint(c)) || c == ' ')
                break;
            if ((feof(f) || ferror(f))) {
                *_eof = true;
                break;
            }
            //fseek(f, -1, SEEK_CUR);
            s = realloc(s, i + 1);
            s[i] = c;
            ++i;
        }
        switch (cont) {
            case 1:
                x->codice = (int)strtol(s, NULL, 10);
                free(s);
                break;
            case 2:
                x->peso = (float)strtod(s, NULL);
                free(s);
                break;
            case 3:
                x->prezzo = (float)strtod(s, NULL);
                free(s);
                return;
            default:
                exit(-1);
        }
        ++cont;
    }
}

Gioiello* Gioielli(const char* filename, float b, int* ret_size) {
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        return NULL;
    bool _eof = false;
    uint32_t lines = totlines(f);
    fseek(f, 0, 0);
    Gioiello* sorted_arr = malloc(lines * sizeof(Gioiello));
    Gioiello* ris = malloc(lines * sizeof(Gioiello));
    Gioiello* curr = malloc(sizeof(Gioiello));
    float current = 0;
    uint32_t cont = 0;
    int i = 0;
    while (_eof != true) {
        read_line(f, &_eof, curr);
        sorted_arr[i] = *curr;
        i++;
    }
    //_greedysort(sorted_arr, lines);
    for (i = lines - 1; i >= 0; --i) {
        if (current + (sorted_arr + i)->prezzo <=
            b) {  // SVOLGIMENTO ALG. GREEDY
            current += (sorted_arr + i)->prezzo;
            ris[cont] = sorted_arr[i];
            ++cont;
        }
        *ret_size = cont;
    }
    ris = realloc(ris, *ret_size * sizeof(Gioiello));
    return ris;
}

int main(void) {
    int retsize;
    const char* filename = "gioielli_2.inp";
    Gioiello* ris = Gioielli(filename, (float)121, &retsize);
    for (uint32_t k = 0; k < retsize; ++k)
        fprintf(stdout, "\n%d %.2f %.2f", (ris + k)->codice, (ris + k)->peso,
                (ris + k)->prezzo);
    puts("");
    return EXIT_SUCCESS;
}