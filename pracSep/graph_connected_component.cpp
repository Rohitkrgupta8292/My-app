#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> component;
vector<bool> vis;

int get_comp(int idx)
{
    if (vis[idx])
    {
        return 0;
    }

    vis[idx] = true;
    int ans = 1;
    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            ans += get_comp(i);
            vis[i] = true;
        }
    }
    return ans;
}

int main()
{
    cout << "N and M: ";
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "U and V: ";
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            component.push_back(get_comp(i));
        }
    }
    cout << "Size of Components: ";
    for (auto i : component)
    {
        cout << i << " ";
    }
    cout<<endl;

    long long ans = 0;
    for (auto i : component)
    {
        ans += i * (n - i);
    }
    cout<<"Not releted to each other: ";
    cout << (ans / 2);
}
