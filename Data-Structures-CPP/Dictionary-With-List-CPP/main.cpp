//Tobby Lie 103385744
//CSCI 2421
//Homework 6
//October 1, 2017
//This program uses
//the list STL to
//implement a dictionary class

#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "DictEntry.h"

using namespace std;

int main(){
    
    list<DictEntry> dictList;
    dictionary dict;
    
    // stream dictionary.txt into inFile
    // to store words into dictList
    ifstream inFile;
    inFile.open("dictionary.txt");
    if(inFile.fail()){ // check if file could not open
        cout << "Failed to open file!" << endl;
    } // end if
    
    string word;
    DictEntry tempDictEntry;
    // while inFile has not ended, load words into tempDictEntry
    // then push_back tempDictEntry object into dictList
    while(!inFile.eof()){
        getline(inFile, word);
        tempDictEntry.setWord(word);
        dictList.push_back(tempDictEntry);
    } // end while
    inFile.close(); // close file after usage
    // stream findwords.txt into inFile
    // store words to use for search
    inFile.open("findwords.txt");
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if

    list<DictEntry>::iterator dictIter; // iterator
    
    // print out sorted list
    dictList.sort();
    cout << "The list sorted: " << endl;
    cout << "----------------" << endl;
    for(dictIter = dictList.begin(); dictIter != dictList.end(); dictIter++){
        cout << dictIter->getWord() << endl;
    } // end for
    cout << "----------------" << endl;
    
    
    // loop for search forward and backward
    string searchWord; // holds current word to be searched for
    while(!inFile.eof()){
        getline(inFile, searchWord);
        int numSearchesForward = dict.searchForward(dictList, searchWord);
        int numSearchesBackward = dict.searchBackward(dictList, searchWord);
            // if word is not in list
            if(numSearchesForward == -1 && numSearchesBackward == -1){
                cout << searchWord << " is not a word in this list" << endl;
            } // end if
            else{
                cout << "Number of searches for " << searchWord << " starting from beginning of list: " <<  numSearchesForward << endl;
                cout << "Number of searches for " << searchWord << " starting from end of list: " << numSearchesBackward << endl;
            } // end else
    } // end while
    inFile.close(); // clse file after usage
    // used to read words into file in reverse alphabetical order
    ofstream outFile;
    outFile.open("revsorted.txt");
    dict.revPrintList(outFile, dictList);
    outFile.close();
    
return 0;
}
