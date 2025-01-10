#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
    int src, dest;
};

class BFS
{

public:
    unordered_map<int, bool> visited;
    vector<int> result;

    // Distance to each node from the source
    unordered_map<int, int> dist;
    // To store all shortest paths
    unordered_map<int, vector<vector<int>>> paths;

    BFS(int n)
    {
        result.reserve(n);
        for (int i = 0; i < n; i++)
        {
            dist[i] = INT_MAX;
        }
    }

    void bfs_alg(vector<Edge> &edges, int n)
    {

        vector<vector<int>> adj(n);
        createAdjList(edges, adj);
        // all components of the graph are visited, especially when the graph is disconnected.
        // Perform BFS for all components of the graph
        for (int s = 0; s < n; s++)
        {
            if (!visited[s])
            {
                bfs_traversal(adj, s);
            }
        }
    }

    // BFS Traversal from a source node

    void bfs_traversal(const vector<vector<int>> &adj, int start)
    {
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            result.push_back(current);
            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Function to perform BFS and find all shortest paths
    void bfs_all_shortest_paths(vector<Edge> &edges, int source, int n)
    {
        vector<vector<int>> adj(n);
        createAdjList(edges, adj);

        // Initialize source
        dist[source] = 0;
        paths[source] = {{source}};

        queue<int> q;
        q.push(source);

        // Map to store parent nodes for path reconstruction
        vector<vector<int>> parents(n);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int n : adj[current])
            {
                // If a shorter path to the neighbor is found
                if (dist[n] > dist[current] + 1)
                {
                    dist[n] = dist[current] + 1;
                    // paths[n].clear();
                    parents[n].push_back(current);

                    // for( const auto& path: paths[current]){
                    //     vector<int> newPath = path;
                    //      newPath.push_back(n);
                    //      paths[n].push_back(newPath);

                    // }
                    q.push(n);
                }
                else if (dist[n] == dist[current] + 1)
                {
                    parents[n].push_back(current);
                }
            }
        }

        // Print results
        cout << "Distances from source " << source << ":\n";
        for (int i = 0; i < n; i++)
        {
            cout << "To vertex " << i << ": ";
            if (dist[i] == INT_MAX)
                cout << "Not reachable\n";
            else
                cout << dist[i] << "\n";
        }

        // Print all shortest paths
        cout << "\nShortest paths from source " << source << ":\n";
        for (int i = 0; i < n; i++)
        {
            if (i == source)
                continue;
            if (dist[i] == INT_MAX)
            {
                cout << "No path to vertex " << i << "\n";
                continue;
            }
             printAllPaths(i, parents, source);
        }
    }
    // Recursive function to find all paths
    // v-> target
    void findPaths(int v, const vector<vector<int>> &parents, int source,
                   vector<int> &current_path, vector<vector<int>> &all_paths)
    {

        current_path.push_back(v);

        if (v == source)
        {
            all_paths.push_back(current_path);
        }
        else
        {
            for (int parent : parents[v])
            {
                findPaths(parent, parents, source, current_path, all_paths);
            }
        }
        current_path.pop_back();

    }

    void printAllPaths(int v, const vector<vector<int>>& parents, int source) {
        vector<vector<int>> all_paths;
        vector<int> current_path;
        findPaths(v, parents, source, current_path, all_paths);
        
        cout << "All shortest paths to vertex " << v << ":\n";
        for (const auto& path : all_paths) {
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i];
                if (i > 0) cout << " -> ";
            }
            cout << "\n";
        }
    }

    void addEdge(vector<Edge> &edges, int u, int v)
    {
        edges.push_back({u, v});
    }

    void createAdjList(vector<Edge> &edges, vector<vector<int>> &adj)
    {
        for (Edge &edge : edges)
        {
            adj[edge.src].push_back(edge.dest);
            adj[edge.dest].push_back(edge.src);
        }
    }

    // Function to print the BFS result
    void printResult()
    {
        cout << "BFS Traversal Order: ";
        for (int node : result)
        {
            cout << node << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 8;
    BFS bfs(n);
    vector<Edge> edges;

    // Add edges to the bfs
    bfs.addEdge(edges, 0, 1);
    bfs.addEdge(edges, 0, 2);
    bfs.addEdge(edges, 1, 3);
    bfs.addEdge(edges, 1, 4);
    bfs.addEdge(edges, 2, 5);
    bfs.addEdge(edges, 3, 6);
    bfs.addEdge(edges, 4, 6);
    bfs.addEdge(edges, 5, 7);

    // Perform BFS
    bfs.bfs_alg(edges, n);

    // Print the BFS result
    bfs.printResult();

    bfs.bfs_all_shortest_paths(edges,0,n);
}