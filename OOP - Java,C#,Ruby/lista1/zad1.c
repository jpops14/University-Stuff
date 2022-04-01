#include<stdio.h>
#include<stdlib.h>
#include "myfigures.h"

int main()
{
    Figura * a;
    Figura * b;
    Figura * c;
    Figura * f[3];

    a=new_square(2.0,3.0,3.0);
    b=new_circle(1.0,1.0,1.0);
    c=new_triangle(1.0,1.0,3.0,1.0,2.0,3.0);
    f[0]=a;
    f[1]=b;
    f[2]=c;
    float polea=sumapol(f,3);
    printf("%f",polea);

}
