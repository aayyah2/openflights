#include "BFS.h"
#include "other.h"
#include "graph.h"
#include "edge.cpp"
#include "random.h"
#include "Dijkstra.h"
#include "LandmarkPath.h"

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
  Graph test(false, false);
  Vertex zero = "0";
  Vertex one = "1";
  Vertex two = "2";
  Vertex three = "3";
  Vertex four = "4";
  Vertex five = "5";
  Vertex six = "6";

  test.insertVertex(zero);
  test.insertVertex(one);
  test.insertVertex(two);
  test.insertVertex(three);
  test.insertVertex(four);
  test.insertVertex(five);

  test.insertEdge(zero, one);
  test.insertEdge(zero, three);
  test.insertEdge(three, one);
  test.insertEdge(one, two);
  test.insertEdge(two, three);
  test.insertEdge(two, four);
  test.insertEdge(two, five);
  test.insertEdge(one, five);
  test.insertEdge(three, four);
  test.insertEdge(one, six);
  test.insertEdge(four, six);
  

  BFS myBFS(test, zero);


  //code for importing airportData (file_to_string is in other.cpp)
  /**
  
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
    g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData));
    
    i++;
    break;
   
  }

  LandmarkPath shortestLayoverPath(g, "CMI", "SBU", "KEF");
  shortestLayoverPath.printLayoverItinerary();
**/

  // Dijkstra shortestPath(g, "ORD", "BOM");

  // shortestPath.printItinerary();

  // for (size_t i = 0; i < shortestPath.myJourney.size() - 1; i++) {
  //   g.setEdgeLabel(shortestPath.myJourney[i],shortestPath.myJourney[i+1], "LOSE");
  // }
  
  // g.initSnapshot("Out");
  // g.snapshot();


  
  /**
   for (int i = 0; i < 10; i++) {
   //array<string, 3> temp{refinedData[i]};
   cout<<refinedData[i][0]<<endl;
   }
   
   string departure = "";
   cout<< "Enter Departure Airport Code: ";
   cin>> departure;
   
   cout << airportFound(departure, refinedData) <<endl;
   string arrival = "";
   cout<< "Enter Arrival Airport Code: ";
   cin>> arrival;
   
   //try catch to ensure valid airports
   if (airportFound(departure, refinedData)&& airportFound(arrival,refinedData)) {
   //check for accuracy
   cout << findDistance(arrival, departure, refinedData) << endl;
   }
   
   **/
  
}
