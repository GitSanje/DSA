#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
#include <sstream>

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
    unordered_map<int, vector<int>> isPathexits;

    BFS(int n)
    {
        result.reserve(n);
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

    unordered_map<string, vector<vector<int>>> getAllPairsShortestPaths(vector<Edge> &edges, int n)
    {
        unordered_map<string, vector<vector<int>>> all_pairs_paths;
        unordered_map<int, vector<int>> isPathexits; // Tracks recorded paths to avoid duplicates

        for (int source = 0; source < n; source++)
        {
            unordered_map<int, vector<vector<int>>> paths_from_source = bfs_all_shortest_paths(edges, source, n);

            // Store paths from this source to all targets
            for (const auto &[target, paths] : paths_from_source)
            {
                bool exists = false;
                string key = to_string(source) + "," + to_string(target);

                if (!exists && !isPathexits[target].empty())
                {
                    for (const auto &path_source : isPathexits[target])
                    {
                        if (path_source == source)
                        {
                            exists = true;
                            break;
                        }
                    }
                }

                // Add the path if it does not exist in `isPathexits`
                if (!exists)
                {
                    isPathexits[source].push_back(target);
                    all_pairs_paths[key] = paths;
                }
            }
        }

        return all_pairs_paths;
    }

    // Function to perform BFS and find all shortest paths
    unordered_map<int, vector<vector<int>>> bfs_all_shortest_paths(vector<Edge> &edges, int source, int n)
    {
        vector<vector<int>> adj(n);
        unordered_map<int, vector<vector<int>>> paths;
        createAdjList(edges, adj);

        unordered_map<int, int> dist(n);
        for (int i = 0; i < n; i++)
            dist[i] = INT_MAX;

        // Initialize source
        dist[source] = 0;
        paths[source] = {{source}};

        queue<int> q;
        q.push(source);

        // Map to store parent nodes for path reconstruction
        vector<vector<int>> parents(n);
        parents[source] = {{source}};

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
                    // parents[n].clear();// Clear old parents
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
                    // Check if this parent already exists to avoid duplicates
                    // if (find(parents[n].begin(), parents[n].end(), current) == parents[n].end())
                    // {
                    parents[n].push_back(current);
                    // }
                }
            }
        }

        // Reconstruct all paths from source to every node
        for (int i = 0; i < n; i++)
        {
            if (dist[i] != INT_MAX && i != source)
            {
                vector<int> current_path;
                findPaths(i, parents, source, current_path, paths[i]);
            }
        }

        return paths;
    }

    vector<double> bt_centrality(vector<Edge> &edges, int n)
    {

        vector<double> CB(n, 0.0);
        unordered_map<string, vector<vector<int>>> all_paths_pairs = getAllPairsShortestPaths(edges, n);
        int allsize = all_paths_pairs.size();
        for (int v = 0; v < n; v++)
        {

            for (const auto &[target, paths] : all_paths_pairs)
            {
                stringstream ss(target);
                string src_str, tgt_str;
                getline(ss, src_str, ',');
                getline(ss, tgt_str);

                int src = stoi(src_str);
                int tgt = stoi(tgt_str);
                if (v == src || v == tgt)
                {
                    continue;
                }
                for (const auto &path : paths)
                {
                    for (const auto &p : path)
                    {
                        if (p == v)
                        {
                            CB[v]++;
                        }
                    }
                }
            }
            CB[v] = CB[v] / allsize;
        }

        return CB;
    }
    // Recursive function to find all paths
    // v-> target
    void findPaths(int v, const vector<vector<int>> &parents, int source,
                   vector<int> &current_path, vector<vector<int>> &all_paths)
    {

        current_path.push_back(v);

        if (v == source)
        {
            vector<int> path = current_path;
            //  reverse(path.begin(), path.end());
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

    void printAllPaths(unordered_map<string, vector<vector<int>>> all_paths)
    {
        for (const auto &[target, paths] : all_paths)
        {
            stringstream ss(target);
            string src_str, tgt_str;
            getline(ss, src_str, ',');
            getline(ss, tgt_str);

            int src = stoi(src_str);
            int tgt = stoi(tgt_str);

            cout << "All shortest paths from " << src << " to " << tgt << ":\n";
            for (const auto &path : paths)
            {
                for (int i = path.size() - 1; i >= 0; i--)
                {
                    cout << path[i];
                    if (i > 0)
                        cout << " -> ";
                }
                cout << "\n";
            }
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
    // bfs.printResult();

    unordered_map<string, vector<vector<int>>> all_paths = bfs.getAllPairsShortestPaths(edges, n);

    // bfs.printAllPaths(all_paths);
    cout << "size of all paths" << all_paths.size() << endl;
    vector<double> cbs = bfs.bt_centrality(edges, n);
    int i = 0;
    cout << "Betweenness centralities" << endl;
    for (const auto &cb_v : cbs)
    {
        cout << "CB of " << i << ": " << cb_v << endl;
        i++;
    }
}