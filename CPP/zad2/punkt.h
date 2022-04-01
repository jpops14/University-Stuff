#include <iostream>
#include <bits/stdc++.h>


class punkt
{
private:
    double x, y;
public:
    punkt (double a, double b);
    punkt (const punkt &p);
    punkt& operator =(const punkt &p);
    void przesun(double a, double b);
    void rotacja(punkt b, double kat);
    double wspx();
    double wspy();
};

double dystans(punkt a, punkt b);
