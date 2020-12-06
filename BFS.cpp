#include <iterator>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include "BFS.h"
#include <map>
using namespace std;

BFS::BFS(Graph g, Vertex origin) //g is the graph, s is the source node
{  
   vector<Vertex> bfsNodes;
    //visited := a set to store references to all visited nodes
    vector<Vertex> vertices = g.getVertices();
    std::map<Vertex, bool> visited;

    for (Vertex v : vertices) {
        visited[v] = false;
    }

    //queue := a queue to store references to nodes we should visit later
    std::deque<Vertex> q;
    
    //queue.enqueue(start_node)
    q.push_back(origin);
 
    //visited.add(start_node)
    visited[origin] = true;

    Vertex current;
    //while queue is not empty:
    while (q.size() > 0) {
        //process current_node
        current = q.front();
        bfsNodes.push_back(current); 
        
        vector<Vertex> currentAdjacent = g.getAdjacent(current);
        
        //delete current node so that we can process next nodes
        //cout << q.front() << endl;
        q.pop_front();

        //for neighbor in current_node.neighbors:
        for (Vertex neighbor: currentAdjacent) {
            
            //if neighbor is not in visited:
            if(visited[neighbor] == false) {
                
                //queue.enqueue(neighbor)
                q.push_back(neighbor);

                //visited.add(neighbor)
                visited[neighbor] = true;
           
            }
        }
    }

    for (Vertex node: bfsNodes) {
        cout << node << endl;
    }
    

}
