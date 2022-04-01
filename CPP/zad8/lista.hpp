#include <bits/stdc++.h>

using namespace std;

namespace wym
{

class wymierna
{
    int licz,mian;
public:
    wymierna(int l,int m);
    wymierna(int x);
    int getLicz();
    int getMian();
    friend ostream& operator<< (ostream &wyj, const wymierna &w);
    friend wymierna operator +(const wymierna &x, const wymierna &y);
    friend wymierna operator -(const wymierna &x, const wymierna &y);
    friend wymierna operator *(const wymierna &x, const wymierna &y);
    friend wymierna operator /(const wymierna &x, const wymierna &y);
    void wypisz();
    wymierna operator ! ();
    wymierna operator - ();
    operator int() const;
    operator double() const;
};


class wyjatek_wymierny : public std::exception
{
    const char* str;
public:
    explicit wyjatek_wymierny(const char* what) : str(what) {};
    virtual auto what() const noexcept -> const char*  { return str; };
};

class dzielenie_przez_zero : public wyjatek_wymierny
{
public:
    explicit dzielenie_przez_zero(const char* what) : wyjatek_wymierny(what) {};
};

class przekroczenie_zakresu : public wyjatek_wymierny
{
public:
    explicit przekroczenie_zakresu(const char* what) : wyjatek_wymierny(what) {};
};
}

