#include "BFS.h"
#include "other.h"
#include "graph.h"
#include "edge.h"
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
  std::vector<array<string, 3>> refinedData = parseVector(data, data.size());

  array<string, 3> point1 = refinedData[0];
  array<string, 3> point2 = refinedData[1];
  
  //populate graph
  Graph g(true);
  Vertex v1 = point1[0];
  Vertex v2 = point2[0];
  g.insertVertex(v1);
  g.insertVertex(v2);


  g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData));
  g.print();
  

  for (int i = 0; i < 10; i++) {
    //array<string, 3> temp{refinedData[i]};
    cout<<refinedData[i][0]<<endl;
  }






  //test cases
 //cout<< orthodromicDistance(-5.826789855957031,144.29600524902344,-6.569803,146.725977) << endl;

  /**
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
