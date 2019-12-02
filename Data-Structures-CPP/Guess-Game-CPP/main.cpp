//Tobby Lie 103385744
//CSCI 2421
//Homework 1
//August 25, 2017
//This program randomly generates a number
//The user specifies the digits and range
//of each digit and then must try to guess
//this number

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Guess.h"


int main() {
    
    srand((int)time(NULL));
    
    //to ask user if they would like to play again
    char ans;
    
    do{
        
    Guess g;
    
    //will ask user for input
    //for digits and range
    g.setNumDigits();
    g.setRange();
    
    //will randomly generate numbers
    //and will populate randomVector
    g.setRandomVector();
    
    //will ask user for guess
    //based off of each digit
    //of the vector
    g.setUserGuess();
    
    int chances = 2;
    
    //this loop will continue to iterate
    //as long as the user has not
    //correctly guessed the number
    //AND chances does not reach 0
    while(g.getCompareCounter() != g.getNumDigits() && chances > 0){
        
        
         cout << endl;
        //this message will hint the user
        //as to how many digits they got right
         cout << g.getCompareCounter() << " of your guesses are correct. You have ";
        cout << chances << " more chance(s) to guess correctly." << endl;
         cout << "Guess again." << endl;
         cout << endl;
         g.setUserGuess();
        
        if(g.getCompareCounter() != g.getNumDigits()){
            
             chances--;
            
        }
    }
    
        //this code will check whether or not
        //user has won after 3 tries
        
    bool winner = g.checkVictory(chances);
        
        if(winner == true){
            
            cout << "Correct!" << endl;
            
        }
        else if(winner == false){
            
            cout << "You lose!" << endl;
            
        }
 
    //user asked for input on
    //whether they would like to
    //play again or not
    cout << "Play again(Y/N)?" << endl;
        
        cin >> ans;
        
    }while(ans == 'y' || ans == 'Y');
    
    cout << "Goodbye!" << endl;
   
    
    return 0;
}
