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

BFS::BFS(Graph g, Vertex origin) //g is the graph, origin is the source node (starting airport)
{  
    vector<Vertex> bfsNodes; //vector of vertices named bfsNodes
   
    //get vertices from our particular dataset
    vector<Vertex> vertices = g.getVertices();
   
    //visited := a set to store references to all visited nodes
    std::map<Vertex, bool> visited;

    //setting all vertices as not visited 
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
        bfsNodes.push_back(current); //enqueueing the current node from the vertices given
        
        vector<Vertex> currentAdjacent = g.getAdjacent(current); //finding the adjacent nodes
        
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
    //print the vertex node and moving to next line
    for (Vertex node: bfsNodes) {
        cout << node << endl;
    }
}
