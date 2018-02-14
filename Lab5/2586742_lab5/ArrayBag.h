//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Header file for an array-based implementation of the ADT bag.
 @file ArrayBag.h */

/*------------------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assignment: Lab5
Description: This is ArrayBag.h class. It contains its instances and constructors. and it also uses BagInterface.h class.
Date: 03/03/2013
-------------------------------------------------------------*/
#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 9; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
  int itemCount;                         // Current count of bag items
  int maxItems;                          // Max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
  int getIndexOf(const ItemType& target) const;
  void minMax(int firstIndex, int lastIndex, int& minI, int& maxI);

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
  bool retrieve(ItemType& item);
  void segregate();
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
