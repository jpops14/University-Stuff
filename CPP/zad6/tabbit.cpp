#include <iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include "tabbit.hpp"



namespace B{

inline int tab_bit::rozmiar() const
{
    return dl;
}
///explicit konstruktory
tab_bit::tab_bit(int rozm)
{
    if(rozm<0)
        throw "nie mozna stworzyć tablicy o ujemnym rozmiarze\n";

    dl=rozm;
    int tabl=dl/rozmiarSlowa;
    if  (dl%rozmiarSlowa!=0)
        tabl++;
    tab=new slowo[tabl];
    for(int i=0; i<tabl; i++)
        tab[i]=0;
}
tab_bit::tab_bit (slowo tb)
{
    dl=rozmiarSlowa;
    tab=new slowo[1];
    tab[0]=tb;
}

const int tab_bit::rozmiarSlowa=sizeof(uint64_t)*8;
///konstruktory

tab_bit::tab_bit(const tab_bit&w)
{
    dl=w.dl;

    int tabl=dl/(sizeof(slowo)*8);
    if  (dl%(sizeof(slowo)*8)!=0)
        tabl++;
    tab=new slowo[tabl];
    for(int i=0; i<tabl; i++)
        tab[i]=w.tab[i];
}

tab_bit::tab_bit(tab_bit&&w)
{
    dl=w.dl;
    tab=w.tab;
    w.tab=nullptr;
    w.dl=0;
}

tab_bit& tab_bit::operator = (const tab_bit&w)
{
    if(&w==this) return *this;
    this->~tab_bit();
    this->dl=w.dl;
    int tabl=dl/rozmiarSlowa;
    if  (dl%rozmiarSlowa!=0)
        tabl++;
    this->tab=new slowo[tabl];
    for(int i=0; i<tabl; i++)
        tab[i]=w.tab[i];
    return *this;

}

tab_bit& tab_bit::operator = (tab_bit&&w)
{
    if(this!=&w)
    {
        delete[] tab;
        tab=w.tab;
        w.tab=nullptr;
        dl=w.dl;
        w.dl=0;
    }
    return *this;
}

tab_bit::~tab_bit()
{
    delete [] tab;
}

//pomocnicze
bool tab_bit::czytaj(int i) const
{
    if(i<0||i>=dl)
    throw "out of range";
    uint64_t kom=i/rozmiarSlowa;
    uint64_t nr=i%rozmiarSlowa;
    uint64_t res=(tab[kom]>>nr)&1;
    if(res==1)
        return true;
    else return false;
}
bool tab_bit::pisz(int i,bool b)
{
     if(i<0||i>=dl)
    throw "out of range";

    uint64_t kom=i/rozmiarSlowa;
    uint64_t nr=i%rozmiarSlowa;
    uint64_t change=(1<<nr);

    if(b==0)
        tab[kom]=tab[kom]&(~change);
    else tab[kom]=tab[kom]|change;
    return b;
}

// operatory bitowe
tab_bit operator & (const tab_bit &u, const tab_bit &v)
{
    tab_bit * res=new tab_bit(min(u.dl,v.dl));
    int tabl=(*res).dl/u.rozmiarSlowa;
    if((*res).dl%u.rozmiarSlowa!=0)
        tabl++;
    for(int i=0; i<tabl; i++)
        (*res).tab[i]=u.tab[i]&v.tab[i];

    return*res;
}

tab_bit operator | (const tab_bit &u, const tab_bit &v)
{
    int ulen=u.dl/u.rozmiarSlowa;
    int vlen=v.dl/v.rozmiarSlowa;
    if(u.dl%u.rozmiarSlowa!=0)
        ulen++;
    if(v.dl%v.rozmiarSlowa!=0)
        vlen++;

    tab_bit * res=new tab_bit(max(u.dl,v.dl));
    int tabl=(*res).dl/u.rozmiarSlowa;
    if((*res).dl%u.rozmiarSlowa!=0)
        tabl++;

    for(int i=0; i<min(ulen,vlen); i++)
        (*res).tab[i]=u.tab[i]|v.tab[i];
    for(int i=min(ulen,vlen); i<tabl; i++)
        if(ulen>vlen)
            (*res).tab[i]=u.tab[i];
        else (*res).tab[i]=v.tab[i];

    return*res;
}

tab_bit operator ^ (const tab_bit &u, const tab_bit &v)
{
    int ulen=u.dl/u.rozmiarSlowa;
    int vlen=v.dl/v.rozmiarSlowa;
    if(u.dl%u.rozmiarSlowa!=0)
        ulen++;
    if(v.dl%v.rozmiarSlowa!=0)
        vlen++;

    tab_bit * res=new tab_bit(max(u.dl,v.dl));
    int tabl=(*res).dl/u.rozmiarSlowa;
    if((*res).dl%u.rozmiarSlowa!=0)
        tabl++;

    for(int i=0; i<min(ulen,vlen); i++)
        (*res).tab[i]=u.tab[i]^v.tab[i];

    for(int i=min(ulen,vlen); i<tabl; i++)
        if(ulen>vlen)
            (*res).tab[i]=u.tab[i]^0;
        else (*res).tab[i]=v.tab[i]^0;

    return*res;
}

tab_bit & tab_bit::operator &= (const tab_bit &v)
{
    tab_bit temp=*this&v;
    delete this;
    *this=temp;
    return *this;
}

tab_bit & tab_bit::operator |= (const tab_bit &v)
{
    tab_bit temp=*this|v;
    delete this;
    *this=temp;
    return *this;
}
tab_bit & tab_bit::operator ^= (const tab_bit &v)
{
    tab_bit temp=*this^v;
    delete this;
    *this=temp;
    return *this;
}

tab_bit & tab_bit::operator ! ()
{
    int tabl=(*this).dl/(*this).rozmiarSlowa;
    if((*this).dl%(*this).rozmiarSlowa!=0)
        tabl++;
    for(int i=0; i<tabl; i++)
        (*this).tab[i]=~ (*this).tab[i];
    return *this;
}
//in&out

istream& operator >> (istream &we, tab_bit &tb)
{
    for(int i=tb.dl-1; i>=0; i--)
    {
        bool x;
        cin >> x;
        tb.pisz(i,x);

    }
    return we;
}

ostream& operator << (ostream &wy, const tab_bit &tb)
{
    for(int i=tb.dl-1; i>=0; i--)
        cout << tb.czytaj(i);
    return wy;
}
//indeksy

bool tab_bit::operator [] (int i) const
{
    return czytaj(i);
}

tab_bit::ref::ref(tab_bit * obj,int x)
{
    elem=obj;
    indeks=x;
}

tab_bit::ref& tab_bit::ref::operator =(bool b)
{
    elem->pisz(indeks,b);
    return *this;
}

tab_bit::ref::operator bool ()
{
        return elem->czytaj(indeks);
}

tab_bit::ref tab_bit::operator[] (int i)
{
    return ref(this,i);
}


}




