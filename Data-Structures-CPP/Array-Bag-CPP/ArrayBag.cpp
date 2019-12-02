#include <iostream>
#include "ArrayBag.h"

ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)
   {
      if (items[searchIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      searchIndex++;
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains



std::vector<ItemType> ArrayBag::toVector() const
{
    std::vector<ItemType> ArrayBagContents;
	for (int i = 0; i < itemCount; i++)
                ArrayBagContents.push_back(items[i]);
   return ArrayBagContents;
}  // end toVector

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the ArrayBag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

/*********************************************************************
 ** FUNCTION: +
 ** DESCRIPTION: overloaded + operator, will add contents of two 
 ** ArrayBag objects together and get rid of duplicate items in this set
 ** PARAMETERS:  constant ArrayBag object
 ** PRE-CONDITIONS: object passed in should have values
 ** POST-CONDITIONS: ArrayBag object updated with contents of two
 ** ArrayBag objects
 ** RETURNS: ArrayBag object
 *********************************************************************/
const ArrayBag ArrayBag::operator+(const ArrayBag& bag){
    // add all items into newBag
    // items from both calling and passed
    // in bag
    ArrayBag newBag;
    for(int i = 0; i < itemCount; i++){
        newBag.add(items[i]);
    }
    for(int i = 0; i < bag.getCurrentSize(); i++){
        newBag.add(bag.items[i]);
    }
    //sort newBag
    newBag.sort();
    // get rid of duplicates
    ArrayBag resultBag;
    for(int i = 0; i < newBag.getCurrentSize(); i++){
        // loop will go through all elements in sortBag
        // if resultBag already contains element from sortBag
        // then move on to next iteration, otherwise
        // add the element from sortBag into resultBag
        if(resultBag.contains(newBag.items[i])){
            continue;
        } // end if
        resultBag.add(newBag.items[i]);
    }
    return resultBag;
} // end operator+

/*********************************************************************
 ** FUNCTION: -
 ** DESCRIPTION: overloaded - operator, will remove contents of one
 ** ArrayBag object from another ArrayBag object
 ** PARAMETERS:  constant ArrayBag object
 ** PRE-CONDITIONS: object passed in should have values
 ** POST-CONDITIONS: ArrayBag object updated
 ** ArrayBag objects
 ** RETURNS: ArrayBag object
 *********************************************************************/
const ArrayBag ArrayBag::operator-(const ArrayBag& bag){
    // if calling bag contains data from
    // bag passed in then remove that value
    // at position i from calling bag
    for(int i = 0; i < bag.getCurrentSize(); i++){
        // loop will go through all elements
        // in bag, if calling bag contains element
        // from bag then remove that element from
        // calling bag
        if(contains(bag.items[i])){
            remove(bag.items[i]);
        } // end if
    }
    // put items from newly subtracted
    // calling bag into a newBag for ease
    // of sort
    ArrayBag newBag;
    for(int i = 0; i < getCurrentSize(); i++){
        newBag.add(items[i]);
    }
    // sort newBag
    newBag.sort();
    // end sort
    
    // get rid of duplicates
    ArrayBag resultBag;
    for(int i = 0; i < newBag.getCurrentSize(); i++){
        // loop will go through all elements in sortBag
        // if resultBag already contains element from sortBag
        // then move on to next iteration, otherwise
        // add the element from sortBag into resultBag
        if(resultBag.contains(newBag.items[i])){
            continue;
        } // end if
        resultBag.add(newBag.items[i]);
    }
    return resultBag;
} // end operator-

/*********************************************************************
 ** FUNCTION: =
 ** DESCRIPTION: overloaded = operator, will initialize an ArrayBag
 ** object with the values of ArrayBag object passed in
 ** PARAMETERS:  constant ArrayBag object
 ** PRE-CONDITIONS: object passed in should have values
 ** POST-CONDITIONS: ArrayBag object updated with contents passed in
 ** ArrayBag object
 ** RETURNS: ArrayBag object
 *********************************************************************/
void ArrayBag::operator&=(const ArrayBag& bag){
    // loop goes through all elements of bag
    // the current bag will initialize all
    // values of items to all items in bag
    for(int i = 0; i < bag.getCurrentSize(); i++){
        items[i] = bag.items[i];
    }
} // end operator=

/*********************************************************************
 ** FUNCTION: sort
 ** DESCRIPTION: sorts calling ArrayBag object
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: object passed in should have values
 ** POST-CONDITIONS: ArrayBag object sorted
 ** RETURNS: nothing
 *********************************************************************/
void ArrayBag::sort(){
    bool swap;
    int temp;
    int size = getCurrentSize();
    do{
        swap = false;
        for(int i = 0; i < (size - 1); i++){
            if(items[i] > items[i+1]){
                temp = items[i];
                items[i] = items[i+1];
                items[i+1] = temp;
                swap = true;
            } // end if
        }
    }while(swap); // end do while
} // end sort

/*********************************************************************
 ** FUNCTION: printValues
 ** DESCRIPTION: prints all values of calling object
 ** PARAMETERS:  none
 ** PRE-CONDITIONS: object calling should have values
 ** POST-CONDITIONS: none
 ** RETURNS: nothing
 *********************************************************************/
void ArrayBag::printValues(){
    
    for(int i = 0; i < getCurrentSize(); i++){
        
        cout << items[i] << " ";
        
    }
    cout << endl;
    
}











