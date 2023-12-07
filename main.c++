#include "Non-Linear\Floyd_Warshall.h"
int main()
{
    int V, E;
        cout << "Enter the number of vertices and edges: ";
        cin >> V >> E;
        FloydWarshall graph(V);
        cout << "Enter the edges and their weights (source destination weight):\n";
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.addEdge(u, v, w);
        }
        graph.floydWarshall();
}