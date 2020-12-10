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
/**
* This is our final project for CS 225. We utilized the OpenFlights Dataset (https://openflights.org/data.html), and specifically used the routes and airport datasets for our project. 
* Our main goal was to find a way to calculate the shortest path from a given Airport to any other Airport. 
*
* In order to do this, we implemented Dijkstra's Algorithm (https://brilliant.org/wiki/dijkstras-short-path-finder/) in Dijkstra.h and Dijkstra.cpp. 
* We also implemented a Landmark Path Algorithm using Dijkstra's Algorithm in LandmarkPath.h and LandmarkPath.cpp. 
* We have written a BFS traversal of our weighted and directed graph (g) to visit all the nodes in BFS order. 
* 
* We take in user input via std::cin >> and output a printed itinerary which details the exact path to take to the desination, along with total travelled miles.
**/

int main() {
  
  //code for importing airportData (file_to_string is in other.cpp)
  const std::string & airportData = "Datasets/airportData.csv";
  std::vector<std::string> data = file_to_vector(airportData);
  
  //parse through the vector to return needed info (3 digit code, lat, long)
  array<int, 3> params{4,6,7};
  std::vector<array<string, 3>> refinedData = parseVector(data, data.size(), params);
  
  //importing routesData
  const std::string & airportRoutesData = "Datasets/airportRoutesData.csv";
  std::vector<std::string> routesData = file_to_vector(airportRoutesData);
  
  //parse through the vector to return needed info (starting airport code, destination airport code, num. of stops)
  array<int, 3> paramsTwo{2,4,7};
  std::vector<array<string, 3>> routes = parseVector(routesData, routesData.size(), paramsTwo);
  
  //accessing the first route
  array<string, 3> routeOne = routes[0];
  
  //specifying graph g as weighted and directed
  Graph g(true, true);
  
  //initializing i to break the graph for testing
  int i = 0;
  
  //adding vertexes within the graph
  std::vector<Vertex> addedVertexes;
  
  //traversing through each route 
  for (array<string, 3> route : routes) {
    Vertex v1 = route[0]; //starting aiport stored in V1
    Vertex v2 = route[1]; //destination airport stored in V2
    if (g.vertexExists(v1) == false) { //making sure that starting airport exists  
      g.insertVertex(v1);
    }
    if (g.vertexExists(v2) == false) { //making sure destination airport exists
      g.insertVertex(v2);
    }
    g.insertEdge(v1, v2); //inserting the edge between each airport (vertices are airport codes)
    g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData)); //setting the edge weight using the calculation of the Orthodromic distance between the two airports 
    
    i++;
   
  }

  string departure = "";
  cout<< "Enter Departure Airport Code: ";
  cin>> departure;
  
  
  string arrival = "";
  cout<< "Enter Arrival Airport Code: ";
  cin>> arrival;

  
  string landmark = "";
  cout<< "If you want to integrate a layover into your itinerary, enter 1; else enter 0: ";
  cin>> landmark;

  string layover = "";
  
  if (landmark == "1") {
    cout<< "Please enter the code of your layover: ";
    cin>> layover;
    LandmarkPath shortestLayoverPath(g, departure, arrival, layover); //finding the shortest layover path
    shortestLayoverPath.printLayoverItinerary(); //printing the itinerary using the dataset with layovers

  } else if (landmark == "0") {
    Dijkstra shortestPath(g, departure, arrival);
    shortestPath.printItinerary();
  }

  

  g.initSnapshot("Out");
  g.snapshot();

  
  // Dijkstra shortestPath(g, "ORD", "BOM");

  // shortestPath.printItinerary();

  // for (size_t i = 0; i < shortestPath.myJourney.size() - 1; i++) {
  //   g.setEdgeLabel(shortestPath.myJourney[i],shortestPath.myJourney[i+1], "LOSE");
  // }
  
  // g.initSnapshot("Out");
  // g.snapshot();


  
  /**
     if (airportFound(departure, refinedData)&& airportFound(arrival,refinedData)) {

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
