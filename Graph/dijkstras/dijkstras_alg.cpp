#include <iostream>
#include <vector>
#include <utility> // For std::pair

using namespace std;

// Function to add an edge to the graph

void addEdge(std::vector<std::pair<int, int>> adj[], int u, int v, int weight)
{
    adj[u].emplace_back(v, weight); // Add directed edge (u -> v)
    adj[v].emplace_back(u, weight); // Add directed edge (v -> u) for undirected graph
}

// Function to print the graph

void printGraph(const std::vector<std::pair<int, int>> adj[], int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        std::cout << "Node" << i << "->";

        for (const auto &edge : adj[i])
        {
            std::cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}

// Function to find the vertex with the minimum distance
int findMinDistance(const vector<int> &dist, const vector<bool> &visited, int V)
{

    int minDist = INT_MAX, minIndex = -1;
    for (int i = 0; i < V; ++i)
    {

        if (!visited[i] && dist[i] < minDist)
        {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}
// Dijkstra's algorithm (naive implementation)
void dijkstra(const std::vector<std::vector<int>> &graph, int src)
{

    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    // Distance to the source is 0
    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count)
    {
        int u = findMinDistance(dist, visited, V);

        visited[u] = true;

        for (int v = 0; v < V; ++v)
        {

            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the results
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    const int nodes = 7;                         // Total number of nodes (0-6)
    std::vector<std::pair<int, int>> adj[nodes]; // Adjacency list

    // Adding edges with weights
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 6);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 2, 3, 8);
    addEdge(adj, 3, 4, 10);
    addEdge(adj, 3, 5, 15);
    addEdge(adj, 4, 5, 6);
    addEdge(adj, 4, 6, 2);
    addEdge(adj, 5, 6, 6);

    std::vector<std::vector<int>> graph = {
        {0, 2, 6, 0, 0, 0, 0},
        {2, 0, 0, 5, 0, 0, 0},
        {6, 0, 0, 8, 0, 0, 0},
        {0, 5, 8, 0, 10, 15, 0},
        {0, 0, 0, 10, 0, 6, 2},
        {0, 0, 0, 15, 6, 0, 6},
        {0, 0, 0, 0, 2, 6, 0}};

    // Print the graph
    printGraph(adj, nodes);
    int source = 0; // Source vertex
    dijkstra(graph, source);

    return 0;
}  