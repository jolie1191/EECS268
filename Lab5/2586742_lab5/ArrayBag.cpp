//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */


/*------------------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assignment: Lab5
Description: This is ArrayBag class. it has its constructors and functions. If the bag is empty, return false, otherwise, set the first item and move it Second, move the largest and smallest item in the bag. Finally,recursive method which locates the indices of the elements in the Bag that have the minimum and maximum values.
Date: 03/03/2013
-------------------------------------------------------------*/
#include "ArrayBag.h"
#include <cstddef>
#include <iostream>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
  return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
  return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
  bool hasRoomToAdd = (itemCount < maxItems);
  if (hasRoomToAdd)
  {
    items[itemCount] = newEntry;
    itemCount++;
  }  // end if

  return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
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

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
  itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
  int frequency = 0;
  int curIndex = 0;       // Current array index
  while (curIndex < itemCount)
  {
    if (items[curIndex] == anEntry)
    {
      frequency++;
    }  // end if

    curIndex++;          // Increment to next entry
  }  // end while

  return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
  return getIndexOf(anEntry) > -1;
}  // end contains


template<class ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const
{
  vector<ItemType> bagContents;
  for (int i = 0; i < itemCount; i++)
    bagContents.push_back(items[i]);

  return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
  bool found = false;
  int result = -1;
  int searchIndex = 0;

  // If the bag is empty, itemCount is zero, so loop is skipped
  while (!found && (searchIndex < itemCount))
  {
    if (items[searchIndex] == target)
    {
      found = true;
      result = searchIndex;
    }
    else {
      searchIndex++;
    }  // end if
  }  // end while

  return result;
}  // end getIndexOf


/**
 * If the Bag is empty, this method simply returns false. Otherwise,
 * it retrieves an "arbitrary" item in the Bag (in our case, the first
 * item in the array), returning its data in the output item parameter.
 * It then removes it from the Bag, and returns true.
 */
template<class ItemType>
bool ArrayBag<ItemType>::retrieve(ItemType& item)
{
  if (itemCount == 0)
  {
    // if empty
    return false;
  }
  else
  {
    // set the first item and remove it
    remove(item = items[0]);
    return true;
  }
} // end retrieve

/**
 * This method will locate the largest and smallest items in the Bag, moving the
 * smallest to the first position of the array, and the largest to the end of the
 * Bag. Both moves should be done by swapping the min and max items with the items
 * currently in the indicated positions in the Bag.
 */
template<class ItemType>
void ArrayBag<ItemType>::segregate()
{
  // if the bag is not empty
  if (itemCount > 0)
  {
    // init the min index and max index to 0
    int minI = 0, maxI = 0;
    // get minIndex and maxIndex
    minMax(0, itemCount - 1, minI, maxI);
    // move the min item to first
    swap(items[minI], items[0]);
    // move the max item to last
    swap(items[maxI], items[itemCount - 1]);
  }
} // end segregate

/**
 * This method must be a recursive method that locates the indices of the elements
 * in the Bag that have the minimum and maximum values. The structure of this method
 * will resemble some (but not all!) aspects of the binary search code we studied as
 * well as the example of finding the largest element of an array discussed in section
 * 2.4.3 of the book. The implementation of minMax will not be identical to either, but
 * if you understand those two, you will be well on the way to understanding how to write
 * this method. (As a point of reference: minMax requires less than two dozen lines of code.)
 */
template<class ItemType>
void ArrayBag<ItemType>::minMax(int firstIndex, int lastIndex, int& minI, int& maxI)
{
  if (firstIndex <= lastIndex)
  {
    // mid index
    int midIndex = (firstIndex + lastIndex) >> 1;
    // update the min and max index
    if (items[minI] > items[midIndex])
      minI = midIndex;
    if (items[maxI] < items[midIndex])
      maxI = midIndex;
    // left half interval
    minMax(firstIndex, midIndex - 1, minI, maxI);
    // right half interval
    minMax(midIndex + 1, lastIndex, minI, maxI);
  }
} // end minMax
