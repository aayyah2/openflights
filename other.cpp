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
	std::vector<array<string, 3>> parsedVector; //creating parsed vector an array of three strings 
	std::string temp;
	for (size_t i = 0; i < size; i++) {
    	temp = vectorIn[i]; //taking in three digit airport code
		
		vector<string> v;
		stringstream ss(temp); //storing temp as string
		//taking into consideration the quotation marks 
		while (ss.good()) { //checking whether the state of string is good
			string substr;
			getline(ss, substr, ','); //getting string ss and substr and discarding the comma
			v.push_back(substr); //adding substr to v
		}
		temp = v[4] + "," + v[6] + "," + v[7]; //taking in needed characteristics from dataset
		
		array<string, 3> a{v[arr[0]],v[arr[1]],v[arr[2]]}; //taking in needed characteristics from dataset
		
		parsedVector.push_back(a); //pushing a
	}
	return parsedVector; //returning the parsed vector
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
	
	//formula for orthodromic distance
	long double ans = pow(sin(dlat / 2), 2) +  cos(lat1) * cos(lat2) *  pow(sin(dlong / 2), 2); 
	ans = 2 * asin(sqrt(ans)); 

	long double R = 6371; 
	
	ans = ans * R; 

	return ans; //returning the calculated answer 
	
}

//converting degrees to radians
long double toRadians(const long double degree) 
{ 
    long double one_deg = (M_PI) / 180; 
    return (one_deg * degree); 
} 

//making sure there is an airport in the dataset given what the user input is
bool airportFound(string userInput, std::vector<array<string, 3>> dataset) {

  for (array<string, 3> airport:dataset) { //for each airport in the dataset
    if (airport[0] == userInput) {
		cout << "airport found"<<endl; //print airport found if an airport is found
      return true;
    }
  }
  cout << "airport not found"<<endl; //if there is no airport found in the dataset, print that 
  return false;
}

//calculating the distance taking in the airport codes
//traversing through dataset to find the latitudes and longitudes for the formula
double findDistance(string code1, string code2, std::vector<array<string, 3>> dataset) {
	code1 = '"' + code1 + '"' ;
	code2 = '"' + code2 + '"' ;
	
	double lat1;
	double long1;
	double lat2;
	double long2;

	//initializing lat1, lat2, long1, long2 to input into the orthodromic distance formula
	for (array<string, 3> airport:dataset) {
		if (airport[0] == code1) { //putting in lat1 and long1 given airport1 data
			lat1 = stod(airport[1]);
			
			long1 = stod(airport[2]);
		}
		if (airport[0] == code2) { //putting lat2 and long2 given airport2 data
			lat2 = stod(airport[1]);
			long2 = stod(airport[2]);
		}
  }
  return (orthodromicDistance(lat1, long1, lat2, long2)); //returning the orthodromic distance
}

