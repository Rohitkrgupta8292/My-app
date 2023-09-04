#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N);

void makeset(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void unionSet(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        makeset(i);
    }
    int n, m;
    cout << "N and M: ";
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "U and v: ";
        cin >> u >> v;
        edges.push_back({u, v});
    }
    bool cycle = false;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);
        if (x == y)
        {
            cycle = true;
        }
        else
        {
            unionSet(u, v);
        }
    }
    if (cycle)
    {
        cout << "cycle is present";
    }
    else
    {
        cout << "cycle is not present";
    }
    cout << endl;
    return 0;
}