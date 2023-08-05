#include <bits/stdc++.h>
using namespace std;

// define int long long..//
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main()
{
    int n, k;
    cout << "N: ";
    cin >> n;
    cout << "K: ";
    cin >> k;

    vi a(n);
    cout << "Array: ";
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    priority_queue<int, vi> pq;

    rep(i, 0, n)
    {
        pq.push(a[i]);
    }

    int sum = 0;
    int count = 0;

    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();

        count++;

        if (sum >= k)
        {
            break;
        }
    }

    if (sum < k)
    {
        cout << "No subsequence!\n";
    }
    else
    {
        cout << count << endl;
    }
    return 0;
}