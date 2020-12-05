/**
 * @file BFS.h
 */

#pragma once

#include <iterator>
#include <iostream>
#include <cmath>
#include <list>
#include <queue>
using namespace std;
 
class BFS {

 int V; 
 list <int> *adj; 

public:
 BFS(int V);
 void addEdge(int v, int w);
 void BFSS(int s);
 
  
//private:
 
};

