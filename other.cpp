#include "other.h"
#include <iostream>
#include <cstdlib>
using namespace std;
#include <sstream>
#include <fstream>
#include <vector>

//file to string as given in ppt
std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);

	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}
    
	return strStream.str();
}

//given ppt code splits by space, which is not what we want
std::vector<std::string> file_to_vector(const std::string & filename) {
	/**
	 * std::ifstream text(filename);
	std::vector<std::string> out;

	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}
	}

	return out;
	**/
	std::ifstream file(filename);
    std::string item;
	std::vector<std::string> out;

    while(std::getline(file, item)) {
        out.push_back(item);
    }
	return out;
}


std::vector<std::string> parseVector(std::vector<std::string> vectorIn, size_t size) {
	std::vector<std::string> parsedVector;
	std::string temp;
	for (size_t i = 0; i < size; i++) {
    	temp = vectorIn[i];

		vector<string> v;
		stringstream ss(temp);
	
		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			v.push_back(substr);
		}
		temp = v[4] + "," + v[6] + "," + v[7];
		parsedVector.push_back(temp);
	}

	return parsedVector;

}