// the number is prime or non prime.
#include <iostream>
using namespace std;

int main()
{
    int n, i;
    cout<<"N: ";
    cin>>n;

    for(i=2; i<n; i++)
    {
        if(n%i==0)
        {
            cout<<n<<" is not a prime number"<<endl;
            break;
        }
    }
    if(i==n)
    {
       cout<<n<<" is prime a number"<<endl;
    }   
    return 0;    
}