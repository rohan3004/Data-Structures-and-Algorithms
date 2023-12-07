/*Copyright© 2023 Rohan Chakaravarty
This header file contains Floyd Warshall Algorithm:    

This is opensource project and feel free contribute*/

#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include "Graph.h"
#include <iostream>
using namespace std;

#define INF 999999

class FloydWarshall:protected Graph {
    public:
    FloydWarshall(int n):Graph(n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                Matrix[i][j]=INF;//it's getting overriden

        for(int i=0;i<n;i++)
            Matrix[i][i]=0; // Distance from a vertex to itself is always 0
    }
    void addEdge(int src, int dest, int weight) { //addEdge Overidden
    Matrix[src][dest] = weight;
    }

    void floydWarshall() {
        for (int k = 0; k < vertices; ++k) {
            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    if (Matrix[i][k] != INF && Matrix[k][j] != INF && Matrix[i][j] > Matrix[i][k] + Matrix[k][j]) {
                        Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
                    }
                }
            }
        }

        // Print the shortest distances
        cout << "\nShortest distances between every pair of vertices\n";
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (Matrix[i][j] == INF)
                    cout << " INF ";
                else
                    cout << " "<<Matrix[i][j] <<" ";
            }
            cout << endl;
        }
    }
};

#endif