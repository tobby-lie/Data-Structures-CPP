//
//CSCI 2421
//Homework 3
//September 8, 2017
//Vehicle class prototypes

#include <string>
#include <fstream>

using namespace std;

class Vehicle{
    
private:
    int year;
    string make;
    string model;
    
public:
    Vehicle();
    //constructor
    Vehicle(int _year, string _make, string _model);
    //accessors
    int getYear() const;
    string getMake() const;
    string getModel() const;
    //mutators
    void setYear(int _year);
    void setMake(string _make);
    void setModel(string _model);
    //print contents of class
    //sort functions
};


