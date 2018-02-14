//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */


/*-------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assignment: Lab4
Desprition: This is LinkedBag.h class. It contain its instance of LinkedBag. Morover, it should return true when retrieve success, and call the gather method in this class.
*/
#ifndef _LINKED_BAG
#define _LINKED_BAG

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   vector<ItemType> toVector() const;





  // Retrieve an item from the list
  // Returns true if retrieve success, or false if the list is empty
  bool retrieve(ItemType& item);
  // Move the matching items to the head of the list
  void gather(const ItemType& item);

}; // end LinkedBag

#include "LinkedBag.cpp"
#endif
