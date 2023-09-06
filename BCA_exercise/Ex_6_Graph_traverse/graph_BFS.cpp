#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
bool vis[N];
vector<char> graph[N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }

    int n, m;
    cout << "N and M: ";
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        char x, y;
        cout << "X and Y: ";
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    queue<char> q;
    q.push('A');
    vis['A'] = 1;

    while (!q.empty())
    {
        char node = q.front();
        q.pop();
        cout << node << " ";

        vector<char>::iterator it;
        for (it = graph[node].begin(); it != graph[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
    return 0;
}
