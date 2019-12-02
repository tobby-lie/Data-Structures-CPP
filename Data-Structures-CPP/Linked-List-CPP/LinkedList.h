//Tobby Lie
//CSCI 2421
//Homework 5
//September 22, 2017
//LinkedList class prototypes

#include <iostream>

using namespace std;

struct Node{
    char data;
    struct Node* nextPtr;
};

class LinkedList{
private:
    Node* headPtr;
    int size;
public:
    LinkedList();
    ~LinkedList();
    bool insertAtFront(char input);
    bool insertBeforePosition(int index, char input);
    bool insertAtBack(char input);
    bool deleteAtFront();
    bool deleteBeforePosition(int index);
    bool deleteAtBack();
    bool deleteAtValue(char value);
    bool contains(char value);
    int getSize() const;
    LinkedList operator+(LinkedList list);
    LinkedList operator-(LinkedList list);
    void operator=(LinkedList list);
    void printList();
    friend ostream& operator << (ostream& out, LinkedList list);
};

