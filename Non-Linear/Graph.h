/*Copyright© 2023 Rohan Chakaravarty
This header file contains Graph Traversal Techniques:
    -> Breadth First Search
    -> Depth First Search
    

This is opensource project and feel free contribute*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;
class Graph{
    bool **a;
    int vertices;
    bool *visited;
    public:
    Graph(int n)
    {
        vertices=n;
        visited = new bool[n];
        // visited={0};
        a=new bool*[n];
        for(int i=0;i<n;i++){
            a[i] = new bool[n];
            visited[i]=0;
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=0;
    }  
    void addEdge(int v,int w)
    {
        a[v][w] = 1;
    }
    void BFS(int s){
        bool visited[vertices]={0};
        int front=-1,rear=-1;
        int queue[vertices];
        visited[s]=1;
        queue[++rear]=s;//enqueue

        while(front!=rear)
        {
            s=queue[++front];//dequeue
            cout<<s<<" ";
            for(int i=0;i<vertices;i++)
            {
                if(a[s][i] && !visited[i])//if neighbour exist and not visited
                {
                    visited[i]=1;
                    queue[++rear]=i;
                }
            }
        }
    }
    void DFS(int s){
        cout<<s<<" ";
        visited[s]=1;
        for(int j=0;j<vertices;j++)
            if(a[s][j] && !visited[j])
                DFS(j);
    }
    ~Graph()
    {
        for(int i=0;i<vertices;i++)
            delete a[i];
        
        delete a;
    }
};
#endif