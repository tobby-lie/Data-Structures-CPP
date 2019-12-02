//Tobby Lie 103385744
//CSCI 2421
//Homework 5
//September 22, 2017
//This program utilizes pointers
//and dynamic memory allcoation
//to implement a LinkedList

#include <iostream>
#include "SetFunctions.h"
#include <fstream>

using namespace std;

int main() {
    
    // driver program to test functions
   
    LinkedList list1, list2, unionlist, differenceList;
    
    ifstream inFile;
    inFile.open("setInput.txt");
    if(inFile.fail()){
        cout << "File failed to open!" << endl;
    }
    getCharFromFile(inFile, list1);
    getCharFromFile(inFile, list2);
    cout << "list 1: " << endl;
    list1.printList();
    cout << "list 2: " << endl;
    list2.printList();
    cout << endl;

    cout << "unionlist: " << endl;
    unionlist = list1 + list2;
    unionlist.printList();

    cout << "differencelist: " << endl;
    differenceList = list1 - list2;
    differenceList.printList();
    
    cout << "Inserting x at beginning of unionlist" << endl;
    unionlist.insertAtFront('x');
    unionlist.printList();
    
    cout << "Inserting x before index 10 in unionlist" << endl;
    unionlist.insertBeforePosition(10, 'x');
    unionlist.printList();
    
    cout << "Inserting x at end of unionlist" << endl;
    unionlist.insertAtBack('x');
    unionlist.printList();
    
    cout << "Deleting value at beginning of unionlist" << endl;
    unionlist.deleteAtFront();
    unionlist.printList();
    
    cout << "Deleteing value before index 9 in unionlist" << endl;
    unionlist.deleteBeforePosition(9);
    unionlist.printList();
    
    cout << "Deleting value at end of unionlist" << endl;
    unionlist.deleteAtBack();
    unionlist.printList();
    
    cout << unionlist << endl;
    
    return 0;
}


















