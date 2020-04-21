#include "torrecartoni.h"


void sequence(cartone *c, bool *vcurr, bool *vbest, size_t i, size_t n, size_t* mheight)
{
    if (i == n)
    {
        size_t height = 0, cont = 0, w = 0;
        for (int k = n - 1; k >= 0; --k)
        {
            if (vcurr[k] == true)
            {
                if (cont != 0)
                {
                    if (w > (c + k)->l)
                        return;
                }
                w += (c + k)->p;
                height += (c + k)->a;
                ++cont;
            }
        }
        if (height > *mheight)
        {
            *mheight = height;
            memcpy(vbest, vcurr, n);
        }
        return;
    }

    for (size_t j = 0; j < 2; ++j)
    {
        vcurr[i] = j;
        sequence(c, vcurr, vbest, i + 1, n, mheight);
    }
}

void print(bool* v, cartone* c, uint8_t n, bool flag){
    for(int k = n-1; k >= 0; --k){
       // if(v[k] == true){
            fprintf(stdout, "\nindex: %d, %d\t (%d,%d,%d)", k,v[k],(c+k)->p,(c+k)->a,(c+k)->l);
      //  }
    }
    puts("");
}

void TorreCartoni(cartone *c, int n)
{
    size_t max;
    bool *vcurr = malloc(n * sizeof(bool));
    bool *vbest = malloc(n * sizeof(bool));
    sequence(c, vcurr, vbest, 0, n, &max);
    print(vbest, c, n, false);
}

void main(void)
{
    cartone c[] = {{.p = 10, .a = 20, .l = 40}, {.p = 10, .a = 10, .l = 8}, {.p = 9, .a = 3, .l = 5},{.p = 10, .a = 3, .l = 50}};
    size_t n = sizeof(c)/sizeof(c[0]);
    TorreCartoni(c, n);
}