// print all prime number between two number.
#include <iostream>
using namespace std;

int main()
{
    int a,b,i,j;
    cout<<"A: ";
    cin>>a;
    cout<<"B: ";
    cin>>b;
  
    for(i=a; i<=b; i++)
    {
        for(j=2; j<i; j++)
        {
            if(i%j==0)
            {
               break;
            }
        }
        if(j == i)
        {
           cout<<i<<" is a prime number"<<endl;
        }
    }
    return 0;
}