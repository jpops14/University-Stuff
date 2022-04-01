#include "myfigures.h"

Figura * new_square(float x,float y,float a)
{
    if(a<0){
    printf("ERROR - negative side length\n");
    return NULL;
    }
    Figura * Square=(Figura *)malloc(sizeof(Figura));
    Square->figure=square;
    Square->x1=x;
    Square->y1=y;
    Square->x2=a;
    Square->y2=0;
    Square->x3=0;
    Square->y3=0;
    return Square;
}

Figura * new_circle(float x,float y,float r)
{
    if(r<0)
    {
    printf("ERROR - negative radius\n");
    return NULL;
    }

    Figura * Circle=(Figura *)malloc(sizeof(Figura));
    Circle->figure=circle;
    Circle->x1=x;
    Circle->y1=y;
    Circle->x2=r;
    Circle->y2=0;
    Circle->x3=0;
    Circle->y3=0;
    return Circle;
}

Figura * new_triangle(float x1,float y1,float x2, float y2, float x3, float y3)
{
    Figura * Triangle=(Figura *)malloc(sizeof(Figura));
    Triangle->figure=triangle;
    Triangle->x1=x1;
    Triangle->y1=y1;
    Triangle->x2=x2;
    Triangle->y2=y2;
    Triangle->x3=x3;
    Triangle->y3=y3;
    return Triangle;
}

float pole(Figura *f)
{
    float pole;
    if(f->figure==2)
    {
       pole=((f->x2)-(f->x1))*((f->y3)-(f->y1))-((f->y2)-(f->y1))*((f->x3)-(f->x1));
       if(pole<0) pole = pole * (-1);
       pole = pole/2;
    }
    else{
    pole=(f->x2)*(f->x2);
    if(f->figure==1)
    pole=pole*(3.14);
    }

   return pole;
}

void przesun(Figura *f, float x, float y)
{
   f->x1+=x;
   f->y1+=y;
   if(f->figure==2)
   {
        f->x2+=x;
        f->y2+=y;
        f->x3+=x;
        f->y3+=y;
   }

}

float sumapol(Figura* f[], int size)
{
    float suma=0;
    for(int i=0;i<size;i++)
    {
     suma+=pole(f[i]);
    }
}
