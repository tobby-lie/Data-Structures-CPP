#include <iostream>
#include "Vehicle.h"


/*********************************************************************
 ** FUNCTION: Vehicle
 ** DESCRIPTION: default constructor for Vehicle class
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
Vehicle::Vehicle(){
    year = 0;
    make = "";
    model = "";
}
/*********************************************************************
 ** FUNCTION: Vehicle
 ** DESCRIPTION: overloaded constructor
 ** PARAMETERS:  _year,_make,_model
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: Vehicle class updated
 ** RETURNS: none
 *********************************************************************/
Vehicle::Vehicle(int _year, string _make, string _model){
    year = _year;
    make = _make;
    model = _model;
}
/*********************************************************************
 ** FUNCTION: getYear
 ** DESCRIPTION: accessor for year
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: year should be populated
 ** POST-CONDITIONS: none
 ** RETURNS: string
 *********************************************************************/
int Vehicle::getYear() const{
    return year;
}
/*********************************************************************
 ** FUNCTION: getMake
 ** DESCRIPTION: accessor for make
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: make should be populated
 ** POST-CONDITIONS: none
 ** RETURNS: string
 *********************************************************************/
string Vehicle::getMake() const{
    return make;
}
/*********************************************************************
 ** FUNCTION: getModel
 ** DESCRIPTION: accessor for model
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: model should be populated
 ** POST-CONDITIONS: none
 ** RETURNS: string
 *********************************************************************/
string Vehicle::getModel() const{
    return model;
}
/*********************************************************************
 ** FUNCTION: setYear
 ** DESCRIPTION: mutator for year
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: year updated
 ** RETURNS: nothing
 *********************************************************************/
void Vehicle::setYear(int _year){
    year = _year;
}
/*********************************************************************
 ** FUNCTION: setMake
 ** DESCRIPTION: mutator for make
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: make updated
 ** RETURNS: nothing
 *********************************************************************/
void Vehicle::setMake(string _make){
    make = _make;
}
/*********************************************************************
 ** FUNCTION: setModel
 ** DESCRIPTION: mutator for model
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: model updated
 ** RETURNS: nothing
 *********************************************************************/
void Vehicle::setModel(string _model){
    model = _model;
}








































