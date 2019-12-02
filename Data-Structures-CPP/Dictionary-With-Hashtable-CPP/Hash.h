//Tobby Lie
//CSCI 2421
//Homework 9
//November 5, 2017
//Hash class prototypes

#ifndef Hash_h
#define Hash_h

#include <list>
#include <string>

using namespace std;

class Hash{
private:
    list<string> hashTable[1373]; // array of string lists
public:
    int hashStr(string input); // returns index of hash table
    void insert(string _word);
    void readFromFile(string fileName);
    string removeNonAlNum(string input);
    int numItems(); // returns number of items in table
    void printTable(); // print contents of hash table;
    bool contains(string _word);
    string lowerCase(string input);
};

#endif /* Hash_h */
