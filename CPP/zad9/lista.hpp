#include <bits/stdc++.h>


namespace calc
{

template <typename T>
class list
{
    class node
    {
        T elem;
        node * next;
        node * prev;
    };
    node * fst;
    int roz;

public:
    list(std::initializer_list<T> v);
    list();
    void add(int i,T e);
    void rem(T e);
    int findelem(T e);
    int countelems();
};
}

