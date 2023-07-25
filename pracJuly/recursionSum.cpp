#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int prevSum = sum(n - 1);
    return n + prevSum;
}

int main()
{
    int n;
    cout<<"N: ";
    cin>>n;

    cout<<"The sum till "<<n<<": "<<sum(n)<<endl;
    return 0;
}