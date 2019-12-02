#include <iostream>
#include "Recursion.h"


/*********************************************************************
 ** FUNCTION: Recursion
 ** DESCRIPTION: default constructor
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
Recursion::Recursion(){}
// end default constructor
/*********************************************************************
 ** FUNCTION: readFromFile
 ** DESCRIPTION: reads data from file into Vehicle vector
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: should have file to open
 ** POST-CONDITIONS: Vehicle vector filled
 ** RETURNS: nothing
 *********************************************************************/
void Recursion::readFromFile(){
    ifstream inFile;
    inFile.open("vehiclein.txt"); // open file
    if(inFile.fail()){
        cout << "Unable to open file!" << endl;
        return; // if file could not be open return
    }// end if
    int _year;
    string _make;
    string _model;
    string bar;
    while(!inFile.eof()){
        inFile >> _year;
        inFile.ignore();
        getline(inFile, _make);
        getline(inFile, _model);
        getline(inFile, bar);
        // use temp to hold contents of class
        Vehicle temp(_year, _make, _model);
        // push_back into actual vector
        v.push_back(temp);
    }// end while
}// end readFromFile
/*********************************************************************
 ** FUNCTION: sortYear
 ** DESCRIPTION: sorts vector by year
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: vector sorted by year
 ** RETURNS: nothing
 *********************************************************************/
void Recursion::sortYear(){
    int startScan, minIndex;
    int minYear;
    Vehicle minValue;
    int size = (int)v.size(); // vector size
    for(startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minYear = v[startScan].getYear();
        minValue = v[startScan];
        for(int index = startScan + 1; index < size; index++){
            if(v[index].getYear() < minYear){
                minValue = v[index];
                minIndex = index;
            } // end if
        } // end for
        v[minIndex] = (v[startScan]);
        v[startScan] = (minValue);
    } // end for
} // end sortYear
/*********************************************************************
 ** FUNCTION: sortMake
 ** DESCRIPTION: sorts vector by make
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: vector sorted by make
 ** RETURNS: nothing
 *********************************************************************/
void Recursion::sortMake() {
    int startScan, minIndex;
    string minYear;
    Vehicle minValue;
    int size = (int)v.size(); // size of vector
    for(startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minYear = v[startScan].getMake();
        minValue = v[startScan];
        for(int index = startScan + 1; index < size; index++){
            if(v[index].getMake() < minYear){
                minValue = v[index];
                minIndex = index;
            } // end if
        } // end for
        v[minIndex] = (v[startScan]);
        v[startScan] = (minValue);
    } // end for
} // end sortMake
/*********************************************************************
 ** FUNCTION: sortModel
 ** DESCRIPTION: sorts vector by model
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: vector sorted by model
 ** RETURNS: nothing
 *********************************************************************/
void Recursion::sortModel(){
    int startScan, minIndex;
    string minYear;
    Vehicle minValue;
    int size = (int)v.size(); // size of vector
    for(startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minYear = v[startScan].getModel();
        minValue = v[startScan];
        for(int index = startScan + 1; index < size; index++){
            if(v[index].getModel() < minYear){
                minValue = v[index];
                minIndex = index;
            } // end if
        } // end for
        v[minIndex] = (v[startScan]);
        v[startScan] = (minValue);
    }// end for
} // end sortModel
/*********************************************************************
 ** FUNCTION: getFrequencyOf
 ** DESCRIPTION: overloaded getFrequencyOf function that
 ** returns int for how many times year appears in vector
 ** PARAMETERS:  int year
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::getFrequencyOf(int year) const{
    int frequency = 0;
    int searchIndex = 0;
    while (searchIndex < v.size())
    {
        if ((v[searchIndex].getYear()) == year){
            frequency++;
        } // end if
        searchIndex++;
    } // end while
    return frequency;
} // end getFrequencyOf
/*********************************************************************
 ** FUNCTION: getFrequencyOf
 ** DESCRIPTION: overloaded getFrequencyOf function that
 ** returns int for how many times make appears in vector
 ** PARAMETERS:  string make
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::getFrequencyOf(string make) const{
    int frequency = 0;
    int searchIndex = 0;
    while (searchIndex < v.size()){
        if ((v[searchIndex].getMake()) == make){
            frequency++;
        } // end if
        searchIndex++;
    } // end while
    return frequency;
} // end getFrequencyOf
/*********************************************************************
 ** FUNCTION: getFrequencyOf
 ** DESCRIPTION: overloaded getFrequencyOf function that
 ** returns int for how many times model appears in vector
 ** PARAMETERS:  string make, string forModel in order to overload 
 ** for model
 ** PRE-CONDITIONS: vector should be filled, two string arguments
 ** must be sent in
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::getFrequencyOf(string model, string forModel) const{
    int frequency = 0;
    int searchIndex = 0;
    while (searchIndex < v.size()){
        if ((v[searchIndex].getModel()) == model){
            frequency++;
        } // end if
        searchIndex++;
    } // end while
    return frequency;
} // end getFrequencyOf
/*********************************************************************
 ** FUNCTION: getSize
 ** DESCRIPTION: returns size of vector
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::getSize() const{
    return (int)v.size(); // size of vector
} // end getSize
/*********************************************************************
 ** FUNCTION: printVehicle
 ** DESCRIPTION: prints contents of one vehicle at an index
 ** PARAMETERS:  index
 ** PRE-CONDITIONS: parameter passed in should be int
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Recursion::printVehicle(int index) const{
    cout << "Vehicle #: " << index + 1 << endl;
    cout << v[index].getYear() << endl;
    cout << v[index].getMake() << endl;
    cout << v[index].getModel() << endl;
} // end printVehicle
/*********************************************************************
 ** FUNCTION: binSearchRec
 ** DESCRIPTION: recursive binary search for year
 ** PARAMETERS:  first, last, int target
 ** PRE-CONDITIONS: first, last should be int, target should be int
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::binSearchRec(int first, int last, int target) const{
    int index = 0;
    if(first > last){
        index = -1;
    } // end if
    else{
        int mid = first + (last - first)/2;
        if(target == v[mid].getYear()){
            index = mid;
        } // end if
        else if(target < v[mid].getYear()){
            index = binSearchRec(first, mid - 1, target);
        } // end else if
        else{
            index = binSearchRec(mid + 1, last, target);
        } // end else
    } // end else
    return index;
} // end binSearchRec
/*********************************************************************
 ** FUNCTION: binSearchRec
 ** DESCRIPTION: recursive binary search for make
 ** PARAMETERS:  first, last, string target
 ** PRE-CONDITIONS: first, last should be int, target should be string
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::binSearchRec(int first, int last, string target) const{
    int index = 0;
    if(first > last){
        index = -1;
    } // end if
    else{
        int mid = first + (last - first)/2;
        if(target == v[mid].getMake()){
            index = mid;
        } // end if
        else if(target < v[mid].getMake()){
            index = binSearchRec(first, mid - 1, target);
        } // end else if
        else{
            index = binSearchRec(mid + 1, last, target);
        } // end else
    } // end else
    return index;
} // end binSearchRec
/*********************************************************************
 ** FUNCTION: binSearchRec
 ** DESCRIPTION: recursive binary search for model
 ** PARAMETERS:  first, last, string target, string forModel
 ** PRE-CONDITIONS: first, last should be int, target should be string
 ** second string argument must be passed in to signal search for model
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::binSearchRec(int first, int last, string target, string forModel) const{
    int index = 0;
    if(first > last){
        index = -1;
    } // end if
    else{
        int mid = first + (last - first)/2;
        if(target == v[mid].getModel()){
            index = mid;
        } // end if
        else if(target < v[mid].getModel()){
            index = binSearchRec(first, mid - 1, target, forModel);
        } // end else if
        else{
            index = binSearchRec(mid + 1, last, target, forModel);
        } // end else
    } // end else
    return index;
} // end binSearchRec
/*********************************************************************
 ** FUNCTION: print
 ** DESCRIPTION: print contents for all values in vector
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void Recursion::print() const{
    for(int i = 0; i < v.size(); i++){
        cout << v[i].getYear() << endl;
        cout << v[i].getMake() << endl;
        cout << v[i].getModel() << endl;
        cout << endl;
    } // end for
} // end print
/*********************************************************************
 ** FUNCTION: displayRecYear
 ** DESCRIPTION: display all values for year that user specifies
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Recursion::displayRecYear(){
    sortYear(); // sort by year
    cout << "What year are you searching for?" << endl;
    int _year;
    cin.ignore();
    cin >> _year;
    // check to make sure input is an int
    while(cin.fail()){
        cout << "Invalid input, must input an integer that represents a year" << endl;
        cout << "Input a year: " << endl;
        cin.clear(); // clears state
        cin.ignore(); // clear stream buffer
        cin >> _year;
    } // end while
    int index = binSearchRec(0, getSize() - 1, _year);
    int count = 0;
    if(index == -1){
        cout << "There is no record of that year!" << endl;
        return;
    } // end if
    do{
        printVehicle(index);
        index++;
        count++;
    }while(count < getFrequencyOf(_year)); // end do while
} // end displayRecYear
/*********************************************************************
 ** FUNCTION: displayRecMake
 ** DESCRIPTION: display all values for make that user specifies
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Recursion::displayRecMake(){
    sortMake(); // sort by make
    cout << "What make are you searching for?" << endl;
    string _make;
    cin.ignore();
    getline(cin,_make);
    int index = binSearchRec(0, getSize() - 1, _make);
    int count = 0;
    if(index == -1){
        cout << "There is no record of that make!" << endl;
        return;
    } // end if
    do{
        printVehicle(index);
        index++;
        count++;
    }while(count < getFrequencyOf(_make)); // end do while
} // end displayRecMake
/*********************************************************************
 ** FUNCTION: displayRecModel
 ** DESCRIPTION: display all values for model that user specifies
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Recursion::displayRecModel(){
    sortModel(); // sort model
    cout << "What model are you searching for?" << endl;
    string _model, forModel;
    cin.ignore();
    getline(cin,_model);
    int index = binSearchRec(0, getSize() - 1, _model, forModel);
    int count = 0;
    if(index == -1){
        cout << "There is no record of that model!" << endl;
        return;
    } // end if
    do{
        printVehicle(index);
        index++;
        count++;
    }while(count < getFrequencyOf(_model, forModel)); // end do while
} // end displayRecModel
/*********************************************************************
 ** FUNCTION: binSearchIter
 ** DESCRIPTION: iterative binary search for year
 ** PARAMETERS: int target
 ** PRE-CONDITIONS: target should be int
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::binSearchIter(int target) const{
    int first = 0;
    int last = (int)v.size() - 1, middle, position = -1;
    bool found = false;
    while(!found && first <= last){
        middle = (first+last)/2;
        if(v[middle].getYear() == target){
            found = true;
            position = middle;
        } // end if
        else if(v[middle].getYear() > target){
            last = middle - 1;
        } // end else if
        else{
            first = middle + 1;
        } // end else
    } // end while
return position;
} // end binSearchIter
/*********************************************************************
 ** FUNCTION: binSearchIter
 ** DESCRIPTION: iterative binary search for make
 ** PARAMETERS: string target
 ** PRE-CONDITIONS: target should be string
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::binSearchIter(string target) const{
        int first = 0;
        int last = (int)v.size() - 1, middle, position = -1;
        bool found = false;
        while(!found && first <= last){
            middle = (first+last)/2;
            if(v[middle].getMake() == target){
                found = true;
                position = middle;
            } // end if
            else if(v[middle].getMake() > target){
                last = middle - 1;
            } // end else if
            else{
                first = middle + 1;
            } // end else
        } // end while
return position;
} // end binSearchIter
/*********************************************************************
 ** FUNCTION: binSearchIter
 ** DESCRIPTION: iterative binary search for model
 ** PARAMETERS: string target, string forModel
 ** PRE-CONDITIONS: target should be string and second string must 
 ** be sent in to signal for search for model
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int Recursion::binSearchIter(string target, string forModel) const{
    int first = 0;
    int last = (int)v.size() - 1, middle, position = -1;
    bool found = false;
    while(!found && first <= last){
        middle = (first+last)/2;
        if(v[middle].getModel() == target){
            found = true;
            position = middle;
        } // end if
        else if(v[middle].getModel() > target){
            last = middle - 1;
        } // end else if
        else{
            first = middle + 1;
        } // end else
    } // end while
return position;
} // end binSearchIter
/*********************************************************************
 ** FUNCTION: displayIterYear
 ** DESCRIPTION: display all values for year that user specifies
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Recursion::displayIterYear(){
    sortYear();
    cout << "What year are you searching for?" << endl;
    int _year;
    cin.ignore();
    cin >> _year;
    //check to make sure input is an int
    while(cin.fail()){
        cout << "Invalid input, must input an integer that represents a year" << endl;
        cout << "Input a year: " << endl;
        cin.clear(); // clears state
        cin.ignore(); // clear stream buffer
        cin >> _year;
    } // end while
    int index = binSearchIter(_year);
    int count = 0;
    if(index == -1){
        cout << "There is no record of that year!" << endl;
        return;
    } // end if
    do{
        printVehicle(index);
        index++;
        count++;
    }while(count < getFrequencyOf(_year)); // end do while
} // end displayIterYear
/*********************************************************************
 ** FUNCTION: displayIterMake
 ** DESCRIPTION: display all values for make that user specifies
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Recursion::displayIterMake(){
    sortMake();
    cout << "What make are you searching for?" << endl;
    string _make;
    cin.ignore();
    getline(cin,_make);
    int index = binSearchIter(_make);
    int count = 0;
    if(index == -1){
        cout << "There is no record of that make!" << endl;
        return;
    } // end if
    do{
        printVehicle(index);
        index++;
        count++;
    }while(count < getFrequencyOf(_make)); // end do while
} // end displayIterMake
/*********************************************************************
 ** FUNCTION: displayIterModel
 ** DESCRIPTION: display all values for model that user specifies
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: vector should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void Recursion::displayIterModel(){
    sortModel();
    cout << "What model are you searching for?" << endl;
    string _model, forModel;
    cin.ignore();
    getline(cin,_model);
    int index = binSearchIter(_model, forModel);
    int count = 0;
    if(index == -1){
        cout << "There is no record of that model!" << endl;
        return;
    } // end if
    do{
        printVehicle(index);
        index++;
        count++;
    }while(count < getFrequencyOf(_model, forModel)); // end do while
} // end displayIterModel

































