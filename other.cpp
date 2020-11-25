#include "other.h"
#include <iostream>
#include <cstdlib>
using namespace std;
#include <sstream>
#include <fstream>

//file to string as given in ppt
std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);

	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}
    cout<<"file accessed";
	return strStream.str();
}
