# aditiaa2-aayyah2-jchint2-cgurna2
Final Project: OpenFlights Shortest Path and Landmark Path


**Description:**
Our final project for CS 225 utilizes an airports dataset (https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat) to calculate the most efficient path based on different user preferences. 

1) Most efficient path (with geographic distance travelled as the metric for efficiency) - Dijsktra's Algorithm
2) Landmark path (selecting most efficient path that passes through the given landmarks)
3) BFS Traversal of Graph Nodes

We take in the user's input (starting airport, ending airport, and any landmarks) using std::cin
Ex: To enter ORD, type ORD (no quotes) when prompted. 

The inclusion of a landmark/layover in the itinerary is dictated by the user's input. Enter 0 when prompted for a path with no landmark/layover, and 1 for a path with a layover. You will then be prompted to enter which Landmark Airport you would like to include in the itinerary. 

The complete path is printed out when the calculations are complete. This is formatted with the starting and ending airport printed, along with a step-by-step travel plan and total Km travelled. 


**Example:**

*User Input*

- Enter Departure Airport Code: CMI

- Enter Arrival Airport Code: FRA

- If you want to integrate a layover into your itinerary, enter 1; else enter 0: 1

- Please enter the code of your layover: DXB


*Terminal Output*

- Starting airport is: CMI

- Layover airport is: DXB

- Ending airport is: FRA

- *This is how you get from CMI to FRA via DXB:*
  * Travel to ORD

  * Travel to ARN
  
  * Travel to DXB
  
  * Travel to VIE
  
  * Travel to NUE
  
  * Travel to FRA
  
- Arrived at Destination. Total travelled kilometers are: 16698 Km


**To Build:**
This project is written in C++.
In order to "make", open the main directory on your terminal and run:

1) make
2) ./final

You will then be prompted to enter your inputs and landmarks. 

If you're curious about our testing process and want to see our test cases in action, run:

1) make test
2) ./test


**Directory Guide:**
1) The Datasets folder contains the airports and routes CSVs
2) The images folder contains the graphical output (PNG) of our complete dataset. This is the graph we traversed for our algorithms
3) The tests folder contains our test.cpp (test cases)
4) The catch folder contains code from the CS 225 test suite (used to help us write test cases)


**Usage:**
We think this is a cool representation of what can be done with graph data structures and traversals. Though this is historical data (and therefore not up to date), it's useful to illustrate the complexities of air travel and how algorithms like Dijkstra can be used to quickly and efficiently calculate paths. 


**Authors:**
Aditi Adya (aditiaa2)
Aparna Ayyah (aayyah2)
Chaahat Gurnani (cgurna2)
Joshmita Chintala (jchint2)

**Credits:**
Thank you to CS 225 for the Graph.h, Graph.cpp, Edge.cpp, Random.h, Random.cpp, catch.hpp, and catchmain.cpp files. 
- Our BFS.h and BFS.cpp code is based on the Pseudocode provided here (https://courses.engr.illinois.edu/cs225/fa2020/resources/bfs-dfs/)
- Our Dijkstra's Algorithm (Dijkstra.h and Dijkstra.cpp) is based on the explanations provided on this page (https://brilliant.org/wiki/dijkstras-short-path-finder/)

Special thanks to all the TAs and CAs that helped us troubleshoot our problems! We really enjoyed this experience. 

**We hope you enjoy our project!**
