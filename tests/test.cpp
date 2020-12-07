#include "../catch/catch.hpp"
#include "../other.h"
#include "../BFS.h"
#include "../graph.h"
#include <array>
#include <vector>

#include <iostream>
#include "../Dijkstra.h"
#include "../LandmarkPath.h"


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

TEST_CASE("Dijkstra Works Properly") {

  const std::string & airportData = "Datasets/airportData.csv";
  std::vector<std::string> data = file_to_vector(airportData);
  //parse through the vector to return needed info (3 digit code, lat, long)
  array<int, 3> params{4,6,7};
  std::vector<array<string, 3>> refinedData = parseVector(data, data.size(), params);
  
  
  const std::string & airportRoutesData = "Datasets/airportRoutesData.csv";
  std::vector<std::string> routesData = file_to_vector(airportRoutesData);
  array<int, 3> paramsTwo{2,4,7};
  std::vector<array<string, 3>> routes = parseVector(routesData, routesData.size(), paramsTwo);

  Graph g(true, true);
  int i = 0;

  std::vector<Vertex> addedVertexes;
  Vertex v1Actual = "";
  for (array<string, 3> route : routes) {
    Vertex v1 = route[0];
    Vertex v2 = route[1];
    if (g.vertexExists(v1) == false) {
      g.insertVertex(v1);
      addedVertexes.push_back(v1);
    }
    if (g.vertexExists(v2) == false) {
      g.insertVertex(v2);
      addedVertexes.push_back(v2);
    }
    g.insertEdge(v1, v2);
    g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData));
    
    i++;
    
    v1Actual = v1;
    
    if (i == 20) {
      break;
    }
  }
  Dijkstra d(g, "KZN", "OVB");

  double actual = d.travelDistance;
  double expected =  2108.0;

  REQUIRE(actual == expected);
}

TEST_CASE("Landmarkpath Works Properly") {
  //Relies on Dijkstra
  const std::string & airportData = "Datasets/airportData.csv";
  std::vector<std::string> data = file_to_vector(airportData);
  //parse through the vector to return needed info (3 digit code, lat, long)
  array<int, 3> params{4,6,7};
  std::vector<array<string, 3>> refinedData = parseVector(data, data.size(), params);
  
  
  const std::string & airportRoutesData = "Datasets/airportRoutesData.csv";
  std::vector<std::string> routesData = file_to_vector(airportRoutesData);
  array<int, 3> paramsTwo{2,4,7};
  std::vector<array<string, 3>> routes = parseVector(routesData, routesData.size(), paramsTwo);

  Graph g(true, true);
  int i = 0;

  std::vector<Vertex> addedVertexes;
  Vertex v1Actual = "";
  for (array<string, 3> route : routes) {
    Vertex v1 = route[0];
    Vertex v2 = route[1];
    if (g.vertexExists(v1) == false) {
      g.insertVertex(v1);
      addedVertexes.push_back(v1);
    }
    if (g.vertexExists(v2) == false) {
      g.insertVertex(v2);
      addedVertexes.push_back(v2);
    }
    g.insertEdge(v1, v2);
    g.setEdgeWeight(v1, v2, findDistance(v1, v2, refinedData));
    
    i++;
    
    v1Actual = v1;
    
    if (i == 20) {
      break;
    }
  }

  LandmarkPath l(g, "KZN", "OVB", "CEK");
  double actual = l.totalDistance;
  double expected =  2108.0;
  REQUIRE(actual == expected);
}

TEST_CASE("BFS Works Properly") {
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

  vector<Vertex> expected = {zero,one,three,five,six,two,four};
  REQUIRE(myBFS.bfsNodes == expected);

}


