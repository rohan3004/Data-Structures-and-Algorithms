#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <iostream>
#include <vector>
using namespace std;

#define INF 99999

class Graph {
private:
    int V;
    vector<vector<int>> dist;

public:
    Graph(int vertices) : V(vertices) {
        dist.resize(V, vector<int>(V, INF));
        for (int i = 0; i < V; ++i)
            dist[i][i] = 0; // Distance from a vertex to itself is always 0
    }

    void addEdge(int src, int dest, int weight) {
        dist[src][dest] = weight;
    }

    void floydWarshall() {
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Print the shortest distances
        cout << "Shortest distances between every pair of vertices:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
    static void execute()
    {
        int V, E;
        cout << "Enter the number of vertices and edges: ";
        cin >> V >> E;
        Graph graph(V);
        cout << "Enter the edges and their weights (source destination weight):\n";
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.addEdge(u, v, w);
        }
        graph.floydWarshall();
    }
};

#endif