// Maximum sum of subarray..//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "N: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the element of array:\n";
    for (auto &x : a)
    {
        cin >> x;
    }

    int curr = 0, maxTillNow = 0;
    for (int i = 0; i < n; i++)
    {
        curr += a[i];
        maxTillNow = max(curr, maxTillNow);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    cout << "Sum of maximum subarray: " << maxTillNow;
    return 0;
}