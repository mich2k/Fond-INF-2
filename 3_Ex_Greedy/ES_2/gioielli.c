#include "gioielli.h"

/*void _greedysort(Gioiello** x, uint32_t lines) {
    Gioiello* temp = malloc(sizeof(Gioiello));
    for (uint32_t i = 0; i < lines - 1; i++) {
        for (uint32_t j = 0; j < lines - i - 1; j++) {
            float curr_att = (x[j]->peso / x[j]->prezzo);
            float curr_succ = (x[j + 1]->peso / x[j + 1]->prezzo);
            if (curr_att > curr_succ) {
                // swap arr[j+1] and arr[i]
                temp = &x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }
    free(temp);
}*/

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

    // Gioiello* sorted = calloc(lines, sizeof(Gioiello));
    Gioiello* ris = calloc(lines, sizeof(Gioiello));
    Gioiello* curr = calloc(1, sizeof(Gioiello));
    uint32_t i = 0;
    float current = 0;
    /*while (_eof != true) {
        read_line(f, &_eof, curr);
        unsorted[i] = *curr;
        i++;
    }
   // _greedysort(unsorted, lines);*/

    while (_eof != true) {
        read_line(f, &_eof, curr);
        if (current + curr->prezzo <= b) {  // SVOLGIMENTO ALG. GREEDY
            current += curr->prezzo;
            ris[i] = *curr;
            ++i;
        }
        *ret_size = i;
    }

    free(curr);
    // return sorted;
    return ris;
}

int main(void) {
    int retsize;
    const char* filename = "gioielli_1.inp";
    Gioiello* ris = Gioielli(filename, (float)121, &retsize);
    for (uint32_t k = 0; k < retsize; ++k)
        fprintf(stdout, "\n%d %.2f %.2f", (ris + k)->codice, (ris + k)->peso,
                (ris + k)->prezzo);
    puts("");
    return EXIT_SUCCESS;
}