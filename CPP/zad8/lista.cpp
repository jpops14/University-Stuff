#include <iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include "wymierne.hpp"
#include <numeric>


namespace wym
{
wymierna::wymierna(int l,int m)
{
    if(m==0)
        throw dzielenie_przez_zero("0 w mianowniku");
    int temp=__gcd(abs(l),abs(m));
    ///cout << temp << "\n";

    if(l==0)
    {
        licz=0;
        mian=1;
    }
    else
    {
        int znak=(l/abs(l))*(m/(abs(m)));
        licz=abs(l)/temp;
        mian=abs(m)/temp;
        licz=licz*znak;
    }
}

wymierna::wymierna(int x) : wymierna(x,1) {};

int wymierna::getLicz()
{
    return licz;
}

int wymierna::getMian()
{
    return mian;
}

wymierna  wymierna::operator ! ()
{
    if(licz==0)
        throw dzielenie_przez_zero("Odwrotnosc 0 nie istnieje");
    int znak=(licz>0) - (licz<0);
    wymierna * res=new wymierna(znak*mian,abs(licz));
    return *res;
}

wymierna wymierna::operator - ()
{
    wymierna * res=new wymierna((-1)*licz,mian);
    return *res;
}

wymierna operator +(const wymierna &x, const wymierna &y)
{
    int nww=lcm(x.mian,y.mian);
    int xmult=nww/x.mian;
    int ymult=nww/y.mian;
    int l=x.licz*xmult+y.licz*ymult;
    wymierna*res=new wymierna(l,nww);
    return *res;
}

wymierna operator -(const wymierna &x, const wymierna &y)
{
    int nww=lcm(x.mian,y.mian);
    int xmult=nww/x.mian;
    int ymult=nww/y.mian;
    int l=x.licz*xmult-y.licz*ymult;
    wymierna*res=new wymierna(l,nww);
    return *res;
}

wymierna operator *(const wymierna &x, const wymierna &y)
{
    int znak=((x.licz>0)-(x.licz<0))*((y.licz>0)-(y.licz<0));
    int tempx=abs(x.licz);
    int tempy=abs(y.licz);

    int gcd1=__gcd(tempx,y.mian);
    int gcd2=__gcd(x.mian,tempy);

    tempx=tempx/gcd1;
    tempy=tempy/gcd2;

    int tempa=y.mian/gcd1;
    int tempb=x.mian/gcd2;

    wymierna * res=new wymierna(tempx*tempy*znak,tempa*tempb);
    return *res;
}

wymierna operator /(const wymierna &x, const wymierna &y)
{
    if(y.licz==0)
        throw dzielenie_przez_zero("div_by_0");
    wymierna tempx=x;
    wymierna tempy=y;
    tempy=!tempy;
    return (tempx*tempy);
}


wymierna::operator int() const
{
    double temp=(double)licz/mian;
    temp=round(temp);
    int res=temp;
    return res;
}
wymierna::operator double() const
{
    double res=(double)licz / mian;
    return res;
}

void wymierna::wypisz()
{
    cout << licz << "/" << mian;
}
}




