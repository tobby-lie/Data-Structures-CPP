//Tobby Lie 103385744
//CSCI 2421
//Homework 7
//October 7, 2017
//simulation function implementation

#include <fstream>
#include <iostream>
#include <iomanip>
#include "simulation.h"

using namespace std;

/*********************************************************************
 ** FUNCTION: simulate
 ** DESCRIPTION: runs the bank simulation which calls processArrival
 ** and processDeparture, will continue looping until the eventPriority
 ** queue is empty
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: should have input from file available
 ** POST-CONDITIONS: eventPriorityQueue should be empty and data should
 ** be processed and displayed in a program trace that tracks events executed
 ** RETURNS: nothing
 *********************************************************************/
void simulate(){
    
    queue<Customer> bankLine; // Queue of customers to represent bank line
    priority_queue<Event> eventPriorityQueue; // priority queue that holds all events: departure and arrivals
    
    bool tellerAvailable = true; // status of teller set to true since we are just starting out
    
    ifstream inFile;
    inFile.open("Input.txt"); // open input file
    if(inFile.fail()){
        cout << "unable to open file!" << endl;
    } // end if
    
    int _time, _transactionLength; // temp variables for time and transLength input
    while(!inFile.eof()){ // loops until end of file to populate eventPrioriyQueue
        Event newArrivalEvent;
        inFile >> _time;
        inFile >> _transactionLength;
        newArrivalEvent.time = _time;
        newArrivalEvent.transactionLength = _transactionLength;
        eventPriorityQueue.push(newArrivalEvent);
    } // end while
    inFile.close(); // close file
    
    int totalPeople = (int)eventPriorityQueue.size(); // total people tracked through reference var
    int totalWaitTime = 0; // total wait time tracked through reference var
    cout << "Simulation With One Teller Begins" << endl;
    cout << endl;
    while(!eventPriorityQueue.empty()){ // loops until eventPriorityQueue empty
        Event newEvent;
        newEvent = eventPriorityQueue.top(); // passed in for processing
        int currentTime = newEvent.time; // passed in for processing
        if(newEvent.transactionLength != 0){ // if arrival event
            processArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable, totalWaitTime, currentTime);
        } // end if
        else{ // else it is a departure event
            processDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, totalWaitTime, currentTime);
       } // end else
    } // end while
    // display final statistics
    cout << endl;
    cout << "Final Statistics:" << endl;
    cout << endl;
    cout << "   Total number of people processed: " << totalPeople << endl;
    cout << "   Total amount of time waited: " << totalWaitTime << endl;
    cout << "   Average amount of time spent waiting: " << (double)totalWaitTime/totalPeople << endl;
} // end simulate
/*********************************************************************
 ** FUNCTION: processArrival
 ** DESCRIPTION: processes an arrival event, the action taken will
 ** depend on whether, the bankLine is empty and teller is available
 ** if both of these conditions are not met, a customer with the event
 ** must be added to the bankLine queue
 ** PARAMETERS: Event arrivalEvent, priority_queue<Event> &eventPriorityQueue, 
 ** queue<Customer> &bankLine, bool& tellerAvailable, int &totalWaitTime, int currentTime
 ** PRE-CONDITIONS: should have events to be processed
 ** POST-CONDITIONS: eventPriorityQueue updated, and bankLine may be updated
 ** totalWaitTime may also be updated
 ** RETURNS: nothing
 *********************************************************************/
void processArrival(Event arrivalEvent, priority_queue<Event> &eventPriorityQueue, queue<Customer> &bankLine, bool& tellerAvailable, int &totalWaitTime, int currentTime){
    
    eventPriorityQueue.pop(); // take off top event
    Customer tempCust; // to hold info about this event in a cust for possible push into bankLine
    tempCust.event.time = arrivalEvent.time;
    tempCust.event.transactionLength = arrivalEvent.transactionLength;
    cout << "Processing an arrival event at time: " << arrivalEvent.time << endl;

    int waitTime;
    if(bankLine.empty() && tellerAvailable){ // if bankLine is empty and teller is available
        int departureTime = currentTime + arrivalEvent.transactionLength; // departureTime = currtime + arrivaltime
        Event newDepartureEvent;
        newDepartureEvent.time = departureTime; // fill departure event with departure time
        eventPriorityQueue.push(newDepartureEvent); // add departure event into eventPriorityQueue
        tellerAvailable = false; // teller is occupied
        waitTime = 0;
        totalWaitTime += waitTime; // update totalWaitTime
    } // end if
    else{ // if teller occupied and bankLine not empty, add tempCust into bankLine
        bankLine.push(tempCust);
    } // end else
 
} // end processArrival
/*********************************************************************
 ** FUNCTION: processDeparture
 ** DESCRIPTION: processes a departure event, the action taken will
 ** depend on whether, the bankLine is empty or not
 ** if empty then process next cust at front of line
 ** PARAMETERS: Event arrivalEvent, priority_queue<Event> &eventPriorityQueue,
 ** queue<Customer> &bankLine, bool& tellerAvailable, int &totalWaitTime, int currentTime
 ** PRE-CONDITIONS: should have events to be processed
 ** POST-CONDITIONS: eventPriorityQueue updated, and bankLine may be updated
 ** totalWaitTime and tellerAvailable may also be updated
 ** RETURNS: nothing
 *********************************************************************/
void processDeparture(Event departureEvent, priority_queue<Event> &eventPriorityQueue, queue<Customer> &bankLine, bool& tellerAvailable, int &totalWaitTime, int currentTime){
   
    eventPriorityQueue.pop(); // remove top from eventPriorityQueue
    cout << "Processing a departure event at time: " << departureEvent.time << endl;

    if(!bankLine.empty()){ // if bankLine is not empty
        int waitTime;
        Customer tempCust;
        tempCust = bankLine.front(); // holds value from bankLine before it is popped off
        bankLine.pop();
        int departureTime = currentTime + tempCust.event.transactionLength; // departureTime of tempcust
        waitTime = currentTime  - tempCust.event.time; // waitTime of tempCust
        Event newDepartureEvent;
        newDepartureEvent.time = departureTime; // departure event filled with time
        eventPriorityQueue.push(newDepartureEvent); // add this departure event to eventPriorityQueue
        totalWaitTime += waitTime; // update totalWaitTime
    } // end if
    else{ // else if the bankLine is empty teller is available
        tellerAvailable = true;
    } // end else

} // end processDeparture

















