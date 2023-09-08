// finding the minimum number of jumps to reach the end..//
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main()
{
    int n;
    cout << "N: ";
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    vector<int> jumps(n, inf);
    if (arr[0] == 0)
    {
        cout << inf << " ";
    }
    jumps[0] = 0; // first jump is always zero.
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + arr[j]))
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
            }
        }
    }
    cout <<"Jumps: "<< jumps[n - 1];
    return 0;
}