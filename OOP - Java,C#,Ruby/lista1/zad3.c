#include <stdio.h>
#include "mytable.h"


int main()
{
   Tablica *t;
   t = nowa_tablica();
   dodaj(t, 2, 6.0);
   dodaj(t, -3, 5.0);
   dodaj(t, 6, 7.0);
   dodaj(t, -1, 4.0);
   dodaj(t, -5, 2.0);
   float x=indeks(t, -5);
   printf("%lf\n",x);
   x=indeks(t, -1);
   printf("%lf\n",x);
   x=indeks(t, 4);
   printf("%lf\n",x);
   x=indeks(t, -6);
   printf("%lf\n",x);
   x=indeks(t, 9);
   printf("%lf\n",x);
}

