// inclusion and exclusion principle..//
#include <bits/stdc++.h>
using namespace std;

int divisible(int n, int a, int b)
{
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);

    return c1+c2-c3;
}

int main()
{
    int n,a,b;

    cout<<"N: ";
    cin>>n;

    cout<<"A: ";
    cin>>a;

    cout<<"B: ";
    cin>>b;

    cout<<"Total Number divisible by "<<a<<" and "<<b<<": "<<divisible(n,a,b)<<endl;
   
    return 0;
}