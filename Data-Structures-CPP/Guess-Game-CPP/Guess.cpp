#include "Guess.h"
#include <iostream>


using namespace std;

/*********************************************************************
 ** FUNCTION: setNumDigits
 ** DESCRIPTION: prompts user for input of numDigits
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: input must be a number
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/

void Guess::setNumDigits(){
    
    cout << "How many digits would you like the randomly generated number to be?" << endl;
    cin >> numDigits;
    
}

/*********************************************************************
 ** FUNCTION: setRange
 ** DESCRIPTION: prompts user for input of range
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: input must be a number
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/

void Guess::setRange(){
    
    cout << "Please specify the range you would like each digit to have, from 1 - m." << endl;
    cout << "Input m: " << endl;
    cin >> range;
    
}

/*********************************************************************
 ** FUNCTION: getRange
 ** DESCRIPTION: returns range variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: range
 *********************************************************************/

int Guess::getRange(){
    
    return range;
    
}

/*********************************************************************
 ** FUNCTION: getNumDigits
 ** DESCRIPTION: returns numDigits variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: numDigits
 *********************************************************************/

int Guess::getNumDigits(){
    
    return numDigits;
    
}

/*********************************************************************
 ** FUNCTION: setRandomVector
 ** DESCRIPTION: generates random numbers and populates 
 ** the randomVector vector
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: must use srand to seed system time in 
 ** random number generation
 ** POST-CONDITIONS: randomVector updated
 ** RETURNS: nothing
 *********************************************************************/

void Guess::setRandomVector(){
    
    for(int i = 0; i < numDigits; i++){
        
        randomVector.push_back(1 + rand()%range);
        //can be taken out
        //cout << randomVector[i];
        
    }
    //can be taken out
    //cout << endl;
}

/*********************************************************************
 ** FUNCTION: setUserGuess
 ** DESCRIPTION: asks user for input for individual digits used
 ** as guesses to be compared against randomVector vector elements
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: inputs must be numbers
 ** POST-CONDITIONS: compareCounter may or may not be updated
 ** RETURNS: nothing
 *********************************************************************/

void Guess::setUserGuess(){
    
    vector<int> tempRandomVector;
    compareCounter = 0;
    
    
    cout << "It is time for you to enter in your guess of " << numDigits << " digits" << endl;
    cout << "And a range of 1 - " << range << " per digit." << endl;
    cout << endl;
    
    
    for(int i = 0; i < numDigits; i++){
        
        int guess = 0;
        
        cout << "Please input digit " << i + 1 << " within the range of 1 - " << range << endl;
        cin >> guess;
        
        for(int j = 0; j < randomVector.size(); j++) {
            
            if(guess == randomVector[j]){
                
                compareCounter++;
                
                tempRandomVector.push_back(randomVector[j]);
                
                randomVector.erase(randomVector.begin() + j);
                
                guess = 0;
                
            }
        }
}
    for(int i = 0; i < tempRandomVector.size(); i++){
        
        randomVector.push_back(tempRandomVector[i]);
        
    }
    
}

/*********************************************************************
 ** FUNCTION: getCompareCounter
 ** DESCRIPTION: returns compareCounter variable
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: compareCounter
 *********************************************************************/

int Guess::getCompareCounter(){
    
    return compareCounter;
    
}

/*********************************************************************
 ** FUNCTION: checkVictory
 ** DESCRIPTION: returns bool to represent victory or loss
 ** PARAMETERS:  chance
 ** PRE-CONDITIONS: int of user tries must be passed in
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/


bool Guess::checkVictory(int chance){
    
    if(chance > 0){
        return true;
    }
    
    return false;
    
}





