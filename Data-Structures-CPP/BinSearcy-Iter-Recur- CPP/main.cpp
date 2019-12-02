//Tobby Lie 103385744
//CSCI 2421
//Homework 3
//September 8, 2017
//This program takes data about
//vehicles from a file and stores
//the data into a vector.
//operations such as searching
//and sorting can be performed
//on the data

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include "Recursion.h"

using namespace std;

int main() {
    // create Recursion object
    Recursion r;
    
    // read in data from file
    r.readFromFile();
    cout << endl;
    // initial print out of all contents
    r.print();
   
    // will continue looping until user chooses to exit
    // by inputting 0
    int choice = 0;
    char exit = 'n';
    do{
        cout << "This program will allow you to search for a vehicle" << endl;
        cout << "based on year, make or model. It will demonstrate" << endl;
        cout << "the binary search through recursively and iteratively" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Here are your options (1-6)" << endl;
        cout << "1: Binary Recursive Search by Year" << endl;
        cout << "2: Binary Recursive Search by Make" << endl;
        cout << "3: Binary Recursive Search by Model" << endl;
        cout << "4: Binary Iterative Search by Year" << endl;
        cout << "5: Binary Iterative Search by Make" << endl;
        cout << "6: Binary Iterative Search by Model" << endl;
        cout << "Please make a selection." << endl;
        cin >> choice;
        while(choice > 6 || choice < 1){
            cout << "Invalid input, must be a number between 1-6" << endl;
            cin >> choice;
        }
        switch(choice){
            case 1:{
                r.displayRecYear();
                break;
            }
            case 2:{
                r.displayRecMake();
                break;
            }
            case 3:{
                r.displayRecModel();
                break;
            }
            case 4:{
                r.displayIterYear();
                break;
            }
            case 5:{
                r.displayIterMake();
                break;
            }
            case 6:{
                r.displayRecModel();
                break;
            }
        }
        cout << "If you would like to go to the main menu input 1" << endl;
        cout << "If you would like to exit input 0" << endl;
        cin >> choice;
        while(choice > 1 || choice < 0){
            cout << "Invalid input, (1 for main menu, 0 to exit)" << endl;
            cin >> choice;
        }
    }while(choice == 1 || exit == 1);
    return 0;
}
