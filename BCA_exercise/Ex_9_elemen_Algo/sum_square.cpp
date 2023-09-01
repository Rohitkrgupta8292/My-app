// finding the sum of square of two integer..//
#include <bits/stdc++.h>
using namespace std;

long int SumofSquare(int a, int b)
{
    int sum;
    sum = (pow(a,2) + pow(b,2));
    return sum;
}

int main()
{
    int a,b;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;
    cout<<"Sum of Square of "<<a<<" and "<<b<<" : "<<SumofSquare(a , b);
    return 0;
}