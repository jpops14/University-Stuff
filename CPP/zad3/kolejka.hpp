#include <iostream>
#include<string>
#include<vector>


using namespace std;

class kolejka
{
private:
    int pocz;
    int ile;
    int pojemnosc;
    string *kol;

public:
    void wloz(string x);
    string naprzodzie();
    string wyciagnij();
    int rozmiar();


    kolejka(int newsize);
    kolejka();
    kolejka(std::initializer_list<string> l);
    kolejka(const kolejka& q);
    kolejka(kolejka&& q);

    kolejka& operator = (const kolejka &q);
    kolejka& operator = (kolejka &&q);


    ~kolejka();
};

