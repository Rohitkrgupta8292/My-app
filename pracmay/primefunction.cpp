#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int num);

int main()
{
    int a,b;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;

    for(int i=a; i<=b; i++)
    {
        if(isprime(i))
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
bool isprime(int num)
{
    for(int i=2; i<=sqrt(num); i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}