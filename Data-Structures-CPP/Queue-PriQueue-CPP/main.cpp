//Tobby Lie 103385744
//CSCI 2421
//Homework 7
//October 7, 2017
//This program utilizes queues
//to implement a bank simulation
//the first simulation utilizing
//a single teller and the second
//simulation utilizing three tellers

#include <iostream>
#include "simulation.h"
#include "threeTellerSimulation.h"

using namespace std;

int main(){
    
    simulate(); // simulation with 1 teller
    cout << endl;
    threeTellerSimulation(); // simulation with 3 tellers
    
    return 0;
}
