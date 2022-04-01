#include <iostream>
#include <bits/stdc++.h>

class odcinek
{
private:
    punkt p1,p2;
public:
    odcinek (punkt a,punkt b);
    odcinek (const odcinek &o);
    odcinek& operator =(const odcinek &o);
    bool czy_na_odcinku(punkt p3);
    void przesun(double a, double b);
    void rotacja (punkt b, double angle);
    double dlugosc();
    punkt srodek();
};

bool rownolegle(odcinek a, odcinek b);

bool prostopadle(odcinek a, odcinek b);

bool przeciecie(odcinek a,odcinek b);
