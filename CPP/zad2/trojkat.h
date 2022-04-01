#include <iostream>
#include <bits/stdc++.h>

class trojkat
{
private:
    punkt p1,p2,p3;
public:
    trojkat(punkt a,punkt b,punkt c);
    trojkat(const trojkat &t);
    trojkąt& operator =(const trojkat &t);
    void przesun(double a, double b);
    void rotacja (punkt b, double angle);
    double pole();
    double obwod();
    bool czywewnatrz(punkt a);
    punkt srodek();

};
