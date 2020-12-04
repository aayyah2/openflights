#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph g, Vertex origin, Vertex destination) {
    startingPoint = origin;
    endingPoint = destination;
    myJourney = {"CEK", "ORD", "LAX", "KZN"};
    //q holds all the vertices of g
    q = g.getVertices();
    distances[origin] = 0;                    
       for (Vertex v: q) {
           if (v != origin) {
               distances[v]=INFINITY;
           } 
        }   
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
                  distances[u] = temp;
                 
              }
          }
        }
        travelDistance = distances[destination];
        cout << distances[destination] << endl;
        
}

void Dijkstra::printItinerary() {
    cout << "Starting airport is: " << startingPoint << endl;
    cout << "Ending airport is: " << endingPoint << endl;
    cout << "This is how you get from " << startingPoint << " to " << endingPoint << ":" << endl;
    for (Vertex airport : myJourney) {
        cout << "Travel to " << airport << endl;
    }
    cout << "Arrived at Destination. Total travelled miles are: " << travelDistance << endl;

}