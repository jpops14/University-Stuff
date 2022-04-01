#include<punkt.h>

punkt::punkt (double a, double b)
{
    x=a;
    y=b;
}

punkt::punkt(const punkt &p)
{
    x=p.x;
    y=p.y;
}

punkt& punkt::operator =(const punkt &p)
{
    x=p.x;
    y=p.y;
    return *this;
}

double punkt::wspx()
{
    return x;
}

double punkt::wspy()
{
    return y;
}

void punkt::przesun(double a, double b)
{
    x+=a;
    y+=b;
}

void punkt::rotacja(punkt b,double kat)
{
    double tempx=cos(kat)*x-sin(kat)*y;
    double tempy=sin(kat)*x+cos(kat)*y;
}

double dystans(punkt a, punkt b)
{
    double temp1=b.wspx()-a.wspx();
    double temp2=b.wspy()-a.wspy();
    return sqrt(temp1*temp1+temp2*temp2);
}


