//
//CSCI 2421
//Homework 1
//August 25, 2017
//Guess Class prototypes

#include <vector>

using namespace std;

class Guess{
    
private:
    //holds random numbers
    vector<int> randomVector;
    //holds number of digits in number
    int numDigits;
    //holds range that each digit can carry
    int range;
    //holds number of correct guesses by user
    int compareCounter;
    
public:
    //setter for numDigits variable
    void setNumDigits();
    //getter for numDigits variable
    int getNumDigits();
    //setter for range variable
    void setRange();
    //getter for range variable
    int getRange();
    //generates and populates random numbers
    //into randomVector
    void setRandomVector();
    //asks user for guess input which
    //is then compared against elements
    //in randomVector
    void setUserGuess();
    //getter for compareCounter variable
    int getCompareCounter();
    //will check if user has won the game
    bool checkVictory(int);
    
};
