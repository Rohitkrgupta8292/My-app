#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;
    
    int sum=0;
    int originaln=n;
    while(n>0)
    {
        int lastdigit = n%10;
        sum += pow(lastdigit,3);
        n /= 10;
    }
    if(sum==originaln)
    {
        cout<<"Armstrong Number!\n";
    }
    else
    {
        cout<<"Not a Armstrong Number!\n";
    }

return 0;

}