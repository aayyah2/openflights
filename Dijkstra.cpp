#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph g, Vertex origin, Vertex destination) {
    startingPoint = origin; //initializing starting airport
    endingPoint = destination; //initializing ending airport
    
    //q holds all the vertices of g
    q = g.getVertices();
    
    distances[origin] = 0; //distance from origin to origin is set to zero                  
    for (Vertex v: q) { //initialize all distances as infinite
        if (v != origin) {
            distances[v]=INFINITY; //unknown distance function from origin to each node set to infinity
            paths[v] = vector<Vertex> (); //taking in an airport and returning a vertex
        } 
    }   
    paths[destination] = {destination}; //taking in the destination and mapping it to endingPoint
    while (q.empty() == false) { //setting up while loop for queue, while there are airports/vertices
        double minVal = distances[q[0]]; //minimum value is equal to distance from first vertex
        Vertex v = q[0]; //in the first runthrough, this vertex is the source node
       
        //for all of the airports, if distances is less than the minimum value, have to set the min val to distances
        for (Vertex t: q) { //vertex in q with minimum distance [v]
            if (distances[t] < minVal) {
                v = t;
                minVal = distances[t];
            }
        }
        
        //removing v from q and getting adjacent vertices
        q.erase(find(q.begin(), q.end(), v)); 
        vector<Vertex> vAdjacent = g.getAdjacent(v); 
        
        //for each neighbor u of v where neighbor u has not yet been removed from queue 
        for (Vertex u : vAdjacent) {
            double temp = distances[v] + g.getEdgeWeight(v,u); //temporary value for distance [v] + length from v to u
            if (temp < distances[u])  { //a shorter path to u has been found! 
                
                //looking through path with vertices and enqueuing u into a 
                vector<Vertex> a = paths[v]; 
                a.push_back(u);
                
                paths[u] = a; //a is paths[u]
                distances[u] = temp; //update the distance of u 
            }
        }
    }
    travelDistance = distances[destination]; //represents the distance travelled
    myJourney = paths[destination]; //represents the journey with all of the paths needed to get to destination

}

//function to print out the itenerary included total miles to destination and layover paths from start to end
void Dijkstra::printItinerary() {
    cout << "Starting airport is: " << startingPoint << endl;
    cout << "Ending airport is: " << endingPoint << endl;
    if (travelDistance == 0) { //if the distance travelled is zero, there is no itinerary for the given airports 
        cout << "This itinerary is not possible with current dataset" << endl;
        return;
    }
    cout << "This is how you get from " << startingPoint << " to " << endingPoint << ":" << endl;
    for (Vertex airport : myJourney) { //printing out the journey from myJourney with the paths
        cout << "Travel to " << airport << endl;
    }
    cout << "Arrived at Destination. Total travelled miles are: " << travelDistance << " Km" << endl; //total miles printed

}