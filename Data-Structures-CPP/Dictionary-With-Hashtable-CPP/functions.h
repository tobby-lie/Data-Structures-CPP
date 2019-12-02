//Tobby Lie
//CSCI 2421
//Homework 9
//November 5, 2017
//spell checker program functions

#ifndef functions_h
#define functions_h

#include <string>
#include <fstream>
#include "Hash.h"

using namespace std;

/*********************************************************************
 ** FUNCTION: countNumWordsFromTxtInDict
 ** DESCRIPTION: counts number of words in given .txt file that are in dict.txt
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: int count
 *********************************************************************/
int countNumWordsFromTxtInDict(string fileName){
    Hash dictH;
    dictH.readFromFile("dict.txt"); // read dict.txt into dictH

    ifstream inFile;
    inFile.open(fileName.c_str()); // open file
    if(inFile.fail()){ // error message for opening file
        cout << "Failed to open file!" << endl;
    } // end if
    int count = 0;
    string holder;
    while(!inFile.eof()){ // while not end of file
        inFile >> holder;
        holder = dictH.removeNonAlNum(holder);
        holder = dictH.lowerCase(holder);
        if(dictH.contains(holder)){ // if dict.txt contains holder then increment counter
            count++;
        } // end if
    } // end while
    inFile.close(); // close file
    return count;
} // end countNumWordsFromTxtInDict

/*********************************************************************
 ** FUNCTION: countNumWordsNotFromTxtInDict
 ** DESCRIPTION: counts number of words in given .txt file that are not in dict.txt
 ** will also determine possible misspells
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: int count
 *********************************************************************/
int countNumWordsNotFromTxtInDict(string fileName){
    Hash dictH;
    dictH.readFromFile("dict.txt");
    
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    int count = 0;
    string holder, temp;
    while(inFile >> holder){
        temp = holder;
        temp = dictH.removeNonAlNum(temp);
        temp = dictH.lowerCase(temp);
        if(!dictH.contains(holder)){
            holder = dictH.removeNonAlNum(holder);
            cout << holder << endl;
            count++;
        } // end if
        holder = "";
    } // end while
    inFile.close();
    return count;
} // end countNumWordsNotFromTxtInDict

/*********************************************************************
 ** FUNCTION: countNumWordsInFile
 ** DESCRIPTION: returns number of words in a given file
 ** will also determine possible misspells
 ** PARAMETERS:  string fileName
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: int count
 *********************************************************************/
int countNumWordsInFile(string fileName){
    Hash h;
    h.readFromFile(fileName.c_str());
    
    return h.numItems(); // returns num items of a hash table
} // end countNumWordsInFile

/*********************************************************************
 ** FUNCTION: printReport
 ** DESCRIPTION: prints out possible misspellings, number of words in file
 ** number of words from .txt file in dict.txt and not in dict.txt
 ** PARAMETERS: none
 ** PRE-CONDITIONS: none
 ** POST-CONDITIONS: none
 ** RETURNS: none
 *********************************************************************/
void printReport(){
    Hash dictH;
    dictH.readFromFile("dict.txt");

    // report for Potter.txt
    int numDictWordsPotter = countNumWordsFromTxtInDict("Potter.txt");
    int numNotDictWordsPotter = countNumWordsNotFromTxtInDict("Potter.txt");
    int numItemsPotter = countNumWordsInFile("Potter.txt");
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "# of words from dictionary that appear in Potter.txt: " << numDictWordsPotter << endl;
    cout << "# of words from dictionary that do not appear in Potter.txt and are possible misspells: " << numNotDictWordsPotter << endl;
    cout << "# of words in Potter.txt: " << numItemsPotter << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    // report for check.txt
    int numDictWordsCheck = countNumWordsFromTxtInDict("check.txt");
    int numNotDictWordsCheck = countNumWordsNotFromTxtInDict("check.txt");
    int numItemsCheck = countNumWordsInFile("check.txt");
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "# of words from dictionary that appear in check.txt: " << numDictWordsCheck << endl;
    cout << "# of words from dictionary that do not appear in check.txt and are possible misspells: " << numNotDictWordsCheck << endl;
    cout << "# of words in check.txt: " << numItemsCheck << endl;
    cout << "-----------------------------------------------------------------------" << endl;
}

#endif /* functions_h */






















