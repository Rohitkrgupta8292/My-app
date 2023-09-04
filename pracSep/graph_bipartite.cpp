#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipart;

void color(int u, int curr)
{
    if (col[u] != -1 and col[u] != curr)
    {
        bipart = false;
        return;
    }
    col[u] = curr;
    if (vis[u])
    {
        return;
    }
    vis[u] = true;
    for (auto i : adj[u])
    {
        color(i, curr xor 1);
    }
}

int main()
{
    int n, m;
    cout << "N and M: ";
    cin >> n >> m;
    bipart = true;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "U and V: ";
        cin >> u >> v;
        adj[u].push_back(v); // add edge from u to v in graph.
        adj[v].push_back(u); // add reverse edge also.
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            color(i, 0);
        }
    }
    if (bipart)
    {
        cout << "Graph is bipart";
    }
    else
    {
        cout << "Graph is not bipart";
    }
    cout << endl;
    return 0;
}