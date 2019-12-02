//Tobby Lie 103385744
//CSCI 2421
//Homework 7
//October 7, 2017
//simulation function specifications

#ifndef simulation_hpp
#define simulation_hpp
#include <queue>

using namespace std;

struct Event{ // contains event of either arrival or departure
    int time = 0; // time of event whether that be arrival or departure
    int transactionLength = 0; // transactionLength will be 0 for departure
    
    bool operator<(const Event& rhs) const{
         return (time > rhs.time);
    } // end operator<
}; // end Event
    
        /* found overloaded < on StackOverflow.
         Thought it would be helpful
         to create Event as a struct to encapsulate data
         in order to abstract what an event is
         overloading also helps simplify the sort
         
         could have subtracted time by a very large value
         to flip the way the priority queue sorts
         for example: time = 88; 
         10000 - time = 9912 and then
         10000 - 9912 = 88 to get back original value
         
         but thought this way would be simpler for the
         program specifically
         */

struct Customer{ // for use in bankLine queue
    Event event; // customer "has a" event
}; // end Customer

void simulate(); // simulation function
// processes an arrival event
void processArrival(Event arrivalEvent, priority_queue<Event> &eventPriorityQueue, queue<Customer> &bankLine, bool &tellerAvailable, int &totalWaitTime, int currentTime);
// processes departure event
void processDeparture(Event departureEvent, priority_queue<Event> &eventPriorityQueue, queue<Customer> &bankLine, bool &tellerAvailable, int &totalWaitTime, int currentTime);

#endif /* simulation_hpp */
