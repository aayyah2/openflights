#include "LandmarkPath.h"

LandmarkPath::LandmarkPath(Graph g, Vertex origin, Vertex destination, Vertex layover) {
    //initializing all of the paths (origin, layover and destination)
    pointOne = origin;
    pointTwo = layover;
    pointThree = destination;
    Dijkstra partOne(g, origin, layover); //will have the second airport inclusive of the layover
    Dijkstra partTwo(g,layover, destination); //will have the second airport inclusive of the destination
    //inserting the path and calculating the total distance 
    layoverPath.insert(layoverPath.end(), partOne.myJourney.begin(), partOne.myJourney.end());
    layoverPath.insert(layoverPath.end(), partTwo.myJourney.begin(), partTwo.myJourney.end());
    totalDistance = partOne.travelDistance + partTwo.travelDistance;
}

//printing out the starting aiport, layover aiport and ending airports
void LandmarkPath::printLayoverItinerary() {
    cout << "Starting airport is: " << pointOne << endl;
    cout << "Layover airport is: " << pointTwo << endl;
    cout << "Ending airport is: " << pointThree << endl;
    //making sure there is an itinerary that can be given and if not, print that itinerary cannot be given with the dataset
    if (totalDistance == 0) {
        cout << "This itinerary is not possible with current dataset" << endl;
        return;
    }
    //printing out the itinerary with different points from starting to ending aiports
    cout << "This is how you get from " << pointOne << " to " << pointThree << " via " << pointTwo << ":" << endl;
    for (Vertex airport : layoverPath) {
        cout << "Travel to " << airport << endl;
    }
    //printing out the total distance travelled
    cout << "Arrived at Destination. Total travelled kilometers are: " << totalDistance << " Km" << endl;
}
