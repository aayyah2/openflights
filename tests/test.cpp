#include "../catch/catch.hpp"
#include "../other.h"
#include "../BFS.h"
#include "../graph.h"
#include <array>
#include <vector>

#include <iostream>


TEST_CASE("Routes data parsed correctly") {
  
  const std::string & airportRoutesData = "Datasets/airportRoutesData.csv";
  std::vector<std::string> routesData = file_to_vector(airportRoutesData);
  array<int, 3> paramsTwo{2,4,7};
  std::vector<array<string, 3>> routes = parseVector(routesData, routesData.size(), paramsTwo);

  array<string, 3> actualRoute = routes[0];
  array<string, 3> expectedRoute = {"AER", "KZN", "0"};

  REQUIRE(actualRoute == expectedRoute);

}
TEST_CASE("Airports data lat/long parsed correctly") {
  
  const std::string & airportData = "Datasets/airportData.csv";
  std::vector<std::string> data = file_to_vector(airportData);
  //parse through the vector to return needed info (3 digit code, lat, long)
  array<int, 3> params{4,6,7};
  std::vector<array<string, 3>> refinedData = parseVector(data, data.size(), params);
  array<string, 3> actualRoute = refinedData[0];


  bool test1 = (actualRoute[1] == "-6.081689834590001");
  bool test2 = (actualRoute[2] == "145.391998291");
  bool passfail = test1 && test2;
  REQUIRE(passfail);

}

TEST_CASE("Vertex Inserted Correctly") {
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
  Vertex v1Actual = "";
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
    
    v1Actual = v1;
    break;
  }

  Vertex v1Expected = "AER";

  REQUIRE(v1Actual == v1Expected);

}

TEST_CASE("Edges Inserted Correctly and Weighted") {
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
  int v1v2EdgeActualWeight = 0;

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
    
    v1v2EdgeActualWeight = g.getEdgeWeight(v1, v2);
    break;
  }

  int v1v2EdgeExpectedWeight = 1506;

  REQUIRE(v1v2EdgeActualWeight == v1v2EdgeExpectedWeight);
}

