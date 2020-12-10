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
#include <iterator>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <deque>
using namespace std;
 
class BFS {


public:
    BFS(Graph g, Vertex origin);
    Vertex startingPoint;
    vector<Vertex> q;
    vector<Vertex> adj;
    map<vector<Vertex>, bool> visited;
    vector<Vertex> bfsNodes;
  
//private:
 
};

