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
        Dijkstra(Graph g, Vertex origin);
        std::vector<Vertex> q;
        std::map<string, double> distances;

};