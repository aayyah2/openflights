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
    BFS(Graph g, Vertex origin); //print the BFS traversal for graph given source node
    Vertex startingPoint; //starting airport
    vector<Vertex> q; //creating a queue for BFS
    vector<Vertex> adj; //neighbor vertices of dequeued vertex
    map<vector<Vertex>, bool> visited; //mark the nodes as visited or not
  
//private:
 
};

