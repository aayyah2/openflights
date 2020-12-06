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
#include <queue>
#include <deque>
#pragma once


class Dijkstra {
    public :
        //constructor for shortest path finder
        Dijkstra(Graph g, Vertex origin, Vertex destination); 
        void printItinerary(); //printing the itinerary
        void BFSAttempt(Graph g, Vertex origin); //BFS for Djikstra

        Vertex startingPoint; //starting point vertex
        Vertex endingPoint; //ending point vertex

        std::vector<Vertex> q; //holds all vertices or airport
        std::vector<Vertex> myJourney; //the itinerary of all paths
        std::map<string, double> distances; //distance from airport to airport
        std::map<string, vector<Vertex>> paths; //path including any layovers if needed
        double travelDistance; //total distance travelled

};
