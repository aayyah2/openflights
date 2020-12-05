#include "Dijkstra.h"

class LandmarkPath {
    public:
        LandmarkPath(Graph g, Vertex origin, Vertex destination, Vertex layover);
        std::vector<Vertex> layoverPath;
        void printLayoverItinerary();
        Vertex pointOne;
        Vertex pointTwo;
        Vertex pointThree;
        double totalDistance;
};