#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent a weighted edge
struct Edge
{
    int target; // Target vertex
    int weight; // Weight of the edge
};

// Define a function to find the shortest path using Dijkstra's algorithm
void shortestPath(vector<vector<Edge>> &graph, int source, int target)
{
    int n = graph.size();                            // Number of vertices
    vector<int> dist(n, numeric_limits<int>::max()); // Initialize distances
    vector<int> prev(n, -1);                         // Initialize previous vertices
    dist[source] = 0;                                // Distance to source is 0

    // Create a min heap to keep track of vertices with minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Explore neighbors of u
        for (const Edge &edge : graph[u])
        {
            int v = edge.target;
            int weight = edge.weight;

            // Relaxation step
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest path and its distance
    if (dist[target] == numeric_limits<int>::max())
    {
        cout << "No path exists from " << source << " to " << target << endl;
    }
    else
    {
        cout << "Shortest path from " << source << " to " << target << ": ";
        vector<int> path;
        int u = target;
        while (u != -1)
        {
            path.push_back(u);
            u = prev[u];
        }
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i];
            if (i > 0)
                cout << " -> ";
        }
        cout << ", Distance: " << dist[target] << endl;
    }
}

int main()
{
    int n, m; // Number of vertices
    cout << "N and M: ";
    cin >> n >> m;
    vector<vector<Edge>> graph(n+1);

    // Add edges to the graph
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "U and V and W: ";
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    int source, target;
    cout << "source and target: ";
    cin >> source>> target;

    shortestPath(graph, source, target);

    return 0;
}
