#include<odcinek.h>
#include<punkt.h>

odcinek::odcinek (punkt a, punkt b)
{
    if (a.wspx()==b.wspx() && a.wspy()==b.wspy())
        throw invalid_argument("nie można utworzyć odcinka o długości 0");
    else
    {
        p1=a;
        p2=b;
    }
}

odcinek::odcinek (const odcinek &o){
    p1=o.p1;
    p2=o.p2;

}

odcinek& odcinek::operator =(const odcinek &o){
    p1=o.p1;
    p2=o.p2;
    return *this;
}


void odcinek::przesun(double a, double b)
{
    p1.przesun(a,b);
    p2.przesun(a,b);
}

void odcinek::rotacja(punkt b,double kat)
{
    p1.rotacja(b,kat);
    p2.rotacja(b,kat);
}

punkt odcinek::srodek()
{
    return punkt((p1.wspx()+p2.wspx())/2,(p1.wspy()+p2.wspy())/2);
}

double odcinek::dlugosc()
{
    return dystans(p1,p2);
}

bool odcinek::czy_na_odcinku(punkt p3)
{
    if(dystans(p1,p3)+dystans(p2,p3)==dystans(p1,p2))
        return true;
    else return 0;

}

bool rownolegle(odcinek a, odcinek b)
{
    double a1=(a.p2.wspy()-a.p1.wspy())/(a.p2.wspx()-a.p1.wspx());
    double a2=(b.p2.wspy()-b.p1.wspy())/(b.p2.wspx()-b.p1.wspx());
    if(a1==a2)
        return true;
    else return false;
}

bool prostopadle(odcinek a, odcinek b)
{
    double a1=(a.p2.wspy()-a.p1.wspy())/(a.p2.wspx()-a.p1.wspx());
    double a2=(b.p2.wspy()-b.p1.wspy())/(b.p2.wspx()-b.p1.wspx());
    if(a1*a2==-1)
        return true;
    else return false;
}

bool przeciecie(odcinek a,odcinek b)
{


}



