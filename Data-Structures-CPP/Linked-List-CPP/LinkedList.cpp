//Tobby Lie
//CSCI 2421
//Homework 5
//September 22, 2017
//LinkedList class implementation

#include <iostream>
#include "LinkedList.h"

using namespace std;
/*********************************************************************
 ** FUNCTION: LinkedList
 ** DESCRIPTION: constructor, sets size to 0 and allocates memory for headPtr
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: headPtr allocated
 ** RETURNS: nothing
 *********************************************************************/
LinkedList::LinkedList(){
    // need to allocate memory for headPtr
    headPtr = new Node; // f(1)
    headPtr->nextPtr = nullptr; // f(1)
    size = 0; // f(1)
} // end LinkedList
/*********************************************************************
 ** FUNCTION: ~LinkedList
 ** DESCRIPTION: destructor, set size to 0, delete all nodes in list
 ** PARAMETERS: none
 ** PRE-CONDITIONS: headPtr should at least be allocated for
 ** POST-CONDITIONS: list deleted
 ** RETURNS: nothing
 *********************************************************************/
LinkedList::~LinkedList(){
    Node* currPtr = headPtr; // f(1)
    Node* prevPtr = headPtr; // f(1)
    // loop will delete memory for all elements of the list beginning at headPtr
    while(currPtr != nullptr){ // f(n)
        prevPtr = currPtr; // f(1)
        currPtr = currPtr->nextPtr; //f(1)
        prevPtr = nullptr; //f(1)
        delete prevPtr; //f(1)
    } // end while
    size = 0; //f(1)
} // end LinkedList
/*********************************************************************
 ** FUNCTION: insertAtFront
 ** DESCRIPTION: inserts node to beginning of list
 ** PARAMETERS: char input
 ** PRE-CONDITIONS: headPtr allocated
 ** POST-CONDITIONS: list updated
 ** RETURNS: bool
 *********************************************************************/
bool LinkedList::insertAtFront(char input){
    Node* newNode = new Node; // create newNode  // f(1)
    newNode->data = input;// fill newNode with data;  // f(1)
    newNode->nextPtr = headPtr->nextPtr; // make newNode point to nothing  // f(1)
    headPtr->nextPtr = newNode; // make headPtr point to newNode;  // f(1)
    size++; // increment size  // f(1)
    return true;
} // end insertAtFront
/*********************************************************************
 ** FUNCTION: insertBeforePosition
 ** DESCRIPTION: insert node before an index for list
 ** PARAMETERS: int index, char input
 ** PRE-CONDITIONS: list should have nodes
 ** POST-CONDITIONS: list updated
 ** RETURNS: bool
 *********************************************************************/
bool LinkedList::insertBeforePosition(int index, char input){
    Node* currPtr = nullptr; // f(1)
    Node* trailPtr = nullptr; // f(1)
    Node* newNode = new Node; // create and allocate for newNode // f(1)
    newNode->data = input; // f(1)
    newNode->nextPtr = nullptr; // fill newNode with data // f(1)
    currPtr = headPtr->nextPtr; // trailPtr will trail currPtr by one element // f(1)
    trailPtr = headPtr->nextPtr; // f(1)
    int count = 1; //count starts at 1 because currPtr and trailPtr point to first element // f(1)
    // loops until end of list is reached or count becomes larger than desired index
    while(currPtr != nullptr && count != index-1){  // f(n)
        trailPtr = currPtr; // f(1)
        currPtr = currPtr->nextPtr; // f(1)
        count++; // f(1)
    } // end while
    // if statement tests to see if the current count matches the index, in which case insert can happen
    if(count+1 == index){ // f(1)
        newNode->nextPtr = currPtr; // f(1)
        trailPtr->nextPtr = newNode; // f(1)
        size++; // increment size // f(1)
        return true; // f(1)
    } // end if
    // else return false and print out that there is no position before index provided
    else{ // f(1)
        cout << "There is no position before " << index << endl; // f(1)
        return false;
    } // end else
} // end insertBeforePostion
/*********************************************************************
 ** FUNCTION: insertAtBack
 ** DESCRIPTION: insert node at back of list
 ** PARAMETERS: char input
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: list updated
 ** RETURNS: bool
 *********************************************************************/
bool LinkedList::insertAtBack(char input){
    Node* currPtr = nullptr; // f(1)
    Node* trailPtr = nullptr; // f(1)
    Node* newNode = new Node; // f(1)
    newNode->data = input; // make newNode and then fill with data // f(1)
    newNode->nextPtr = nullptr; // f(1)
    currPtr = headPtr->nextPtr; // f(1)
    trailPtr = headPtr->nextPtr; // f(1)
    // while loop will allow trailPtr to follow behind currPtr by one element
    // will traverse entire list
    while(currPtr != nullptr){ // f(n)
        trailPtr = currPtr;
        currPtr = currPtr->nextPtr;
    } // end while
    // point very last node to the newly allocated node
    trailPtr->nextPtr = newNode; // f(1)
    // increment size
    size++; // increment size // f(1)
    return true;
} // end insertAtBack
/*********************************************************************
 ** FUNCTION: deleteAtFront
 ** DESCRIPTION: deletes first node of list
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: list updated
 ** RETURNS: bool
 *********************************************************************/
bool LinkedList::deleteAtFront(){
    // immediately check if list is empty, this will check to see if there are any elements
    // to remove in the first place
    if(size == 0){ // f(1)
        cout << "There are no elements in this list to delete!" << endl; // f(1)
        return false; // f(1)
    } // end if
    Node* currPtr = nullptr; // f(1)
    Node* delPtr = new Node; // f(1)
    delPtr = headPtr->nextPtr; // element you want to get rid of which is very first element
    currPtr = headPtr->nextPtr; // currPtr also points to first element
    currPtr = currPtr->nextPtr; // traverse list by one so that currPtr is now pointing to second element
                                // or null
    headPtr->nextPtr = currPtr; // make headPtr point to second element rather than first
    delPtr->nextPtr = nullptr; // disconnect delPtr from list
    delete delPtr; // delete delPtr data
    size--; // decrement size
    
    return true;
} // end deleteAtFront
/*********************************************************************
 ** FUNCTION: deleteBeforePosition
 ** DESCRIPTION: deletes node before index
 ** PARAMETERS: int index
 ** PRE-CONDITIONS: list should have nodes
 ** POST-CONDITIONS: list updated
 ** RETURNS: bool
 *********************************************************************/
bool LinkedList::deleteBeforePosition(int index){
    // if index is greater than list size, then we know for sure that the index does
    // not exist within this list
    if(index > size || index <= 0){ // f(1)
        cout << "Index " << index << " does not exist in this list" << endl;
        return false;
    } // end if
    Node* currPtr = nullptr;
    Node* trailPtr = nullptr;
    Node* delPtr = new Node;
    delPtr->nextPtr = nullptr; // will point to node that we want to delete

    currPtr = headPtr;
    trailPtr = headPtr;
    int count = 0; // count starts at 1 because currPtr and trailPtr initially point to headPtr
    // loop continues to traverse list until entire list has been traversed or
    // until count has iterated up until 1 position before index
    while(currPtr != nullptr && count < index-1){ // f(n)
        trailPtr = currPtr;
        currPtr = currPtr->nextPtr;
        count++;
    } // end while
    delPtr = currPtr; // delPtr now points to node that is right before index passed in
    trailPtr->nextPtr = currPtr->nextPtr; //trailPtr makes sure that it is connected to
    // node currPtr is pointing to to make sure list remains in tact
    delPtr = nullptr; // disconnect delPtr from list
    delete delPtr; // delete delPtr memory
    size--; // decrement size
    
    return true;
} // end deleteBeforePosition
/*********************************************************************
 ** FUNCTION: deleteAtBack
 ** DESCRIPTION: deletes last element in list
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: list updated
 ** RETURNS: bool
 *********************************************************************/
bool LinkedList::deleteAtBack(){
    // if list is empty, we know that there are no elements to delete
    if(size == 0){  // f(1)
        cout << "There are no elements in this list to delete!" << endl;
        return false;
    } // end if
    Node* currPtr = nullptr; // f(1)
    Node* trailPtr = nullptr;
    Node* delPtr = new Node;

    currPtr = headPtr->nextPtr;
    trailPtr = headPtr->nextPtr;
    // traverse the entire list
    while(currPtr->nextPtr != nullptr){  // f(n)
        trailPtr = currPtr;
        currPtr = currPtr->nextPtr;
    } // end while
    delPtr = currPtr; // delPtr now pointing to last element
    delPtr = nullptr; // disconnect delPtr from list
    delete delPtr; // delete memory from last element
    trailPtr->nextPtr = nullptr; // trailPtr now points to nothing as it is now the last element
    size--; // decrement size

    return true;
} // end deleteAtBack
/*********************************************************************
 ** FUNCTION: contains
 ** DESCRIPTION: checks to see if list contains value passed in
 ** PARAMETERS: char value
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool LinkedList::contains(char value){
    Node* currPtr = headPtr;
    // traverse list until either entire list has been traversed
    // or value passed in is equal to data within any node
    while(currPtr != nullptr){ // f(n)
        // will only be true if the value passed in is equal to the currPtr data
        if(value == currPtr->data){ // f(1)
            return true;
        } // end if
        currPtr = currPtr->nextPtr;
    } // end while
    return false; // false if list does not have value
} // end contains

int LinkedList::getSize() const{
    return size;  // f(1)
} // end getSize
/*********************************************************************
 ** FUNCTION: operator+
 ** DESCRIPTION: union of two lists
 ** PARAMETERS: LinkedList list
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: LinkedList unionList
 *********************************************************************/
LinkedList LinkedList::operator+(LinkedList list){
 
    LinkedList unionList;
    Node* currPtr = headPtr->nextPtr;
    Node* listPtr = list.headPtr->nextPtr;
    
    // load unionList with elements of calling list
    while(currPtr != nullptr){ // f(n)
        unionList.insertAtFront(currPtr->data);
        currPtr = currPtr->nextPtr;
    } // end while
    // load unionList with elements of passed in list
    while(listPtr != nullptr){  // f(n)
        unionList.insertAtFront(listPtr->data);
        listPtr = listPtr->nextPtr;
    } // end while
   
    return unionList;
} // end operator+
/*********************************************************************
 ** FUNCTION: deleteAtValue
 ** DESCRIPTION: delete node of list based on data value
 ** PARAMETERS: char value
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: list updated
 ** RETURNS: bool
 *********************************************************************/
bool LinkedList::deleteAtValue(char value){
    Node* currPtr = headPtr->nextPtr;
    Node* trailPtr = headPtr;
    // traverse entire list unless value passed in matches
    // data in currPtr which will then return true and also
    // delete value from list
    while(currPtr != nullptr){  // f(n)
        // if value is equal to currPtr data
        if(value == currPtr->data){ // f(1)
            trailPtr->nextPtr = currPtr->nextPtr; // trailPtr now will point to element after currPtr
            currPtr->nextPtr = nullptr; // disconnect currPtr from list
            delete currPtr; // delete currPtr data
            return true;
        } // end if
        // traverse list
        trailPtr = currPtr;
        currPtr = currPtr->nextPtr;
    } // end while
    return false;
} // end deleteAtValue
/*********************************************************************
 ** FUNCTION: operator-
 ** DESCRIPTION: difference operator for two lists
 ** PARAMETERS: LinkedList list
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: LinkedList differenceList
 *********************************************************************/
LinkedList LinkedList::operator-(LinkedList list){
    LinkedList differenceList;
    Node* listCurrPtr = list.headPtr->nextPtr;
    // go through all elements of passed in list
    // remove all elements of calling list that are
    // in the passed in list
    while(listCurrPtr != nullptr){ // f(n)
        // if calling list contains data from
        // passed in list, then remove value from
        // calling list
        if(contains(listCurrPtr->data)){ // f(1)
            deleteAtValue(listCurrPtr->data);
        } // end if
        // traverse passed in list
        listCurrPtr = listCurrPtr->nextPtr;
    } // end while
    Node* currPtr = headPtr->nextPtr;
    // traverse entire calling list
    // load differenceList with values from calling list
    while(currPtr != nullptr){ // f(n)
        differenceList.insertAtFront(currPtr->data);
        currPtr = currPtr->nextPtr; // traverse to next element
    } // end while
    return differenceList;
} // end operator-
/*********************************************************************
 ** FUNCTION: operator=
 ** DESCRIPTION: overloaded assignment operator for two lists
 ** PARAMETERS: LinkedList list
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void LinkedList::operator=(LinkedList list){
    Node* currPtr = nullptr;
    currPtr = list.headPtr->nextPtr;
    // traverse passed in list
    // load calling list with all values of passed in list
    while(currPtr != nullptr){ // f(n)
        insertAtFront(currPtr->data);
        currPtr = currPtr->nextPtr; // traverse to next element
    } // end while
} // end operator=
/*********************************************************************
 ** FUNCTION: printList
 ** DESCRIPTION: prints out contents of calling list
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void LinkedList::printList(){
    Node* currPtr = nullptr;
    currPtr = headPtr->nextPtr;// points to first element
    int count = 0;
    // traverse entire list
    // print out every element
    while(currPtr != nullptr){ // f(n)
        cout << count + 1 << ": " << currPtr->data << endl;
        currPtr = currPtr->nextPtr;
        count++;
    } // end while
} // end printList
/*********************************************************************
 ** FUNCTION: operator <<
 ** DESCRIPTION: overloaded stream operator
 ** PARAMETERS: ostream& out, LinkedList list
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: ostream&
 *********************************************************************/
ostream& operator << (ostream& out, LinkedList list){
    Node *ptr = list.headPtr->nextPtr;
    cout << "headPtr->";
    while (ptr != nullptr)
    {
        if (ptr->nextPtr == nullptr)
            out << ptr->data << "->nullptr\n"; // end if
        else
            out << ptr->data << "->"; // end else
        ptr = ptr->nextPtr;
    } // end while
    return out;
} // end operator <<

















