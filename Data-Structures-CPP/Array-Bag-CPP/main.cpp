//Tobby Lie 103385744
//CSCI 2421
//Homework 2
//September 4, 2017
//This program takes two sets of integers
//from a file and adds them together into one
//set excluding duplicates and also removes
//the contents of one file from another file

#include <iostream>
#include <fstream>
#include <string>
#include "SetFunctions.h"


using namespace std;

int main(){
    
    ifstream infile;

    infile.open("setInput.txt");
    
    if(infile.fail()){
        cout << "could not open file!" << endl;
    }
    
    ArrayBag bag1, bag2, resultBag;
    getIntsFromFile(infile, bag1);
    getIntsFromFile(infile,bag2);
    
    cout << "Two sets of integers called Bag1 and Bag2" << endl;
    cout << "-----------------------------------------";
    cout << endl;
    
    cout << "Bag1: ";
    bag1.printValues();
    cout << "Bag2: ";
    bag2.printValues();
    cout << endl;
    
    cout << "Results of Bag1 and Bag2 union and difference" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "result union(Bag1 + Bag2): ";
    // (bag1 + bag2)
    resultBag = bag1 + bag2;
    resultBag.printValues();
    
    cout << "result difference(Bag1 - Bag2): ";
    // (bag1 - bag2)
    resultBag = bag1 - bag2;
    resultBag.printValues();

    
    return 0;
}
