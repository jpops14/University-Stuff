#include <bits/stdc++.h>

using namespace std;

namespace dbltab{
class tab_dbl
{
double *tab; // tablica liczb zmiennopozycyjnych
int dl; // rozmiar tablicy
static bool check;///seed losowych liczb
public:
tab_dbl();
explicit tab_dbl(int rozm); // wyzerowana tablica liczb
tab_dbl (std::initializer_list<double> initlist);
tab_dbl(const tab_dbl &t); // konstruktor kopiujący
tab_dbl(tab_dbl &&t); // konstruktor przenoszący
tab_dbl& operator = (const tab_dbl &t); // przypisanie kopiujące
tab_dbl& operator = (tab_dbl &&t); // przypisanie przenoszące
friend tab_dbl operator * (const tab_dbl &u, const tab_dbl &v);// mnozenie skalarne
~tab_dbl(); // destruktor
int getdl();

double& operator[](int index);
const double operator[](int index) const;

};
}

