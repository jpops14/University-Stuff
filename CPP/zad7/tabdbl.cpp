#include <iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include "tabdbl.hpp"
#include <random>
#include <chrono>
#include <time.h>
#include <new>


namespace dbltab{

bool tab_dbl::check=0;

int tab_dbl::getdl()
{
    return dl;
}

tab_dbl::tab_dbl (std::initializer_list<double> initlist) : tab_dbl(initlist.size())
{
    for(int i=0; i<dl; i++)
        tab[i]=initlist.begin()[i];
}

tab_dbl::tab_dbl()
{
   for(unsigned long long int i=1;i<=INT_MAX;i++)
   {
       dl=pow(2,i);
       cout << "i: " << i <<"\n";
       tab=new (nothrow) double[dl];
       if (tab==nullptr){
       dl=dl/2;
       delete[]tab;
       tab=new double[dl];
       cout << "answer: 2^" <<i-1 << "\n";
       break;
       }
       delete[]tab;
   }
   if(check==0)
   {
    check=1;
    srand(time(0));
   }

   for(int i=0;i<dl;i++)
   {
        tab[i]=(double )rand()/RAND_MAX;
   }


}

tab_dbl::tab_dbl(int rozm):dl(rozm)
{
    if(rozm<=0)
        throw std::invalid_argument ("non positive array size\n");
    tab=new double[rozm]{0};
   /// cout << tab[3];

}
tab_dbl::~tab_dbl()
{
    delete[] tab;
}

tab_dbl::tab_dbl (const tab_dbl &w)
{
    dl=w.dl;
    tab=new double[dl];
    for(int i=0; i<dl; i++)
        tab[i]=w.tab[i];
}

tab_dbl::tab_dbl (tab_dbl &&w)
{
    dl=w.dl;
    tab=w.tab;
    w.tab=nullptr;
    w.dl=0;
}

tab_dbl & tab_dbl::operator = (const tab_dbl &w)
{
    if(&w==this) return *this;
    this->~tab_dbl();
    this->dl=w.dl;
    this->tab=new double[dl];
    for(int i=0; i<dl; i++)
        tab[i]=w.tab[i];
    return *this;


}

tab_dbl & tab_dbl::operator = (tab_dbl &&w)
{
    if(this!=&w)
    {
        delete[] tab;
        dl=w.dl;
        w.tab=nullptr;
        dl=w.dl;
        w.dl=0;
    }
    return *this;
}

double& tab_dbl::operator[](int index)
{
    if(index<0||index>=dl)
        throw std::out_of_range("index out of range\n");
    return tab[index];
}
const double tab_dbl::operator[](int index) const
{
   if(index<0||index>=dl)
       throw std::out_of_range("index out of range\n");
    return tab[index];
}

tab_dbl operator * (const tab_dbl &u, const tab_dbl &v)
{
    assert(u.dl==v.dl);
    tab_dbl * result=new tab_dbl(u.dl);
    for(int i=0;i<u.dl;i++)
        result->tab[i]=u.tab[i]*v.tab[i];
    return *result;

}


}




