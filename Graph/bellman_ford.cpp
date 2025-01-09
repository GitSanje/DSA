#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

struct Edge {
    int src, dest, weight;
};

class BellmanFord {
public:
    vector<int> dist;

    // Constructor
    BellmanFord(int n) {
        dist.resize(n, INT_MAX);
    }

    bool bellman_ford(vector<Edge>& edges, int src, int N) {
        dist[src] = 0;

        // Relax edges (N - 1) times
        for (int i = 0; i < N - 1; i++) {
            for (Edge& edge : edges) {
                if (dist[edge.src] != INT_MAX && dist[edge.src] + edge.weight < dist[edge.dest]) {
                    dist[edge.dest] = dist[edge.src] + edge.weight;
                }
            }
            
            // Print distances after each iteration
            // cout << "Iteration " << i + 1 << ": ";
            // for (int d : dist) {
            //     if (d == INT_MAX) {
            //         cout << "INF ";
            //     } else {
            //         cout << d << " ";
            //     }
            // }
            // cout << endl;
        }
        
             // Check for negative cycles
    for (Edge& edge : edges) {
        if (dist[edge.src] !=INT_MAX && 
            dist[edge.src] + edge.weight < dist[edge.dest]) {
            return true; // Negative cycle detected
        }
    }

    return false;
        
         
    }




};

int main() {
    vector<Edge> edges = {
        {0, 1, 6}, {0, 2, 5}, {0, 3, 5}, {1, 4, -1},
        {2, 1, -2}, {2, 4, 1}, {3, 2, -2}, {3, 5, -1},
        {4, 6, 3}, {5, 6, 3}
    };

    int N = 7; // Number of vertices
    int src = 0;
    BellmanFord bfd(N);
   

    if ( bfd.bellman_ford(edges, src, N)) {
        cout << "Graph contains negative cycle" << endl;
    } else {
        cout << "Shortest distances from source vertex " << src << ":" << endl;
        for (int i = 0; i < N; i++) {
            if (bfd.dist[i] != INT_MAX) {
                cout << src << " -> " << i << " : " << bfd.dist[i] << endl;
            } else {
                cout << src << " -> " << i << " : " << "INF" << endl;
            }
        }
    }

    return 0;
}
