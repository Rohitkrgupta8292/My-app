#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "N: ";
    cin >> n;
    vector<int> bin(n + 2, 0);
    bin[0] = 1;
    bin[1] = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        bin[i] = bin[i - 1] + bin[i - 2];
    }
    cout << "No of binary string: " << bin[n + 1];
    return 0;
}