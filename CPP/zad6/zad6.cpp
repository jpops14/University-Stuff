#include <bits/stdc++.h>
#include "tabbit.hpp"

using namespace B;

int main()
{

    tab_bit t(46);
    tab_bit u((uint64_t)45);
    tab_bit v(t);
    tab_bit w(tab_bit((uint64_t)177));
    v[0] = 1; // ustawienie bitu 0-go bitu na 1
    t[30] = true; // ustawienie bitu 45-go bitu na 1
    bool b = v[1]; // odczytanie bitu 1-go
    u[45] = u[46] = u[63]; // przepisanie bitu 63-go do bitow 45-go i 46-go
    cout<<t<<endl; // wysietlenie zawartości tablicy bitów na ekranie

}
