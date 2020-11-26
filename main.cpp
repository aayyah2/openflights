#include "BFS.h"
#include "other.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
#include <sstream>
#include <fstream>

int main() {
  //code for importing airportData (file_to_string is in other.cpp)
  const std::string & airportData = "airportData.csv";
  std::vector<std::string> data = file_to_vector(airportData);
  std::vector<std::string> refinedData = parseVector(data, data.size());
  
  for (int i = 0; i < 10; i++) {
    cout<<refinedData[i]<<endl;
  }
}
