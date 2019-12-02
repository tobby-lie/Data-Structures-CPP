//Tobby Lie
//CSCI 2421
//Homework 6
//October 1, 2017
//dictionary class implementation

#include "dictionary.h"


dictionary::dictionary(){} // needs no definition

/*********************************************************************
 ** FUNCTION: searchForward
 ** DESCRIPTION: searches for word passed in starting from beginning of list
 ** PARAMETERS:  wordList, findString
 ** PRE-CONDITIONS: wordList should be loaded
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int dictionary::searchForward(list<DictEntry> &wordList, wordType &findString){
    wordList.sort();
    list<DictEntry>::iterator listIter;
   
    int count = 0;
    for(listIter = wordList.begin(); listIter != wordList.end(); listIter++){
        count++;
        if(listIter->getWord() == findString){
            return count;
        } // end if
    } // end for
    return -1;
} // end searchForward
/*********************************************************************
 ** FUNCTION: searchBackward
 ** DESCRIPTION: searches for word passed in starting from end of list
 ** PARAMETERS:  wordList, findString
 ** PRE-CONDITIONS: wordList should be loaded
 ** POST-CONDITIONS: none
 ** RETURNS: int
 *********************************************************************/
int dictionary::searchBackward(list<DictEntry> &wordList, wordType &findString){
    wordList.sort();
    list<DictEntry>::reverse_iterator reverseListIter;
    
    int count = 0;
    for(reverseListIter = wordList.rbegin(); reverseListIter != wordList.rend(); reverseListIter++){
        count++;
        if(reverseListIter->getWord() == findString){
            return count;
        } // end if
    } // end for
    return -1;
} // end searchBackward
/*********************************************************************
 ** FUNCTION: revPrintList
 ** DESCRIPTION: sorts list and then prints out contents in reverse alphabetical order
 ** PARAMETERS:  output, wordList
 ** PRE-CONDITIONS: wordList should be loaded
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void dictionary::revPrintList(ostream &output, list<DictEntry> &wordList){
    wordList.sort();
    list<DictEntry>::reverse_iterator reverseListIter;
    
    for(reverseListIter = wordList.rbegin(); reverseListIter != wordList.rend(); reverseListIter++){
        output << reverseListIter->getWord() << " ";
    } // end for
} // end revPrintList
























