
#include "wymierne.hpp"

using namespace std;

using namespace wym;

int main()
{

    wymierna test1=wymierna(4,5);
    wymierna test2=wymierna(3,2);
    wymierna test3=test1*test2;
    wymierna test4=test1-test2;
    wymierna test5=!test1;
    wymierna test6=-test1;
    test1.wypisz();
    cout << "\n";
    test2.wypisz();
    cout << "\n";
    test3.wypisz();
    cout << "\n";
    test4.wypisz();
    cout << "\n";
    test5.wypisz();
    cout << "\n";
    test6.wypisz();
    cout << "\n";
    try{
        wymierna test7=wymierna(1,0);
    }
    catch(dzielenie_przez_zero c)
    {
        cout << c.what() << "\n";
    }
    cout << (double)test1 << "\n";
    cout << (int)test2 << "\n";




}


