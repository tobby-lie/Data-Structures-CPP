//
//CSCI 2421
//Homework 2
//September 4, 2017
//ArrayBag class prototypes

#include <vector>

using namespace std;

typedef int ItemType;

class ArrayBag
{
private:
	static const int DEFAULT_BAG_SIZE = 100;
	ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
   int itemCount;                    // current count of bag items 
   int maxItems;                     // max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
    void operator&=(const ArrayBag& bag);
    const ArrayBag operator+(const ArrayBag& bag);
    const ArrayBag operator-(const ArrayBag& bag);
    void sort();
    void printValues();
};  // end Bag


