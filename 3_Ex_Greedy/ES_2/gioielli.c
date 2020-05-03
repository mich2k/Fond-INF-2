#include "gioielli.h"

void _greedysort(Gioiello* x, uint32_t lines) {
    Gioiello* temp = calloc(lines, sizeof(Gioiello));
    for (uint32_t i = 0; i < lines; i++) {
        for (uint32_t j = 0; j < lines - i; j++) {
            if(j+1 > lines)
                continue;
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
            return lines;
    }
}

Gioiello* Gioielli(const char* filename, float b, int* ret_size) {
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        return NULL;
    uint32_t lines = totlines(f);
    fseek(f, 0, 0);
    Gioiello* sorted_arr = calloc(lines , sizeof(Gioiello));
    Gioiello* ris = calloc(lines , sizeof(Gioiello));
    Gioiello* curr = calloc(1,sizeof(Gioiello));
    float current = 0;
    uint32_t cont = 0;
    int i = 0;
    for (;i <= lines-1; ++i ) {
        fscanf(f, "%i %f %f", &curr->codice, &curr->peso, &curr->prezzo);
        sorted_arr[i] = *curr;
    }
    free(curr);
    _greedysort(sorted_arr, lines);
    for (i = lines - 1; i >= 0; --i) {
        if (current + (sorted_arr + i)->prezzo <= b) {  // SVOLGIMENTO ALG. GREEDY
            current += (sorted_arr + i)->prezzo;
            ris[cont++] = sorted_arr[i];
        }
    }
    free(sorted_arr);
    //ris = realloc(ris, (*ret_size) * sizeof(Gioiello));
    *ret_size = cont;
    fclose(f);
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