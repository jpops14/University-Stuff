#include<stdio.h>
#include<stdlib.h>

enum typfig{square,circle,triangle};

struct figura
{
    enum typfig figure;
    float x1,y1,x2,y2,x3,y3;
};

typedef struct figura Figura;

Figura * new_square(float x,float y,float a);

Figura * new_circle(float x,float y,float r)
;

Figura * new_triangle(float x1,float y1,float x2, float y2, float x3, float y3);

float pole(Figura *f);

void przesun(Figura *f, float x, float y);

float sumapol(Figura* f[], int size);

