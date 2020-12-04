#include "BFS.h"
#include "other.h"
#include "graph.h"
#include "edge.cpp"
#include "random.h"
#include "Dijkstra.h"

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <map>

int main() {
  
  //code for importing airportData (file_to_string is in other.cpp)
  
  
  const std::string & airportData = "Datasets/airportData.csv";
  std::vector<std::string> data = file_to_vector(airportData);
  //parse through the vector to return needed info (3 digit code, lat, long)
  array<int, 3> params{4,6,7};
  std::vector<array<string, 3>> refinedData = parseVector(data, data.size(), params);
  
  
  const std::string & airportRoutesData = "Datasets/airportRoutesData.csv";
  std::vector<std::string> routesData = file_to_vector(airportRoutesData);
  array<int, 3> paramsTwo{2,4,7};
  std::vector<array<string, 3>> routes = parseVector(routesData, routesData.size(), paramsTwo);
  
  array<string, 3> routeOne = routes[0];
  //cout << routeOne[0] << routeOne[1] << routeOne[2] << endl;
  Graph g(true, true);
  
  int i = 0;
  
  std::vector<Vertex> addedVertexes;
  
  for (array<string, 3> route : routes) {
    Vertex v1 = route[0];
    Vertex v2 = route[1];
    if (g.vertexExists(v1) == false) {
      g.insertVertex(v1);
    }
    if (g.vertexExists(v2) == false) {
      g.insertVertex(v2);
    }
    g.insertEdge(v1, v2);
    if (i == 0) {
      g.setEdgeLabel(v1,v2, "LOSE");
    }
    if (i == 1) {
      g.setEdgeLabel(v1,v2, "WIN");
    }
    g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData));
    if (i == 30) {
      break;
    }
    i++;
  }
  
  g.initSnapshot("Out");
  g.snapshot();
  
  
  Dijkstra shortestPath(g, "CEK", "KZN");
 
  /**
  for (auto pair : shortestPath.distances) {
    
    cout << pair.first<< ":" << pair.second << endl;
    
    
  }
  **/
  
  
  //shortestPath.printItinerary();
  
  
  /**
   for (int i = 0; i < 10; i++) {
   //array<string, 3> temp{refinedData[i]};
   cout<<refinedData[i][0]<<endl;
   }
   
   string departure = "";
   cout<< "Enter Departure Airport Code With Quotations: ";
   cin>> departure;
   
   cout << airportFound(departure, refinedData) <<endl;
   string arrival = "";
   cout<< "Enter Arrival Airport Code: ";
   cin>> arrival;
   cout<<"Calculating path from " << departure<< " to " << arrival<< endl;
   //try catch to ensure valid airports
   if (airportFound(departure, refinedData)&& airportFound(arrival,refinedData)) {
   //check for accuracy
   cout << findDistance(arrival, departure, refinedData) << endl;
   }
   
   **/
  
}
