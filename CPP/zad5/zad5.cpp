#include <bits/stdc++.h>
#include "wyrazenia.hpp"
using namespace std;


int main()
{
    wyrazenie * ex1= new dziel(new mnoz(new odejmij (new zmienna("x"),new liczba(1)),new zmienna("x")),new liczba(2));
    wyrazenie * ex2= new dziel(new dodaj (new liczba (3),new liczba(5)),new dodaj(new liczba(2),new mnoz(new zmienna("x"),new liczba(7))));
    wyrazenie * ex3= new odejmij(new dodaj(new liczba(2),new mnoz(new zmienna("x"),new liczba(7))), new dodaj(new mnoz(new zmienna ("x"),new liczba(3)),new liczba(5)));
    wyrazenie * ex4= new dziel(new cosinus(new mnoz (new dodaj(new zmienna ("x"),new liczba(1)),new zmienna("x"))) ,new expo(new potega (new zmienna ("x"),new liczba(2))));

    cout << (*ex1).zapis() << "\n" << (*ex2).zapis() << "\n" << (*ex3).zapis() << "\n" << (*ex4).zapis() << "\n";

    for(double i=0.00;i<=1.00;i+=0.01)
    {
        cout << "\n wartość x = " << i << "\n";
        zmienna::nowazmienna("x",i);
        cout << (*ex1).oblicz() << "\n" << (*ex2).oblicz() << "\n" << (*ex3).oblicz() << "\n" << (*ex4).oblicz() << "\n";
        zmienna::usunzmienna("x");
    }
}


