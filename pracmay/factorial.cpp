#include <iostream>
using namespace std;
int fact(int n);

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;

    int ans = fact(n);
    cout<<ans<<endl;
    return 0;
}

int fact(int n)
{
    int factorial = 1;

    for(int i=2; i<=n; i++)
    {
        factorial *= i;
    }
    return factorial;
}