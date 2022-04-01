#include <iostream>
#include<string>
#include<vector>
#include"kolejka.hpp"

using namespace std;

int main()
{
    bool start=0;
    kolejka* test;
    while(start==0)
    {
        start =1;
        cout << "Enter desired size for the queue:\n";
        int n;
        cin >> n;
        try
        {
            test=new kolejka(n);
        }
        catch (const std::bad_alloc& e)
        {
            cout << "size request incorrect - try again\n";
            start=0;
        }
    }
    char c='g';
    string x;
    while(c!='Q')
    {
        cout << "=======================================================================\n";
        cout << "enter: A <string> to add a string to the queue\n";
        cout << "       F to get the front of the queue\n";
        cout << "       R to get current size of the queue\n";
        cout << "       P to remove element from the front of the queue\n";
        cout << "       Q to stop \n";
        cout << "=======================================================================\n";
        cin >> c;
        if(c=='A')
        {
            cin >> x;
            try
            {
                test->wloz(x);
                cout << "output: element added to the queque\n";
            }
            catch(const char* msg)
            {
                cout <<"error: queue is full\n";
            }

        }
        else if(c=='F')
        {
            try{
            cout << "output: queue front == " << test->naprzodzie() << "\n";
            }
            catch(const char* msg)
            {
                cout <<"error: queue is empty\n";
            }
        }
        else if(c=='P')
        {
            try{
            cout << "output: element: " << test->wyciagnij() << " removed from the front\n";
            }
            catch(const char* msg)
            {
                cout <<"error: queue is empty\n";
            }
        }
        else if(c=='R')
        {
            cout << "output: queue size: " << test->rozmiar()<< "\n";
        }

    }

    delete test;

}


