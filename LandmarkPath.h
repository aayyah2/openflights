#include "Dijkstra.h"

//function for taking Djikstra and inserting airports
class LandmarkPath {
    public:
        LandmarkPath(Graph g, Vertex origin, Vertex destination, Vertex layover); //similar to Djikstra function
        std::vector<Vertex> layoverPath; //the path that is takes to get from starting airport to ending airport
        void printLayoverItinerary();
        Vertex pointOne; //starting 
        Vertex pointTwo; //layover
        Vertex pointThree; //ending
        double totalDistance; //total distance that is calculated
};
