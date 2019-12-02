//Tobby Lie 103385744
//CSCI 2421
//Homework 7
//October 7, 2017
//threeTellerSimulation function specifications

#ifndef threeTellerSimulation_hpp
#define threeTellerSimulation_hpp
#include <queue>

using namespace std;

struct threeTellerEvent{
    int time = 0;
    int transactionLength = 0;
    bool operator<(const threeTellerEvent& rhs) const{
        return (time > rhs.time);
    } // end operator<
}; // end threeTellerEvent

struct threeTellerCustomer{
    threeTellerEvent event; // customer "has a" event
}; // end threeTellerCustomer

struct Teller{ // teller holds info about if it is available and holds a customer queue
    bool available;
    threeTellerCustomer currentCustomer;
    queue<threeTellerCustomer> tellerLine;
}; // end Teller

void threeTellerSimulation(); // threeTellerSimulation
int determineShortestLine(Teller t[]); // will determine the shortest line available for tellers, returns index
// process an arrival event
void processThreeTellerArrival(threeTellerEvent arrivalEvent, priority_queue<threeTellerEvent> &eventPriorityQueue, Teller t[], int &totalWaitTime, int currentTime);
// process departureEvent
void processThreeTellerDeparture(threeTellerEvent departureEvent, priority_queue<threeTellerEvent> &eventPriorityQueue, Teller t[], int &totalWaitTime, int currentTime);

#endif /* threeTellerSimulation_hpp */
