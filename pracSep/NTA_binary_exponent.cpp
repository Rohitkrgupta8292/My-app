// finding binary exponentiation..//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2, MOD = 1e9 + 7;

int power(int a, int n)
{
    a %= MOD;
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        n = n >> 1;
    }
    return ans;
}

int powerRecursive(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int p = (powerRecursive(a, n / 2) % MOD);
    if (n & 1)
    {
        return (((p * p) % MOD) * a) % MOD;
    }
    else
    {
        return (p * p) % MOD;
    }
}

int main()
{
    int a, n;
    cout << "A and N: ";
    cin >> a >> n;
    a %= MOD;
    cout << power(a, n) << endl;  // iterative algorithm../
    cout << powerRecursive(a, n); // recursive algorithms..//
    return 0;
}