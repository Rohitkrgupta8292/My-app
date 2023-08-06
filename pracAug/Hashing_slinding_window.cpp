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
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    int s = 0, ans = INT_MAX;
    rep(i, 0, k)
    {
        s += a[i];
    }

    cout << s << " ";
    ans = min(ans, s);
    // slinding window..//
    rep(i, 1, n)
    {
        s -= a[i - 1];
        s += a[i + k - 1];
        ans = min(ans, s);
        cout << s << " ";
    }
    cout << endl;
    cout << "Min: " << ans << endl;
    return 0;
}