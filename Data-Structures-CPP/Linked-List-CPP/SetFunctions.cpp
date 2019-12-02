//Tobby Lie
//CSCI 2421
//Homework 5
//Septemember 22, 2017
//Support functions for LinkedList program

#include <iostream>
#include <sstream> //string stream
#include <string>
#include <fstream>
#include "SetFunctions.h"

using namespace std;

/*********************************************************************
 ** FUNCTION: getCharFromFile
 ** DESCRIPTION: reads in chars from file and stores in list
 ** PARAMETERS: ifstream &infile, LinkedList& list
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool getCharFromFile(ifstream &infile, LinkedList& list){
    
    stringstream ss;
    char tempChar;
    string readString;
    
    getline(infile, readString);
    //write readString into ss
    ss << readString;
    
    //until end of stream
    while(!ss.eof()){
        
        //read in char from ss into tempChar
        ss >> tempChar;

        //if it fails to read a char data type
        if(ss.fail()){
            
            //cout << "Input contains non-integer data." << endl;
            ss.clear(); //clears state of string stream
            return false;
            
        }
        
        list.insertAtFront(tempChar); //add to list object
        
    }
    return true;
    
}



















