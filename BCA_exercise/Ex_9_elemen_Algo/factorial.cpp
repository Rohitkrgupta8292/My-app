// finding factorial of an integer using recursion..//
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    int fac = 1;
    if (n == 0 || n == 1)
    {
        return fac;
    }
    else
    {
        fac = n * factorial((n - 1));
        return fac;
    }
}

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<factorial(n);
    return 0;
}