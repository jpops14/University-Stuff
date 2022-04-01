#include <stdio.h>
#include<stdlib.h>

typedef float dane;

struct tablica
{
    dane * tab;
    int L;
    int R;
    int length;
    int shift;
};
typedef struct tablica Tablica;
struct tablica * nowa_tablica();

float indeks(struct tablica * t,int position);

void dodaj(struct tablica * t, int pos, dane elem);
