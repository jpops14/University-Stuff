#include <iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include "wyrazenia.hpp"

using namespace std;




/// =================================== klasy
/// ===================================> liczba


liczba::liczba(double x)
{
    wartosc=x;
}

double liczba::oblicz()
{
    return wartosc;
}
string liczba::zapis()
{
    return to_string(wartosc);
}
/// ===================================> zmienna

vector<pair < string, double > > zmienna::vektor;

void zmienna::nowazmienna(string x,double y)
{
    vektor.push_back(make_pair(x,y));
}
void zmienna::usunzmienna(string x)
{
    for(int i=0;i<vektor.size();i++)
        if(vektor[i].first==x)
        {
            vektor.erase(vektor.begin()+i);
        }
}
void zmienna::zmienwartosc(string x,double y)
{
    for(int i=0;i<vektor.size();i++)
        if(vektor[i].first==x)
        {
            vektor[i].second=y;
            return;
        }
}

zmienna::zmienna(string x)
{
    nazwa = x;
}

double zmienna::oblicz()
{
    for(int i=0; i<vektor.size(); i++)
        if(vektor[i].first==nazwa)
            return vektor[i].second;

    throw "Niezdefiniowana zmienna";
    return 0;
}

string zmienna::zapis()
{
    return nazwa;
}
/// =======================================================================> stale


string stala :: zapis()
{
    return nazwa;
}
double stala :: oblicz()
{
    return wartosc;
}


pi::pi()
{
    nazwa="pi";
    wartosc=3.1415;
}



e::e()
{
    nazwa="e";
    wartosc=2.7182;
}



fi::fi()
{
    nazwa="fi";
    wartosc=1.6180;
}

///======================================================================> operatory 1arg


operator1arg::~operator1arg()
{
    delete right;
}



sinus::sinus(wyrazenie * x)
{
    right=x;
}

double sinus::oblicz()
{
    return sin((*right).oblicz());
}

string sinus::zapis()
{
    return "sin("+(*right).zapis()+")";
}



cosinus::cosinus(wyrazenie * x)
{
    right=x;
}

double cosinus::oblicz()
{
    return cos((*right).oblicz());
}

string cosinus::zapis()
{
    return "cos("+(*right).zapis()+")";
}


ln::ln(wyrazenie * x)
{
    right=x;
}

double ln::oblicz()
{
    return log((*right).oblicz());
}

string ln::zapis()
{
    return "ln("+(*right).zapis()+")";
}



bezwzgl::bezwzgl(wyrazenie * x)
{
    right=x;
}

double bezwzgl::oblicz()
{
    return abs((*right).oblicz());
}

string bezwzgl::zapis()
{
    return "|"+(*right).zapis()+"|";
}



przeciw::przeciw(wyrazenie * x)
{
    right=x;
}

double przeciw::oblicz()
{
    return (-1)*((*right).oblicz());
}

string przeciw::zapis()
{
    return "(-("+(*right).zapis()+"))";
}



odwrot::odwrot(wyrazenie * x)
{
    right=x;
}

double odwrot::oblicz()
{
    return 1/((*right).oblicz());
}

string odwrot::zapis()
{
    return "1/("+(*right).zapis()+")";
}



expo::expo(wyrazenie * x)
{
    right=x;
}

double expo::oblicz()
{
    return exp((*right).oblicz());
}

string expo::zapis()
{
    return "e^("+(*right).zapis()+")";
}

///======================================================================> operatory 2arg

operator2arg::~operator2arg()
{
    delete lf;
    delete right;
}


dodaj::dodaj(wyrazenie * x,wyrazenie * y)
{
    lf=x;
    right=y;
}

double dodaj::oblicz()
{
    return (*lf).oblicz()+(*right).oblicz();
}

string dodaj::zapis()
{
    return (*lf).zapis()+" + "+(*right).zapis();
}



odejmij::odejmij(wyrazenie * x,wyrazenie * y)
{
    lf=x;
    right=y;
}

double odejmij::oblicz()
{
    return (*lf).oblicz()-(*right).oblicz();
}

string odejmij::zapis()
{
    return (*lf).zapis()+" - "+(*right).zapis();
}



mnoz::mnoz(wyrazenie * x,wyrazenie * y)
{
    lf=x;
    right=y;
}

double mnoz::oblicz()
{
    return (*lf).oblicz()*(*right).oblicz();
}

string mnoz::zapis()
{
    return "("+(*lf).zapis()+") * ("+(*right).zapis()+")";
}



dziel :: dziel(wyrazenie * x,wyrazenie * y)
{
    lf=x;
    right=y;
}

double dziel::oblicz()
{
    return (*lf).oblicz()/(*right).oblicz();
}

string dziel::zapis()
{
    return "("+(*lf).zapis()+") / ("+(*right).zapis()+")";
}


modulo :: modulo(wyrazenie * x,wyrazenie * y)
{
    lf=x;
    right=y;
}

double modulo::oblicz()
{
    return fmod((*lf).oblicz(),(*right).oblicz());
}

string modulo::zapis()
{
    return "("+(*lf).zapis()+") mod ("+(*right).zapis()+")";
}


logarytm :: logarytm(wyrazenie * x,wyrazenie * y)
{
    lf=x;
    right=y;
}

double logarytm::oblicz()
{
    return log((*right).oblicz())/log((*lf).oblicz());
}

string logarytm::zapis()
{
    return "logarytm["+(*lf).zapis()+"]("+(*right).zapis()+")";
}



potega :: potega(wyrazenie * x,wyrazenie * y)
{
    lf=x;
    right=y;
}

double potega::oblicz()
{
    return pow((*lf).oblicz(),(*right).oblicz());
}

string potega::zapis()
{
    return "("+(*lf).zapis()+")^("+(*right).zapis()+")";
}



