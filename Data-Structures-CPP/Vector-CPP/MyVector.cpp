//Tobby Lie
//CSCI 2421
//Homework 4
//September 15, 2017
//myVector class implementation

#include "MyVector.h"
#include <iostream>

// use namespace HW4
namespace HW4{

/*********************************************************************
** FUNCTION: MyVector()
** DESCRIPTION: default constructor
** PARAMETERS:  none
** PRE-CONDITIONS: none
** POST-CONDITIONS: none
** RETURNS: nothing
*********************************************************************/
MyVector::MyVector():vsize(0),vec(nullptr){}
/*********************************************************************
** FUNCTION: operator[]
** DESCRIPTION: overloaded []
** PARAMETERS:  int index
** PRE-CONDITIONS: should pass in int
** POST-CONDITIONS: none
** RETURNS: type T
*********************************************************************/
T MyVector::operator[] (int index){
    if(index < 0 || index > (vsize-1)){
        exit(0); // this conditional statement causes program to exit if index that is not allocated for
        // is passed in
    }// end if
    return vec[index];
}// end operator[]
/*********************************************************************
** FUNCTION: pop_back
** DESCRIPTION: removes last element in array
** PARAMETERS:  none
** PRE-CONDITIONS: array should have at least one element
** POST-CONDITIONS: size decreases by 1
** RETURNS: none
     *********************************************************************/
void MyVector::pop_back(){
    T* tempPtr = new T[vsize]; // create temp pointer that holds current size
    if(vsize == 0){
        exit(0); // if vector is empty then do nothing
    }// end if
    for(int i = 0; i < (vsize - 1); i ++){
        tempPtr[i] = vec[i]; // load tempPtr with vec elements
    }// end for
    vsize--; // decrement size
    delete[] vec;
    vec = nullptr;
    vec = new T[vsize]; // allocate only enough memory for vec size - 1
    for(int i = 0; i < vsize; i++){
        vec[i] = tempPtr[i]; // load vec with tempPtr contents that does not include last element
    }// end for
    delete[] tempPtr; // deallocate tempPtr memory
}// end pop_back
/*********************************************************************
** FUNCTION: push_back
** DESCRIPTION: add single element to the end of an array
** PARAMETERS:  T value
** PRE-CONDITIONS: should pass in type T
** POST-CONDITIONS: array size increases by 1
** RETURNS: none
*********************************************************************/
void MyVector::push_back(T value){
    T* tempPtr = new T[vsize+1]; // allocate tempPtr enough memory for the size plus 1
    for(int i = 0; i < vsize; i++){
        tempPtr[i] = vec[i]; // load tempPtr with all elements of vec
    }// end for
    tempPtr[vsize] = value; // using the current size as index, load the value passed in
                            // into the tempPtr array
    vsize++; // increase overall size by 1
    delete[] vec; // deallocate vec
    vec = new T[vsize]; // allocate new memory for vec that is the new size
    for(int i = 0; i < vsize; i++){
        vec[i] = tempPtr[i]; // load vec with all elements of tempPtr which now contains the new value
    }// end for
    delete[] tempPtr; // deallocate tempPtr memory
}// end push_back
/*********************************************************************
** FUNCTION: size
** DESCRIPTION: returns current size of array
** PARAMETERS:  none
** PRE-CONDITIONS: size can be empty or filled
** POST-CONDITIONS: none
** RETURNS: int vsize
*********************************************************************/
int MyVector::size(){
    return vsize;
}// end size
/*********************************************************************
** FUNCTION: empty
** DESCRIPTION: returns bool to see if array is empty or not
** PARAMETERS:  none
** PRE-CONDITIONS: array can be empty or filled
** POST-CONDITIONS: none
** RETURNS: bool
*********************************************************************/
bool MyVector::empty(){
    if(vsize == 0){
        return true; // true if size is 0
    }
    return false; // false if size is > 0
}//end empty
/*********************************************************************
** FUNCTION: search
** DESCRIPTION: linear search
** PARAMETERS:  T value
** PRE-CONDITIONS: should pass in type T
** POST-CONDITIONS: none
** RETURNS: int position
*********************************************************************/
int MyVector::search(T Value){
int index = 0;
int position  = -1; // position returns -1 if no element found
bool found = false;
while(index < vec[index] && !found){
    if(vec[index] == Value)
    {
        found = true; // will break out of loop if true
        position = index; // position updated
    }// end if
    index++;
}// end while
return position;
}// end search
    
}















