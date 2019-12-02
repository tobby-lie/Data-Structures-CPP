//Tobby Lie 103385744
//CSCI 2421
//Homework 7
//October 7, 2017
//threeTellerSimulation function implementation

#include <fstream>
#include <iostream>
#include <iomanip>
#include "threeTellerSimulation.h"

using namespace std;

/*********************************************************************
 ** FUNCTION: threeTellerSimulation
 ** DESCRIPTION: runs the bank simulation which calls processArrival
 ** and processDeparture, will continue looping until the eventPriority
 ** queue is empty, will utilize three tellers
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: should have input from file available
 ** POST-CONDITIONS: eventPriorityQueue should be empty and data should
 ** be processed and displayed in a program trace that tracks events executed
 ** RETURNS: nothing
 *********************************************************************/
void threeTellerSimulation(){
    
    priority_queue<threeTellerEvent> eventPriorityQueue; // eventPriorityQueue
    
    Teller t[3]; // array of three tellers
    for(int i = 0; i < 3; i++){
        t[i].available = true; // set all three teller availability to true
    } // end for
    
    ifstream inFile;
    inFile.open("Input.txt"); // open input file
    if(inFile.fail()){
        cout << "unable to open file!" << endl;
    } // end if
    
    int _time, _transactionLength; // temp variables for time and transLength input
    while(!inFile.eof()){ // loops until end of file to input into eventPriorityQueue
        threeTellerEvent newArrivalEvent;
        inFile >> _time;
        inFile >> _transactionLength;
        newArrivalEvent.time = _time;
        newArrivalEvent.transactionLength = _transactionLength;
        eventPriorityQueue.push(newArrivalEvent);
    } // end while
    inFile.close(); // close file
    
    int totalPeople = (int)eventPriorityQueue.size(); // total people tracked through reference var
    int totalWaitTime = 0; // total wait time tracked through reference var
    cout << "Simulation With Three Tellers Begins" << endl;
    cout << endl;
    while(!eventPriorityQueue.empty()){ // will run until eventPriorityQueue is empty
        threeTellerEvent newEvent;
        newEvent = eventPriorityQueue.top();
        int currentTime = newEvent.time; // keeps track of current time
        if(newEvent.transactionLength != 0){ // if there is transaction length this means it is arrival
            processThreeTellerArrival(newEvent, eventPriorityQueue, t, totalWaitTime, currentTime);
        } // end if
        else{ // else departure event
            processThreeTellerDeparture(newEvent, eventPriorityQueue, t, totalWaitTime, currentTime);
        } // end else
    } // end while
    // display final statistics
    cout << endl;
    cout << "Final Statistics:" << endl;
    cout << endl;
    cout << "   Total number of people processed: " << totalPeople << endl;
    cout << "   Total amount of time waited: " << totalWaitTime << endl;
    cout << "   Average amount of time spent waiting: " << (double)totalWaitTime/totalPeople << endl;
    cout << endl;
} // end threeTellerSimulation
/*********************************************************************
 ** FUNCTION: determineShortestLine
 ** DESCRIPTION: Takes array of tellers and will return the index of the
 ** Teller with the smallest tellerLine
 ** PARAMETERS: Teller t[]
 ** PRE-CONDITIONS: should have Teller array
 ** POST-CONDITIONS: none
 ** RETURNS: int shortestLineIndex
 *********************************************************************/
int determineShortestLine(Teller t[]){
    // determine shortest line for tellers
    Teller tempTeller; // represents the teller with shortest line
    int shortestLineIndex = 0; // will hold value of index of teller with shortest line
    int smallestLine = (int)t[0].tellerLine.size(); // will hold initial smallest line value
    for(int i = 1; i < 3; i++){ // check through all tellers
        if(t[i].tellerLine.size() < smallestLine){ // if current tellerLine size is less than smallest line
            smallestLine = (int)t[i].tellerLine.size();// if current teller is less than smallest line value
            shortestLineIndex = i;
        } // end if
    } // end for
    return shortestLineIndex;
} // end determineShortestLine
/*********************************************************************
 ** FUNCTION: processThreeTellerArrival
 ** DESCRIPTION: processes an arrival event, the action taken will
 ** depend on whether, the bankLine is empty and teller is available
 ** for each teller, if these conditions are met for a teller, then
 ** that teller is used and after processing, function returns to caller
 ** PARAMETERS: threeTellerEvent arrivalEvent, priority_queue<threeTellerEvent> &eventPriorityQueue,
 ** Teller t[], int &totalWaitTime, int currentTime
 ** PRE-CONDITIONS: should have events to be processed
 ** POST-CONDITIONS: eventPriorityQueue updated, and tellerLine may be updated
 ** totalWaitTime may also be updated
 ** RETURNS: nothing
 *********************************************************************/
void processThreeTellerArrival(threeTellerEvent arrivalEvent, priority_queue<threeTellerEvent> &eventPriorityQueue, Teller t[], int &totalWaitTime, int currentTime){
    
    eventPriorityQueue.pop(); // remove from top of eventPriorityQueue
    threeTellerCustomer tempCust; // load tempCust with time and transLength
    tempCust.event.time = arrivalEvent.time;
    tempCust.event.transactionLength = arrivalEvent.transactionLength;
    cout << "Processing an arrival event at time: " << arrivalEvent.time << endl;
    
    int waitTime;

    int shortestLineIndex = determineShortestLine(t); // determine teller index with shortest line
    for(int i = 0; i < 3; i++){
        // goes through every teller and sees if they are available
        if(t[i].tellerLine.empty() && t[i].available){
            // departure is equal to currentTime of event + event transaction length
            int departureTime = currentTime + arrivalEvent.transactionLength; // departureTime
            threeTellerEvent newDepartureEvent;
            newDepartureEvent.time = departureTime;
            eventPriorityQueue.push(newDepartureEvent); // add newDepartureEvent to eventPriorityQueue
            t[i].currentCustomer.event.time = departureTime;
            t[i].available = false; // teller is occupied
            waitTime = 0;
            totalWaitTime += waitTime; // totalWaitTime updated
            return; // return so that no other tellers are checked for
        } // end if
    } // end for
    
    t[shortestLineIndex].tellerLine.push(tempCust); // if conditions not met then this line is executed
                                                    // which adds tempCust to tellerLine with shortest line
} // end processThreeTellerArrival
/*********************************************************************
 ** FUNCTION: processThreeTellerDeparture
 ** DESCRIPTION: processes an departure event, the action taken will
 ** depend on if a tellerLine is not empty
 ** PARAMETERS: threeTellerEvent arrivalEvent, priority_queue<threeTellerEvent> &eventPriorityQueue,
 ** Teller t[], int &totalWaitTime, int currentTime
 ** PRE-CONDITIONS: should have events to be processed
 ** POST-CONDITIONS: eventPriorityQueue updated, and tellerLine may be updated
 ** teller availability may also be updated
 ** RETURNS: nothing
 *********************************************************************/
void processThreeTellerDeparture(threeTellerEvent departureEvent, priority_queue<threeTellerEvent> &eventPriorityQueue, Teller t[], int &totalWaitTime, int currentTime){
    
    eventPriorityQueue.pop(); // remove top from eventPriorityQueue
    cout << "Processing a departure event at time: " << departureEvent.time << endl;
    // need to figure out which teller this departure time is from
    for(int i = 0; i < 3; i++){
        if(t[i].currentCustomer.event.time == departureEvent.time)
        { // will only execute for departure that matches the current customer event time
    
            if(!t[i].tellerLine.empty()){ // if that tellerLine is not empty pull from line
                int waitTime;
                threeTellerCustomer tempCust; // fill tempCust with next customer in line
                tempCust = t[i].tellerLine.front();
                t[i].tellerLine.pop(); // remove next cust in line
                int departureTime = currentTime + tempCust.event.transactionLength; // departure time
                waitTime = currentTime - tempCust.event.time; // waitTime
                threeTellerEvent newDepartureEvent; // departure event
                newDepartureEvent.time = departureTime;
                eventPriorityQueue.push(newDepartureEvent); // newDepartureEvent added to eventPriorityQueue
                t[i].currentCustomer.event.time = departureTime; // sets departure time for this cust in line
                return; // return so that next teller is not examined
            } // end if
        } // end if
    } // end for
    for(int i = 0; i < 3; i++){ // go through each element
        if(t[i].currentCustomer.event.time == departureEvent.time){ // match departure time to teller cust time
            t[i].available = true; // set teller to available
        } // end if
    } // end for
} // end processThreeTellerDeparture

















