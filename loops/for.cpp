#include <iostream>
using namespace std;

int main()
{
    int n, sum=0;
    cout<<"N: ";
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        sum += i;
    }
    cout<<"Sum: "<<sum;
    cout<<endl;

    return 0;
}