#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>

using namespace std;
//file to string as given in ppt
std::string file_to_string(const std::string & filename);
//file to vector (rewrote given function)
std::vector<std::string> file_to_vector(const std::string & filename);

//creates and returns vector with needed values only (3 digit code, lat, long)
std::vector<array<string, 3>> parseVector(std::vector<std::string> vectorIn, size_t size);

//calculates orthodromic distance between 2 points
long double orthodromicDistance(double lat1, double long1, double lat2, double long2);

bool airportFound(string userInput, std::vector<array<string, 3>> dataset);

long double toRadians(const long double degree);

//check accuracy
long double findDistance(string code1, string code2, std::vector<array<string, 3>> dataset);