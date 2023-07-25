// finding factorial using recursion function..//
#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int prevFact = factorial(n - 1);
    return n * prevFact;
}

int main()
{
    int n;
    cout << "N: ";
    cin >> n;
    cout << factorial(n)<<endl;
    return 0;
}