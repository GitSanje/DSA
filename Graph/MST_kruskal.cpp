#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge

struct Edge
{
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Disjoint Set Union (DSU) or Union-Find structure

class DSU
{

// private:
//     vector<int> parent, rank;

public:
   vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find the parent of a node with path compression
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union two sets by rank

    bool unite(int x, int y)
    {
        // cout << x << " -- " << y << " == " << "\n";
        int rootX = find(x);
        int rootY = find(y);                       
        // lies on the same group
        if (rootX == rootY)
            return false;
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY; // change the parent of rootX to rootY
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

// Kruskal's Algorithm

vector<Edge> kruskal(int V, vector<Edge> &edges)
{

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(V);

    // Resultant MST edges
    vector<Edge> mst;
   
    cout << "sorted edges  :\n";
    for (Edge &edge : edges)
    { 
         cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
        if (dsu.unite(edge.src, edge.dest))
        {
            mst.push_back(edge);
        }
    }
    // Print the parent array
    cout << "\nParent Array After Kruskal:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": Parent -> " << dsu.parent[i] << "\n";
    }

    // Print the rank array
    cout << "\nRank Array After Kruskal:\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": Rank -> " << dsu.rank[i] << "\n";
    }


    return mst;
}

int main()
{
    int V = 7; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 2}, {0, 2, 6}, {1, 3, 5}, {2, 3, 8}, {3, 4, 10}, {3, 5, 15}, {4, 5, 6}, {4, 6, 2}, {5, 6, 6}};

    vector<Edge> mst = kruskal(V, edges);

    cout << "Edges in the Minimum Spanning Tree:\n";
    int totalWeight = 0;
    for (Edge &edge : mst)
    {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
        totalWeight += edge.weight;
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";

    

    return 0;
}