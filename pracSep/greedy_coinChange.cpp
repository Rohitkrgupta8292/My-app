// fiinding the minimum coins or notes using greedy approach..//
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main()
{
    int n;
    cout<<"N: ";
    cin>>n;

    vi a(n);
    rep(i , 0 , n){
        cin >>a[i];
    }
    int x;
    cout<<"X: ";
    cin>>x;

    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }
    cout<<"answer: "<<ans<<endl;
    return 0;
}