#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int val[N], wt[N];

int dp[N][N];

/* recursion
int knapsack(int n, int w)
{
    if (w <= 0)
    {
        return 0;
    }
    if (n <= 0)
    {
        return 0;
    }
    if (wt[n - 1] > w)
    {
        return knapsack(n - 1, w);
    }
    return max(knapsack(n - 1, w), knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);
}
*/
// memoization..//
int knapsackk(int n, int w)
{
    if (w <= 0)
    {
        return 0;
    }
    if (n <= 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (wt[n - 1] > w)
    {
        dp[n][w] = knapsackk(n - 1, w);
    }
    else
    {
        dp[n][w] = max(knapsackk(n - 1, w), knapsackk(n - 1, w - wt[n - 1]) + val[n - 1]);
    }

    return dp[n][w];
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = -1;
        }
    }
    int n;
    cout << "N: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "weight: ";
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "value: ";
        cin >> val[i];
    }

    int w;
    cout << "W: ";
    cin >> w;

    cout << knapsackk(n, w);

    return 0;
}