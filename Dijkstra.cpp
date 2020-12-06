#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph g, Vertex origin, Vertex destination) {
    startingPoint = origin;
    endingPoint = destination;
    //q holds all the vertices of g
    q = g.getVertices();
    
    distances[origin] = 0;                    
    for (Vertex v: q) {
        if (v != origin) {
            distances[v]=INFINITY;
            paths[v] = vector<Vertex> ();
        } 
    }   
    paths[destination] = {destination};
    while (q.empty() == false) {
        double minVal = distances[q[0]];
        Vertex v = q[0];
        for (Vertex t: q) {
            if (distances[t] < minVal) {
                v = t;
                minVal = distances[t];
            }
        }
        q.erase(find(q.begin(), q.end(), v));
        vector<Vertex> vAdjacent = g.getAdjacent(v);
        for (Vertex u : vAdjacent) {
            double temp = distances[v] + g.getEdgeWeight(v,u);
            if (temp < distances[u])  {

                vector<Vertex> a = paths[v];
                a.push_back(u);
                
                paths[u] = a;
                distances[u] = temp;
            }
        }
    }
    travelDistance = distances[destination];
    myJourney = paths[destination];

}

void Dijkstra::printItinerary() {
    cout << "Starting airport is: " << startingPoint << endl;
    cout << "Ending airport is: " << endingPoint << endl;
    if (travelDistance == 0) {
        cout << "This itinerary is not possible with current dataset" << endl;
        return;
    }
    cout << "This is how you get from " << startingPoint << " to " << endingPoint << ":" << endl;
    for (Vertex airport : myJourney) {
        cout << "Travel to " << airport << endl;
    }
    cout << "Arrived at Destination. Total travelled miles are: " << travelDistance << " Km" << endl;

}


void Dijkstra::BFSAttempt(Graph g, Vertex origin) {
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
    q.push_front(origin);
 
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
        q.pop_front();

        //for neighbor in current_node.neighbors:
        for (Vertex neighbor: currentAdjacent) {
            //if neighbor is not in visited:
            if(visited[neighbor] == false) {
                //queue.enqueue(neighbor)
                q.push_front(neighbor);
                //visited.add(neighbor)
                visited[neighbor] = true;
            }
        } 
    }

    /**
     * BFSTraversal(start_node):
        visited := a set to store references to all visited nodes

        queue := a queue to store references to nodes we should visit later
        queue.enqueue(start_node)
        visited.add(start_node)

        while queue is not empty:
            current_node := queue.dequeue()

            process current_node
            # for example, print(current_node.value)

            for neighbor in current_node.neighbors:
            if neighbor is not in visited:
                queue.enqueue(neighbor)
                visited.add(neighbor)
    **/

}