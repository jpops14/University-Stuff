#include <iostream>
#include<string>
#include<vector>
#include"wielomiany.hpp"

using namespace std;


///konstruktory
wielomian::wielomian () : n(0), a(new double[1])  ///jednomian
{
    n=0;
    a[0]=1.0;
}

wielomian::wielomian (int st, const double wsp[]) : n(st)
{
    if(st<0)
        throw "nie mozna tworzyc wielomianów o ujemnym stopniu";
    if(wsp[st]==0&&st!=0)
        throw "wsp przy najwyzszej potedze == 0";
    n=st;
    a=new double[st+1];
    for(int i=0; i<=st; i++)
        a[i]=wsp[i];

    ///  for(int i=0; i<=st; i++)
    ///    cout<< a[i] << " ";
}

wielomian::wielomian (std::initializer_list<double> wsp)// lista współczynników
{
    if(wsp.begin()[wsp.size()-1]==0)
        throw "wsp przy najwyzszej potedze == 0";
    n=wsp.size()-1;
    a=new double[wsp.size()];
    for(int i=0; i<=n; i++)
        a[i]=wsp.begin()[i];
}

wielomian::wielomian (const wielomian &w)
{
    n=w.n;
    a=new double[n+1];
    for(int i=0; i<=n; i++)
        a[i]=w.a[i];
}

wielomian::wielomian (wielomian &&w)
{
    n=w.n;
    a=w.a;
    w.a=nullptr;
    w.n=-1;
}

wielomian& wielomian::operator = (const wielomian &w)
{
    if(&w==this) return *this;
    this->~wielomian();
    this->n=w.n;
    this->a=new double[n+1];
    for(int i=0; i<=n; i++)
        a[i]=w.a[i];
    return *this;


}

wielomian& wielomian::operator = (wielomian &&w)
{
    if(this!=&w)
    {
        delete[] a;
        a=w.a;
        w.a=nullptr;
        n=w.n;
        w.n=-1;
    }
    return *this;
}

wielomian::~wielomian ()
{
    delete [] a;
}

/// stream operators

istream& operator >> (istream &we, wielomian &w)
{
    if(w.n!=-1)
        delete w.a;
    we >> w.n;
    if(w.n<0)
        throw "nie mozna stworzyc wielomianu o ujemnym stopniu";
    w.a=new double[w.n+1];
    for(int i=0; i<=w.n; i++)
        we >> w.a[i];

    return we;
}

ostream& operator << (ostream &wy, const wielomian &w)
{
    wy << "{ " << w.a[0];
    for(int i=1; i<=w.n; i++)
    {
        wy << " + " << w.a[i] << "*x^(" << i <<")";
    }
    wy << " }";
    return wy;
}

/// operators I
wielomian operator + (const wielomian &u, const wielomian &v)
{
    double *tab=new double[max(u.n,v.n)+1];
    for(int i=0; i<=min(u.n,v.n); i++)
    {
        tab[i]=u.a[i]+v.a[i];
    }
    if(u.n>v.n)
        for(int i=v.n+1; i<=u.n+1; i++)
            tab[i]=u.a[i];
    else for(int i=u.n+1; i<=v.n; i++)
            tab[i]=v.a[i];
    wielomian * temp;
    for(int i=max(u.n,v.n); i>=0; i--)
        if(tab[i]!=0)
        {
            temp=new wielomian(i,tab);
            break;
        }
        else if(i==0)
        {
            temp=new wielomian(0,tab);
        }
    delete[] tab;
    return *temp;
}

wielomian operator - (const wielomian &u, const wielomian &v)
{
    double *tab=new double[max(u.n,v.n)+1];
    for(int i=0; i<=min(u.n,v.n); i++)
    {
        tab[i]=u.a[i]-v.a[i];
    }
    if(u.n>v.n)
        for(int i=v.n+1; i<=u.n+1; i++)
            tab[i]=u.a[i];
    else for(int i=u.n+1; i<=v.n; i++)
            tab[i]=(-1)*v.a[i];


    wielomian * temp;
    for(int i=max(u.n,v.n); i>=0; i--)
        if(tab[i]!=0)
        {
            temp=new wielomian(i,tab);
            break;
        }
        else if(i==0)
        {
            temp=new wielomian(0,tab);
        }
    delete[] tab;
    return *temp;
}

wielomian operator * (const wielomian &u, const wielomian &v)
{
    double *tab=new double[u.n+v.n+1];
    wielomian * temp;
    for(int i=0; i<=u.n+v.n; i++)
        tab[i]=0;

    for(int i=0; i<=u.n; i++)
        for(int j=0; j<=v.n; j++)
            tab[i+j]+=u.a[i]+v.a[j];

    for(int i=u.n+v.n; i>=0; i--)
        if(tab[i]!=0)
        {
            temp=new wielomian(i,tab);
            break;
        }
        else if(i==0)
        {
            temp=new wielomian(0,tab);
        }
    delete []tab;
    return *temp;
}
wielomian operator * (const wielomian &u, double c)
{
    double * tab=new double[u.n+1];
    for(int i=0; i<=u.n; i++)
        tab[i]=u.a[i]*c;
    wielomian * temp;
    for(int i=u.n; i>=0; i--)
        if(tab[i]!=0)
        {
            temp=new wielomian(i,tab);
            break;
        }
        else if(i==0)
        {
            temp=new wielomian(0,tab);
        }
    delete[] tab;
    return *temp;

}
wielomian operator * (double c,const wielomian &u)
{
    return u*c;
}

///operators II
wielomian& wielomian::operator += (const wielomian &v)
{
    double *tab=new double[max(n,v.n)+1];
    for(int i=0; i<=min(n,v.n); i++)
    {
        tab[i]=a[i]+v.a[i];
    }
    if(n>v.n)
        for(int i=v.n+1; i<=n; i++)
            tab[i]=a[i];
    else for(int i=n+1; i<=v.n; i++)
            tab[i]=v.a[i];

    delete[]a;
    for(int i=max(n,v.n); i>=0; i--)
        if(tab[i]!=0)
        {
            n=i;
            break;
        }
        else if(i==0)
        {
            n=0;
        }
    a=new double[n+1];
    for(int i=0; i<=n; i++)
        a[i]=tab[i];

    delete[] tab;
    return *this;
}

wielomian& wielomian::operator -= (const wielomian &v)
{
    double *tab=new double[max(n,v.n)+1];
    for(int i=0; i<=min(n,v.n); i++)
    {
        tab[i]=a[i]-v.a[i];
    }
    if(n>v.n)
        for(int i=v.n+1; i<=n; i++)
            tab[i]=a[i];
    else for(int i=n+1; i<=v.n; i++)
            tab[i]=v.a[i];

    delete[]a;
    for(int i=max(n,v.n); i>=0; i--)
        if(tab[i]!=0)
        {
            n=i;
            break;
        }
        else if(i==0)
        {
            n=0;
        }
    a=new double[n+1];
    for(int i=0; i<=n; i++)
        a[i]=tab[i];

    delete[] tab;
    return *this;
}
wielomian& wielomian::operator *= (const wielomian &v)
{
    double *tab=new double[n+v.n+1];
    wielomian * temp;
    for(int i=0; i<=n+v.n; i++)
        tab[i]=0;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=v.n; j++)
            tab[i+j]+=a[i]+v.a[j];

    delete[]a;
    for(int i=n+v.n; i>=0; i--)
        if(tab[i]!=0)
        {
            n=i;
            break;
        }
        else if(i==0)
        {
            n=0;
        }
    a=new double[n+1];
    for(int i=0; i<=n; i++)
        a[i]=tab[i];

    delete[] tab;
    return *this;
}
wielomian& wielomian::operator *= (double c)
{
    if(c==0)
    {
        n=0;
        delete[]a;
        a=new double[1];
        a[0]=0;
    }
    else for(int i=0; i<=n; i++)
            a[i]=a[i]*c;
    return *this;
}
///

double wielomian::operator () (double x) const // wartość wielomianu dla x
{
    /// cout << "entry\n";
    double result=0;
    for(int i=n; i>=0; i--)
    {
        result=result*x;
        result+=a[i];
        /// cout << "repeat\n";
    }
    ///cout << "done\n";

    return result;
}
double wielomian::operator [] (int i) const // odczytanie i-tego współczynnika
{
    if(i>n) throw "out of bounds";

    return a[i];
}

///metody

void wielomian::setn(int x)
{
    if(x>n) throw "nie można zwiększyć stopnia wielomianu";
    if(x<n)
    {
        double *tab=new double[x+1];
        for(int i=0; i<=x; i++)
            tab[i]=a[i];
        if(tab[x]==0)
            throw "nie mozna ustawic stopnia X - wsp 0 przy najwyzszej potedze";
        delete[] a;
        a=tab;
        n=x;
    }
}

int wielomian::getn()
{
    return n;
}

double& wielomian::operator[](int index)
{
    if(index>n) throw "out of bounds";
    return a[index];
}

