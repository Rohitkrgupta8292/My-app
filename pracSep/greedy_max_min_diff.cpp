#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "N: ";
    cin >> n;

    vector<int> a(n);
    cout << "enter the element of array:\n";
    for (auto &i : a)
    {
        cin >> i;
    }
    sort(a.begin(), a.end());
    long long mn = 0, mx = 0;
    for (int i = 0; i < n / 2; i++)
    {
        mx += (a[i + n / 2] - a[i]);
        mn += (a[2 * i + 1] - a[2 * i]);
    }
    cout << "Maximum difference: " << mx << endl;
    cout << "Minimum difference: " << mn;
    return 0;
}