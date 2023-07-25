// Euclid Alogorithm to find Greatest commom divisor..//
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while(b!= 0)
    {
        int rem =  a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main()
{
    int a, b;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;

    cout<<"The GCD between "<<a<<" and "<<b<<": "<<gcd(a, b)<<endl;
    return  0;
}