// friends pairing problem..//
#include <bits/stdc++.h> // for std::pair, std::make_pair and other stuffs.
using namespace std;

int main()
{
    int n;
    cout << "N: ";
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    cout << "Possible ways to pair friends: " << dp[n];
    return 0;
}