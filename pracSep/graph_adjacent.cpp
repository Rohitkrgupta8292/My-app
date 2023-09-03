// adjaceny matrix in graph...//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2, MOD = 1e9 + 7;
vector<int> adj[N];

int main()
{
    // representation of graph..//
    int n, m;
    cout << "N and M: ";
    cin >> n >> m;

    int s = n + 1;

    vector<vector<int>> adjm(s, vector<int>(s, 0)); // 2d array..//

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cout << "X and Y: ";
        cin >> x >> y;

        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    cout << "adjaceny matrix of above graph is given by: " << endl;
    for (int i = 1; i < s; i++)
    {
        for (int j = 1; j < s; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    if (adjm[3][7] == 1)
    {
        cout << "there is a edge between 3 and 7";
    }
    else
    {
        cout << "No edges";
    }
    cout << endl;

 // adjacency list of graph..//
    cout<<"N and M: ";
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cout << "X and Y: ";
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << endl;
    cout << "adjacency list of the above graph is given by:\n";

    for (int i = 1; i < n + 1; i++)
    {
        cout << i << " ->";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}