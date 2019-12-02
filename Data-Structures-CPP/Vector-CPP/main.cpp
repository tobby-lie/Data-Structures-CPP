//Tobby Lie 103385744
//CSCI 2421
//Homework 4
//September 15, 2017
//This program utilizes dynamic memory
//allocation to implement a dynamic array
//which will help to mimic the STL vector

#include <iostream>
#include "MyVector.h"

using namespace std;

int main(){
    
// will implement simple driver program for myVector to test functions
    
// use namespace HW4 once, to declare object
HW4::MyVector v;
    
// test push_back function
v.push_back(8);
cout << "value at index 0 after push_back" << endl;
cout << v[0] << endl;
v.push_back(2);
cout << "value at index 1 after push_back" << endl;
cout << v[1] << endl;
// test pop_back
v.pop_back();
// push back once more
v.push_back(6);
cout << "value at index 1 after pop_back and another push_back" << endl;
cout << v[1] << endl;
cout << endl;
// test size
cout << "size of vector: "  << v.size() << endl;
// test search
cout << "index for value of 6: " << v.search(6) << endl;
cout << "index for value of 8: " << v.search(8) << endl;
cout << endl;
// test empty
    if(v.empty() == false){
        cout << "This vector is not empty" << endl;
        cout << "and has a size of: " << v.size() << " elements" << endl;
    }
// pop_back twice to empty vector
v.pop_back();
v.pop_back();

cout << endl;
// test empty once more
    if(v.empty() == true){
        cout << "after 2 pop_backs the vector is now empty." << endl;
    }
return 0;
}




















