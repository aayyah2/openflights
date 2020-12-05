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
    cout << "Arrived at Destination. Total travelled kilometers are: " << travelDistance << " Km" << endl;

}


