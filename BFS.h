/**
 * @file BFS.h
 */

#pragma once

#include <iterator>
#include <iostream>
#include <cmath>
#include <list>
#include <queue>
#include "graph.h"
using namespace std;
 
class BFS {


public:
    BFS(Graph g, Vertex s);
    Vertex startingPoint;
    vector<Vertex> q;
    list<Vertex> *adj;


  
//private:
 
};

