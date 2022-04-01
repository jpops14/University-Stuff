#include <bits/stdc++.h>
#include "wielomiany.hpp"
using namespace std;


int main()
{
    double tab1[5]= {1,1,1,1,1};
    double tab2[7]= {2,2,2,2,2,2,2};
    wielomian * test1=new wielomian(4,tab1);
    wielomian * test2=new wielomian(6,tab2);

    cout << (*test1)(2) << "\n";

    wielomian test5=(*test1)*(*test2);
    cout << test5 << "\n";

    wielomian test3=*test1+*test2;
    cout << test3 << "\n";

    wielomian test4=*test1-*test2;
    cout << test4 << "\n";

    *test1+=*test2;
    cout << *test1 << "\n";


    (*test2)[0]=5;
    cout << *test2 << "\n";

    cin >> *test1;
    cout << *test1;



}


