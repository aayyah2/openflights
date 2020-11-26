#include "BFS.h"
#include "other.h"
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

/**
  for (int i = 0; i < 10; i++) {
    //array<string, 3> temp{refinedData[i]};
    cout<<refinedData[i][1]<<endl;
  }
  **/
  
  string departure = "";
  cout<< "Enter Departure Airport Code With Quotations: ";
  cin>> departure;
  
  cout << airportFound(departure, refinedData) <<endl;
  


/**
  string arrival = "";
  cout<< "Enter Arrival Airport Code: ";
  cin>> arrival;

  cout<<"Calculating path from " << departure<< " to " << arrival<< endl;
**/
  
}
