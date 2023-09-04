#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
int main()
{
    int n, m;
    cout << "N and M: ";
    cin >> n >> m;
    vector<int> dist(n + 1, inf);
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "U and V and W: ";
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int src;
    cout << "source: ";
    cin >> src;

    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        auto x = *s.begin();
        s.erase(x);
        for (auto i : graph[x.second])
        {
            if (dist[i.first] > dist[x.second] + i.second)
            {
                s.erase({dist[i.first], i.first});
                dist[i.first] = dist[x.second] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }
    for (int i = 1; i <=n; i++)
    {
        if (dist[i] < inf)
        {
            cout << dist[i] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    return 0;
}