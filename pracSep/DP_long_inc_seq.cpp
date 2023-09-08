#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2, MOD = 1e9 + 7;
int dp[N];
// memoization..//
/*
int lis(vector<int> &a, int n)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[n] > a[i])
        {
            dp[n] = max(dp[n], 1 + lis(a, i));
        }
    }
    return dp[n];
}
*/

int main()
{
    // for (int i = 0; i < N; i++)
    // {
    // dp[i] = -1;
    // }
    int n;
    cout << "N: ";
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "array:" << i + 1 << ": ";
        cin >> a[i];
    }
    // bottom up or tabulation..//
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i], ans);
    }

    cout << "length of longest incresing sequence: " << ans;
    return 0;
}