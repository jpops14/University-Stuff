#include <iostream>
#include<string>
#include<vector>
#include"kolejka.hpp"

using namespace std;


///konstruktory
kolejka& kolejka::operator = (kolejka &&q)
{
    if (this != &q)
    {
        delete[]kol;
        kol=q.kol;
        pocz=q.pocz;
        ile=q.ile;
        pojemnosc=q.pojemnosc;
        q.kol=nullptr;
        q.pojemnosc=0;
        q.pocz=0;
        q.ile=0;

    }
    return *this;
}

kolejka::kolejka(kolejka&& q)
{
    pocz=q.pocz;
    ile=q.ile;
    pojemnosc=q.pojemnosc;
    kol=q.kol;
    q.kol=nullptr;
    q.pocz=0;
    q.ile=0;
    q.pojemnosc=0;

}

kolejka::kolejka(std::initializer_list<string> l) : kolejka(l.size())
{
    pojemnosc=l.size();
    pocz=0;
    ile=l.size();
    for(int i=0; i<ile; i++)
        kol[i]=l.begin()[i];

}

kolejka& kolejka::operator = (const kolejka &q)    ///assignment
{
    if(&q==this) return *this;
    this->~kolejka();
    this->pocz=q.pocz;
    this->ile=q.ile;
    this->pojemnosc=q.pojemnosc;
    ///kolejka
    kol=new string[q.pojemnosc];
    for(int i=0; i<pojemnosc; i++)
        kol[i]=q.kol[i];
    return *this;
}

kolejka::kolejka(const kolejka& q)           ///copy
{
    pocz=q.pocz;
    ile=q.ile;
    pojemnosc=q.pojemnosc;
    ///kolejka
    kol=new string[q.pojemnosc];
    for(int i=0; i<pojemnosc; i++)
        kol[i]=q.kol[i];
}

kolejka::~kolejka()          ///destruktor
{
    delete[] kol;
}


kolejka::kolejka(int newsize) : pojemnosc(newsize),kol(new string[newsize])      ///rozmiar
{
    pocz=0;
    ile=0;
}

kolejka::kolejka() : kolejka(1)           ///delegatowy
{}


///metody

int kolejka::rozmiar()
{
    return ile;
}

string kolejka::wyciagnij()
{
    if(ile==0)
    {
        throw "empty";
    }
    ///wyjatek - pusta kolejka
    string temp=kol[pocz];
    pocz=(pocz+1)%pojemnosc;
    ile--;
    return temp;
}

string kolejka::naprzodzie()
{
    if(ile==0)
    {
        throw "empty";
    }
    return kol[pocz];
}

void kolejka::wloz(string x)
{
    if(ile>=pojemnosc)
    {
        throw "full";
    }
    kol[(pocz+ile)%pojemnosc]=x;
    ile++;
}


