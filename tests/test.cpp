#include "catch/catch.hpp"

#include "other.h"
#include "BFS.h"

#include <iostream>


TEST_CASE("Main properly accesses 3 digit code") {
  const std::string & airportData = "airportData.csv";
  std::vector<std::string> data = file_to_vector(airportData);
  std::vector<array<string, 3>> refinedData = parseVector(data, data.size());

  bool actual = airportFound("GKA", refinedData);
  REQUIRE(actual);
}