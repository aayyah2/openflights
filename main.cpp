#include "BFS.h"
#include "other.h"
#include "graph.h"
#include "edge.cpp"
#include "random.h"

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <string>

int main() {
  //code for importing airportData (file_to_string is in other.cpp)
  const std::string & airportData = "airportData.csv";
  std::vector<std::string> data = file_to_vector(airportData);
  //parse through the vector to return needed info (3 digit code, lat, long)
  array<int, 3> params{4,6,7};
  std::vector<array<string, 3>> refinedData = parseVector(data, data.size(), params);


  const std::string & airportRoutesData = "airportRoutesData.csv";
  std::vector<std::string> routesData = file_to_vector(airportRoutesData);
  array<int, 3> paramsTwo{2,4,7};
  std::vector<array<string, 3>> routes = parseVector(routesData, routesData.size(), paramsTwo);

  array<string, 3> routeOne = routes[0];

  Graph g(true);


  for (array<string, 3> route : routes) {
    Vertex v1 = route[0];
    Vertex v2 = route[1];
    g.insertVertex(v1);
    g.insertVertex(v2);
    g.insertEdge(v1, v2);
    g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData));
  }
  g.savePNG("out.png");
  /**
  
  for (int i = 0; i < 10; i++) {
    //array<string, 3> temp{refinedData[i]};
    cout<<refinedData[i][0]<< refinedData[i][1] << endl;
  }
  g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData));
  cout << orthodromicDistance(55.606201171875, 49.278701782227, 43.449902, 39.9566) << endl;
 
  //g.print();

  
  array<string, 3> point1 = refinedData[0];
  array<string, 3> point2 = refinedData[1];
  
  //populate graph
  Graph g(true);
  Vertex v1 = point1[0];
  Vertex v2 = point2[0];
  g.insertVertex(v1);
  g.insertVertex(v2);

  
  
  g.insertEdge(v1, v2);

  g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData));

  cout << g.getEdgeWeight(v1, v2);
  //g.print();
  
  
  for (int i = 0; i < 10; i++) {
    //array<string, 3> temp{refinedData[i]};
    cout<<refinedData[i][0]<<endl;
  }
  



  //test cases
 //cout<< orthodromicDistance(-5.826789855957031,144.29600524902344,-6.569803,146.725977) << endl;

  
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
