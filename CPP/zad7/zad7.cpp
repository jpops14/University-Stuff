///#define NDEBUG
#include <bits/stdc++.h>
#include "tabdbl.hpp"

using namespace std;

using namespace dbltab;

int main()
{
   tab_dbl * test=new tab_dbl(5);
   cout << "Testowanie indeksowania: \n"<< (*test)[3] << "\n";
   (*test)[3]=2;
    cout << (*test)[3] << "\n";

    cout << "Obsługa wyjątków:\n";
    try{
        tab_dbl * test2=new tab_dbl(-1);
    }
    catch(const std::invalid_argument& e)
    {
        cout << e.what();
    }
    try{
        (*test)[12]=3;
    }
    catch(const std::out_of_range& e)
    {
        cout << e.what();
    }
    cout << "Konstruktor bezargumentowy:\n";
   ///tab_dbl * test3=new tab_dbl();
   ///cout << (*test3).getdl() <<"\n";

    cout << "Operator mnożenia i assercje: \n";
    tab_dbl test4={1,2,3,4,5};
    tab_dbl test5={1,2,3,4,5};
    tab_dbl test6={1,2,3,4};
    tab_dbl test7=test4*test5;
    cout << "mnożenie zakończone powodzeniem\n";
    tab_dbl test8=test5*test6;
    cout << "mnożenie zakończone powodzeniem\n";

}


