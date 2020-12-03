#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph g, Vertex origin) {

    q = g.getVertices();
    distances[origin] = 0;                    
       for (Vertex v: q) {
           if (v != origin) {
               distances[v]=INFINITY;
           } 
        } 
        //cout << distances[origin] << endl;      
             
        while (q.empty() == false) {
           
          double minVal = distances[q[0]];
          Vertex v = q[0];
          for (Vertex t: q) {
            
              if (distances[t] < minVal) {
                  v = t;
                  minVal = distances[t];
              }
          }
          //cout << distances[origin] << endl;    

          q.erase(find(q.begin(), q.end(), v));
          vector<Vertex> vAdjacent = g.getAdjacent(v);
          for (Vertex u : vAdjacent) {
              
              double temp = distances[v] + g.getEdgeWeight(v,u);
              
              if (temp < distances[u])  {
                  
                  distances[u] = temp;
              }
          }
        }  
         
}