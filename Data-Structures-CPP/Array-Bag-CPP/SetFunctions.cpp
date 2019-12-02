#include <iostream>
#include <sstream> //string stream
#include <string>
#include <fstream>
#include "SetFunctions.h"

using namespace std;

bool getIntsFromFile(ifstream &infile, ArrayBag& bag){
    
    stringstream ss;
    int tempInt;
    string readString;
    
    getline(infile, readString);
    //write readString into ss
    ss << readString;
    
    //until end of stream
    while(!ss.eof()){
        
        //read in int from ss into tempInt
        ss >> tempInt;
        
        //if it fails to read an int data type
        if(ss.fail()){
            
            //cout << "Input contains non-integer data." << endl;
            ss.clear(); //clears state of string stream
            return false;
            
        }
        
        bag.add(tempInt); //add to bag object
        
    }
    return true;
    
}
