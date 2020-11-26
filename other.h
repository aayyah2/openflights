#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>

//file to string as given in ppt
std::string file_to_string(const std::string & filename);
//file to vector (rewrote given function)
std::vector<std::string> file_to_vector(const std::string & filename);

//creates and returns vector with needed values only (3 digit code, lat, long)
std::vector<std::string> parseVector(std::vector<std::string> vectorIn, size_t size);
