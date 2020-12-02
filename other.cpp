#include "other.h"
#include <iostream>
#include <cstdlib>
using namespace std;
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <string>

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
	
	//simplified vector transformation
	std::ifstream file(filename);
	std::string item;
	std::vector<std::string> out;
	while(std::getline(file, item)) {
		//1 item = 1 line in data
		out.push_back(item);
	}
	//out is vector with entire csv processed
	return out;
}

//parse through the vector to return needed info (3 digit code, lat, long)
std::vector<array<string, 3>> parseVector(std::vector<std::string> vectorIn, size_t size, array<int, 3> arr) {
	std::vector<array<string, 3>> parsedVector;
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
		
		array<string, 3> a{v[arr[0]],v[arr[1]],v[arr[2]]};
		

		parsedVector.push_back(a);
	}

	return parsedVector;

}

//calculation of distance (cost) between 2 geographic points
long double orthodromicDistance(double lat1, double long1, double lat2, double long2) {
	
	// Convert the latitudes and longitudes from degree to radians. 
	lat1 = toRadians(lat1); 
    long1 = toRadians(long1); 
    lat2 = toRadians(lat2); 
    long2 = toRadians(long2); 
	
	// Haversine Formula 
	long double dlong = long2 - long1; 
	long double dlat = lat2 - lat1; 

	long double ans = pow(sin(dlat / 2), 2) +  cos(lat1) * cos(lat2) *  pow(sin(dlong / 2), 2); 
	ans = 2 * asin(sqrt(ans)); 

	long double R = 6371; 
	
	ans = ans * R; 

	return ans; 
	
}

long double toRadians(const long double degree) 
{ 
    long double one_deg = (M_PI) / 180; 
    return (one_deg * degree); 
} 

bool airportFound(string userInput, std::vector<array<string, 3>> dataset) {

  for (array<string, 3> airport:dataset) {
    if (airport[0] == userInput) {
		cout << "airport found"<<endl;
      return true;
    }
  }
  cout << "airport not found"<<endl;
  return false;
}

double findDistance(string code1, string code2, std::vector<array<string, 3>> dataset) {
	code1 = '"' + code1 + '"' ;
	code2 = '"' + code2 + '"' ;
	
	double lat1;
	double long1;
	double lat2;
	double long2;

	for (array<string, 3> airport:dataset) {
		if (airport[0] == code1) {
			lat1 = stod(airport[1]);
			
			long1 = stod(airport[2]);
		
		}
		if (airport[0] == code2) {
			lat2 = stod(airport[1]);
			long2 = stod(airport[2]);
		}
  }
  return (orthodromicDistance(lat1, long1, lat2, long2));
}

