#include "graph.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <map>


class Dijkstra {
    public :
        //constructor for shortest path finder
        Dijkstra(Graph g, Vertex origin, Vertex destination);
        void printItinerary();

        Vertex startingPoint;
        Vertex endingPoint;

        std::vector<Vertex> q;
        std::vector<Vertex> myJourney;
        std::map<string, double> distances;
        std::map<string, vector<Vertex>> paths;
        double travelDistance;

};