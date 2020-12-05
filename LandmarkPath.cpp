#include "LandmarkPath.h"


LandmarkPath::LandmarkPath(Graph g, Vertex origin, Vertex destination, Vertex layover) {
    pointOne = origin;
    pointTwo = layover;
    pointThree = destination;
    Dijkstra partOne(g, origin, layover); //will have the second airport inclusive of the layover
    Dijkstra partTwo(g,layover, destination); //will have the second airport inclusive of the destination
    layoverPath.insert(layoverPath.end(), partOne.myJourney.begin(), partOne.myJourney.end());
    layoverPath.insert(layoverPath.end(), partTwo.myJourney.begin(), partTwo.myJourney.end());
    totalDistance = partOne.travelDistance + partTwo.travelDistance;
}

void LandmarkPath::printLayoverItinerary() {
    cout << "Starting airport is: " << pointOne << endl;
    cout << "Layover airport is: " << pointTwo << endl;
    cout << "Ending airport is: " << pointThree << endl;
    if (totalDistance == 0) {
        cout << "This itinerary is not possible with current dataset" << endl;
        return;
    }
    cout << "This is how you get from " << pointOne << " to " << pointThree << " via " << pointTwo << ":" << endl;
    for (Vertex airport : layoverPath) {
        cout << "Travel to " << airport << endl;
    }
    cout << "Arrived at Destination. Total travelled kilometers are: " << totalDistance << " Km" << endl;
}