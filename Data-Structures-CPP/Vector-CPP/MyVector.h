//Tobby Lie
//CSCI 2421
//Homework 4
//September 15, 2017
//myVector class prototypes

#ifndef MYVECTOR_
#define MYVECTOR_

namespace HW4{
    
typedef int T;
class MyVector
{
private:
    int vsize = 0;
    T* vec = nullptr;
public:
    MyVector();
    T operator[] (int index);
    void pop_back();
    void push_back(T value);
    int size(); //returns the vector size
    bool empty();//determine if is empty
    int search(T Value);
};

}//namespace HW4
#endif
