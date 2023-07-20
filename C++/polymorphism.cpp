#include <bits/stdc++.h>
using namespace std;

// function overloading..//
class Apnacollege
{
public:
    void fun()
    {
        cout << "I am a function with no argument!\n";
    }

    void fun(int x)
    {
        cout << "I am  a function with int argument!\n";
    }

    void fun(double x)
    {
        cout << "I am a function with double argumenst!\n";
    }
};

int main()
{
    Apnacollege obj;
    obj.fun();
    obj.fun(4);
    obj.fun(6.2);

    return 0;
}