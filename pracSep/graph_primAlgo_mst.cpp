#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 3;
vector<vector<int>> g[N];
int cost = 0;
vector<int> dist(N), parent(N);
vector<bool> vis(N);
const int INF = 1e9;

void primsMST(int src)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[src] = 0;
    s.insert({0, src});
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w<<endl;;
        cost += w;
        for (auto i : g[x[1]])
        {
            if (vis[i[0]])
            {
                continue;
            }
            if (dist[i[0]] > i[1])
            {
                s.erase({dist[i[0]], i[0]});
                dist[i[0]] = i[1];
                s.insert({dist[i[0]], i[0]});
                parent[i[0]] = x[1];
            }
        }
    }
}

int main()
{
    cout << "N and M: ";
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "U and v and W: ";
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsMST(0);
    cout << "Cost: " << cost;
}