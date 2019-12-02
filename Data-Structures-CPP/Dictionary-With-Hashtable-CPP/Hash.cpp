//Tobby Lie
//CSCI 2421
//Homework 9
//November 5, 2017
//Hash class implementation

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "Hash.h"

using namespace std;

/*********************************************************************
 ** FUNCTION: hashStr
 ** DESCRIPTION: will return the hash of a string that represents an index
 ** PARAMETERS:  string input
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: int index
 *********************************************************************/
int Hash::hashStr(string input){
    int hash = 0;
    int index;
    int size = (int)input.length();
    for(int i = 0; i < size; i++){ // create running total for hash of each char ascii val
        hash += int(input[i]);
    } // end for
    index = hash%1373; // mod by size of table so that it produces an index
    return index;
} // end hashStr

/*********************************************************************
 ** FUNCTION: insert
 ** DESCRIPTION: insert string into hash table based on hashed index
 ** PARAMETERS:  string _word
 ** PRE-CONDITIONS: hashtable should be made
 ** POST-CONDITIONS: hashtable updated
 ** RETURNS: nothing
 *********************************************************************/
void Hash::insert(string _word){
    int index = hashStr(_word); // hash
    hashTable[index].push_back(_word); // put _word into designated indexed bucket
} // end insert

/*********************************************************************
 ** FUNCTION: readFromFile
 ** DESCRIPTION: read strings from file to be placed into hash table
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: hashtable updated
 ** RETURNS: nothing
 *********************************************************************/
void Hash::readFromFile(string fileName){
    ifstream inFile;
    inFile.open(fileName.c_str()); // open file
    if(inFile.fail()){ // error message
        cout << "Failed to open file!" << endl;
    } // end if
    string temp;
    while(!inFile.eof()){ // while not end of file
        inFile >> temp;
        temp = removeNonAlNum(temp); // remove non alnum
        temp = lowerCase(temp); // convert to lowercase
        insert(temp); // insert into hash table
    } // end while
    inFile.close(); // close file
} // end readFromFile

/*********************************************************************
 ** FUNCTION: removeNonAlNum
 ** DESCRIPTION: removes all non AlNum from string char by char
 ** PARAMETERS:  string input
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: string input updated to have only AlNum chars
 ** RETURNS: string input
 *********************************************************************/
string Hash::removeNonAlNum(string input){
    for(int i = 0; i < (int)input.size(); i++) { // go through each char in string
        if(!isalnum(input[i]) && input[i] != '\''){ // remove all alnum unless an apostrophe
            input.erase(i--,1); // starting at i-- and deleting 1 char
        } // end if
    } // end for
    return input; // return updated input
} // end removeNonAlNum

/*********************************************************************
 ** FUNCTION: numItems
 ** DESCRIPTION: return the number of items in hash table
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: hashtable can be filled or empty
 ** POST-CONDITIONS: none
 ** RETURNS: int count
 *********************************************************************/
int Hash::numItems(){
    int count = 0;
    for(int i = 0; i < 1373; i++){ // go through each bucket and accumulate size
        count += hashTable[i].size(); // size of bucket at i
    } // end for
    return count;
} // end numItems

/*********************************************************************
 ** FUNCTION: printTable
 ** DESCRIPTION: print contents of entire table
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: hash table must be filled for this specific function
 ** if an isEmpty() function were created then this would work for empty hash tables
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void Hash::printTable(){
    list<string>::iterator iter;
    for(int i = 0; i < 1373; i++){ // for each index, print contents of entire bucket out
        for(iter = hashTable[i].begin(); iter != hashTable[i].end(); iter++){ // traverse entire bucket and print each value in bucket out
            *iter = removeNonAlNum(*iter); // remove alNum
            cout << *iter << endl;
        } // end for
    } // end for
} // end printTable

/*********************************************************************
 ** FUNCTION: contains
 ** DESCRIPTION: returns bool for whether hash table contains a certain string passed in
 ** PARAMETERS:  string _word
 ** PRE-CONDITIONS: hashtable should be filled
 ** POST-CONDITIONS: none
 ** RETURNS: bool
 *********************************************************************/
bool Hash::contains(string _word){
    _word = removeNonAlNum(_word);
    _word = lowerCase(_word);
    
    int index = hashStr(_word); // hash _word
    
    list<string>::iterator iter; // for hashed bucket, see if word matches any values in that bucket
    for(iter = hashTable[index].begin(); iter != hashTable[index].end(); iter++){ // go through entire bucket
        if(*iter == _word){
            return true;
        } // end if
    } // end for
    return false;
} // end contains

/*********************************************************************
 ** FUNCTION: lowerCase
 ** DESCRIPTION: goes through each char in string and converts to lowercase
 ** PARAMETERS:  string input
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: string input updated
 ** RETURNS: string input
 *********************************************************************/
string Hash::lowerCase(string input){
    for(int i = 0; i < input.size(); i++){ // traverse entire string
        input[i] = tolower(input[i]); // convert char to lowercase
    } // end for
    return input;
} // end lowerCase























