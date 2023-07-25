// Printing number till n using recursion function..//
#include <bits/stdc++.h>
using namespace std;

void dec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    dec(n - 1);
}

void inc(int n)
{
    if (n == 0)
    {
        return;
    }
    inc(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cout << "N: ";
    cin >> n;

    cout << "The Number is decreasing order: ";
    dec(n);
    cout << endl;

    cout << "The Number is increasion order: ";
    inc(n);
    cout << endl;

    return 0;
}