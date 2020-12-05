#include <iterator>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "BFS.h"
using namespace std;

BFS::BFS(Graph g, Vertex s) //g is the graph, s is the source node
{  
    
    startingPoint = s;
    q = g.getVertices();

    bool *visited = new bool[q.size()];
    for(int i = 0; i < q.size(); i++)
    {
        visited[i] = false;
    }

    queue<Vertex> Q; //let Q be queue
    list<Vertex>::iterator w;
    Vertex v;
    adj = new list<Vertex>[q.size()];

    Q.push(s); //enqueue s, inserting s in queue until all its neighbor vertices are marked
    visited[s] = true; //mark s as visited

    while(!Q.empty()) //while Q is not empty
    {
        v = Q.front(); //dequeue, removing that vertex from queue, whose neighbor will be visited now
        cout << v << " ";
        Q.pop();

        // processing all neighbors of v
        for(w = adj[v].begin; w!=adj[v].end(); ++w) // for all neighbors w of v in graph G
        {
            if(!visited[*w]) //if w is not visited
            {
                Q.push(*w); //enqueue w, stores w in Q to further visit its neighbor
                visited[*w] = true; //mark w as visited
            }
        }
    }

}
