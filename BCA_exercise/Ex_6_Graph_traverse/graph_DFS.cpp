#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
bool vis[N];
vector<char> graph[N];

void dfs(char node)
{
    vis[node] = true; // preorder..//
    cout << node << " ";

    vector<char>::iterator it;
    for (it = graph[node].begin(); it != graph[node].end(); it++)
    {
        if (!vis[*it])
        {
            dfs(*it);
        }
    }
}

int main()
{
    int n, m;
    cout << "N and M: ";
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        vis[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
        char x, y;
        cout << "X and Y: ";
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs('A');
    return 0;
}