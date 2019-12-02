//
//CSCI 2421
//Homework 3
//September 8, 2017
//Recursion class prototypes

#include "Vehicle.h"
#include <vector>

using namespace std;

class Recursion{
    
private:
    vector<Vehicle> v;
    
public:
    // default constructor
    Recursion();
    
    // read data from file
    // into v vector
    void readFromFile();
    
    // sort functions
    void sortYear();
    void sortMake();
    void sortModel();
    
    // overloaded functions to
    // get frequency of
    // year
    int getFrequencyOf(int year) const;
    // make
    int getFrequencyOf(string make) const;
    // model
    int getFrequencyOf(string model, string forModel) const;
    
    // overloaded recursive
    // binary search functions
    // for year
    int binSearchRec(int first, int last, int target) const;
    // for make
    int binSearchRec(int first, int last, string target) const;
    // for model
    int binSearchRec(int first, int last, string target, string forModel) const;
    
    // overloaded iterative
    // binary search functions
    // for year
    int binSearchIter(int target) const;
    // for make
    int binSearchIter(string target) const;
    // for model
    int binSearchIter(string target, string forModel) const;
    
    // get size of vector
    int getSize() const;
    
    // print vehicle at
    // certain index
    void printVehicle(int index) const;
    
    // print contents of
    // entire v vector
    void print() const;
    
    // print all data about
    // a vehicle at a given
    // year for Recursive
    void displayRecYear();
    // given a make
    void displayRecMake();
    // given a model
    void displayRecModel();
    
    // print all data about
    // a vehicle at a given
    // year for Iterative
    void displayIterYear();
    // given a make
    void displayIterMake();
    // given a model
    void displayIterModel();
    
};

























