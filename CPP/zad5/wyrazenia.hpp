#include <bits/stdc++.h>


using namespace std;



class wyrazenie
{
public:
    virtual double oblicz()=0;
    virtual string zapis()=0;
    virtual ~wyrazenie() {};
};
/// =================================== klasy
/// ===================================> liczba

class liczba : public wyrazenie
{
private:
    double wartosc;
public:
    liczba(double x);
    double oblicz();
    string zapis();
    ~liczba() {};
};

/// ===================================> zmienna

class zmienna : public wyrazenie
{
private:
    string nazwa;
    static vector< pair < string, double > > vektor;
public:
    zmienna(string x);
    double oblicz();
    string zapis();
    ~zmienna() {};
    static void nowazmienna(string x,double y);
    static void usunzmienna(string x);
    static void zmienwartosc(string x,double y);
};



/// =======================================================================> stale

class stala : public wyrazenie
{
protected:
    string nazwa;
    double wartosc;
public:
    double oblicz();
    string zapis();
    ~stala() {};
};


class pi : public stala
{
public:
    pi();
    pi(const pi &l) = delete;
    pi(pi &&l) = delete;
    pi& operator =(const pi &s) = delete;
    pi& operator =(pi &&l) = delete;
};



class e : public stala
{
public:
    e();
    e(const e&l) = delete;
    e(e&&l) = delete;
    e& operator =(const e&s) = delete;
    e& operator =(e&&l) = delete;
};


class fi : public stala
{
public:
    fi();
    fi(const fi&l) = delete;
    fi(fi&&l) = delete;
    fi& operator =(const fi&s) = delete;
    fi& operator =(fi&&l) = delete;
};


///======================================================================> operatory 1arg
class operator1arg : public wyrazenie
{
protected:
    wyrazenie * right;
public:
    ~operator1arg();
};


class sinus : public  operator1arg
{
public:
    sinus(wyrazenie * x);
    double oblicz();
    string zapis();
    sinus(const sinus&l) = delete;
    sinus(sinus&&l) = delete;
    sinus& operator =(const sinus&s) = delete;
    sinus& operator =(sinus&&l) = delete;
};


class cosinus : public  operator1arg
{
public:
    cosinus(wyrazenie * x);
    double oblicz();
    string zapis();
    cosinus(const cosinus&l) = delete;
    cosinus(cosinus&&l) = delete;
    cosinus& operator =(const cosinus&s) = delete;
    cosinus& operator =(cosinus&&l) = delete;

};


class ln : public  operator1arg
{
public:
    ln(wyrazenie * x);
    double oblicz();
    string zapis();
    ln(const ln&l) = delete;
    ln(ln&&l) = delete;
    ln& operator =(const ln&s) = delete;
    ln& operator =(ln&&l) = delete;

};



class bezwzgl : public  operator1arg
{
public:
    bezwzgl(wyrazenie * x);
    double oblicz();
    string zapis();
    bezwzgl(const bezwzgl&l) = delete;
    bezwzgl(bezwzgl&&l) = delete;
    bezwzgl& operator =(const bezwzgl&s) = delete;
    bezwzgl& operator =(bezwzgl&&l) = delete;
};


class przeciw : public  operator1arg
{
public:
    przeciw(wyrazenie * x);
    double oblicz();
    string zapis();
    przeciw(const przeciw&l) = delete;
    przeciw(przeciw&&l) = delete;
    przeciw& operator =(const przeciw&s) = delete;
    przeciw& operator =(przeciw&&l) = delete;
};



class odwrot : public  operator1arg
{
public:
    odwrot(wyrazenie * x);
    double oblicz();
    string zapis();
    odwrot(const odwrot&l) = delete;
    odwrot(odwrot&&l) = delete;
    odwrot& operator =(const odwrot&s) = delete;
    odwrot& operator =(odwrot&&l) = delete;

};



class expo : public  operator1arg
{
public:
    expo(wyrazenie * x);
    double oblicz();
    string zapis();
    expo(const expo&l) = delete;
    expo(expo&&l) = delete;
    expo& operator =(const expo&s) = delete;
    expo& operator =(expo&&l) = delete;

};


///======================================================================> operatory 2arg
class operator2arg : public operator1arg
{
protected:
    wyrazenie * lf;

public:
    ~operator2arg();
};



class dodaj : public operator2arg
{
public:
    dodaj(wyrazenie * x,wyrazenie * y);
    double oblicz();
    string zapis ();
    dodaj(const dodaj&l) = delete;
    dodaj(dodaj&&l) = delete;
    dodaj& operator =(const dodaj&s) = delete;
    dodaj& operator =(dodaj&&l) = delete;
};


class odejmij : public operator2arg
{
public:
    odejmij(wyrazenie * x,wyrazenie * y);
    double oblicz();
    string zapis ();
    odejmij(const odejmij&l) = delete;
    odejmij(odejmij&&l) = delete;
    odejmij& operator =(const odejmij&s) = delete;
    odejmij& operator =(odejmij&&l) = delete;
};


class mnoz : public operator2arg
{
public:
    mnoz(wyrazenie * x,wyrazenie * y);
    double oblicz();
    string zapis ();
    mnoz(const mnoz&l) = delete;
    mnoz(mnoz&&l) = delete;
    mnoz& operator =(const mnoz&s) = delete;
    mnoz& operator =(mnoz&&l) = delete;
};


class dziel : public operator2arg
{
public:
    dziel(wyrazenie * x,wyrazenie * y);
    double oblicz();
    string zapis ();
    dziel(const dziel&l) = delete;
    dziel(dziel&&l) = delete;
    dziel& operator =(const dziel&s) = delete;
    dziel& operator =(dziel&&l) = delete;
};


class modulo : public operator2arg
{
public:
    modulo(wyrazenie * x,wyrazenie * y);
    double oblicz();
    string zapis ();
    modulo(const modulo&l) = delete;
    modulo(modulo&&l) = delete;
    modulo& operator =(const modulo&s) = delete;
    modulo& operator =(modulo&&l) = delete;
};


class logarytm : public operator2arg
{
public:
    logarytm(wyrazenie * x,wyrazenie * y);
    double oblicz();
    string zapis ();
    logarytm(const logarytm&l) = delete;
    logarytm(logarytm&&l) = delete;
    logarytm& operator =(const logarytm&s) = delete;
    logarytm& operator =(logarytm&&l) = delete;
};



class potega : public operator2arg
{
public:
    potega(wyrazenie * x,wyrazenie * y);
    double oblicz();
    string zapis ();
    potega(const potega&l) = delete;
    potega(potega&&l) = delete;
    potega& operator =(const potega&s) = delete;
    potega& operator =(potega&&l) = delete;

};



