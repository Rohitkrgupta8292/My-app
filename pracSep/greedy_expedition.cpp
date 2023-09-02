#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cout << "T: ";
    cin >> t;

    while (t--)
    {
        int n;
        cout << "N: ";
        cin >> n;

        vector<pair<int, int>> a(n);
        cout<<"Enter the element of vector:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }

        int l, p;
        cout << "L: ";
        cin >> l;
        cout << "P: ";
        cin >> p;

        for (int i = 0; i < n; i++)
        {
            a[i].first = l - a[i].first;
        }

        sort(a.begin(), a.end());

        int ans = 0;
        int curr = p;

        priority_queue<int, vector<int>> pq;

        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (curr >= l)
                break;
            while (curr < a[i].first)
            {
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if (flag)
                break;
            pq.push(a[i].second);
        }

        if (flag)
        {
            cout<<"flag " << "-1" << endl;
            continue;
        }

        while (!pq.empty() && curr < l)
        {
            curr += pq.top();
            pq.pop();
            ans++;
        }

        if (curr < l)
        {
            cout <<"curr" << "-1" << endl;
            continue;
        }

        cout << "No of minimum stop: " << ans;
    }
    return 0;
}