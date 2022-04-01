#include<trojkat.h>
#include<punkt.h>
#include<

trojkat::trojkat(punkt a,punkt b,punkt c);
{

        p1=a;
        p2=b;
        p3=c;
}

trojkat::trojkat(const trojkat &t);
{
    p1=t.p1;
    p2=t.p2;
    p3=t.p3;
}

trojkąt& trojkat::operator =(const trojkat &t);
{
    p1=t.p1;
    p2=t.p2;
    p3=t.p3;
    return *this;
}


void trojkat::przesun(double a, double b)
{
    p1.przesun(a,b);
    p2.przesun(a,b);
    p3.przesun(a,b);
}

void trojkat::rotacja(punkt b,double kat)
{
    p1.rotacja(b, kat);
    p2.rotacja(b, kat);
    p3.rotacja(b, kat);
}

double trojkat::pole()
{
    double wynik=(p2.wspx()-p1.wspx())*(p3.wspy()-p1.wspy())-(p2.wspy()-p1.wspy())*(p3.wspx()-p1.wspx());
    if(wynik<0)
        wynik=wynik*(-1);
    return wynik/2;
}

double trojkat::obwod()
{
    return dystans(p1,p2)+dystans(p2,p3)+dystans(p3,p1);
}


punkt trojkat::srodek()
{
    punkt mid=punkt((p1.wspx()+p2.wsx()+p3.wspx())/3,(p1.wspy()+p2.wspy()+p3.wspy())/3);
    return mid;
}

