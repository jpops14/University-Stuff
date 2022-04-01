#include <bits/stdc++.h>

using namespace std;

class wielomian
{
private:
    int n; // stopień wielomianu
    double *a; // współczynniki wielomianu


public:
///dostęp
    void setn(int x);
    int getn();
    double& operator[](int index);

///konstruktory

    wielomian (); // konstruktor jednomianu
    wielomian (int st, const double wsp[]); // konstruktor wielomianu
    wielomian (std::initializer_list<double> wsp); // lista współczynników
    wielomian (const wielomian &w); // konstruktor kopiujący
    wielomian (wielomian &&w); // konstruktor przenoszący
    wielomian& operator = (const wielomian &w); // przypisanie kopijące
    wielomian& operator = (wielomian &&w); // przypisanie przenoszące
    ~wielomian (); // destruktor


///operatory

    friend wielomian operator + (const wielomian &u, const wielomian &v);
    friend wielomian operator - (const wielomian &u, const wielomian &v);
    friend wielomian operator * (const wielomian &u, const wielomian &v);
    friend wielomian operator * (const wielomian &u, double c);
    wielomian& operator += (const wielomian &v);
    wielomian& operator -= (const wielomian &v);
    wielomian& operator *= (const wielomian &v);
    wielomian& operator *= (double c);
    double operator () (double x) const; // wartość wielomianu dla x
    double operator [] (int i) const; // odczytanie i-tego współczynnika


///stream operatory

    friend istream& operator >> (istream &we, wielomian &w);
    friend ostream& operator << (ostream &wy, const wielomian &w);


};
