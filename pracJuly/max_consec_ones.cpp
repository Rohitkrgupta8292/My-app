#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cout << "N: ";
    cin >> n;
    cout << "K: ";
    cin >> k;
    vector<int> a(n);
    cout<<"Enter the element of array!\n";
    for (auto &i : a)
    {
        cin >> i;
    }
    int zerocnt = 0, i = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            zerocnt++;
        }
        while (zerocnt > k)
        {
            if (a[i] == 0)
            {
                zerocnt--;
            }
            i++;
        }
        ans = max(ans, (j - i + 1));
    }
    cout << ans << endl;
    return 0;
}