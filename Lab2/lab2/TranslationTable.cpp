/*--------------------------------------------------------------------------
Filename: KeyValuePair.h
Name: Jiahui Wang
KUID: 2586742
Assignment: EECS 268 Lab02
Description: It is the translationTable. reading the key and values
from the input file. store them in an array. Moreover,
this also will be used in translator class.
Date: 02/11/2013
---------------------------------------------------------------------------*/

#include "TranslationTable.h"

// a constructor to load key-value-pairs coming from the input file
template<typename Key, typename Value>
TranslationTable<Key, Value>::TranslationTable(std::istream& is) {
  // read number of pairs
  is >> numPairs;
  // allocate the array of KeyValuePair
  keyPairs = new KeyValuePair<Key, Value>[numPairs];
  //declare a Key and Value variables to read
  Key key;
  Value value;
  // loop for numPairs times
  for (int i = 0; i < numPairs; ++i) {
    // read a key and a value
    is >> key >> value;
    // set them to the i-th pair in the array
    keyPairs[i].SetPair(key, value);
  }
}

//a destructor
template<typename Key, typename Value>
TranslationTable<Key, Value>::~TranslationTable() {
  // deallocate the array
  delete[] keyPairs;
}


// find value matches the given key
template<typename Key, typename Value>
Value TranslationTable<Key, Value>::getValue(Key myKey) {
  //declare a Key and Value variables to read
  Value value;
  // loop for each pair
  for (int i = 0; i < numPairs; ++i) {
    // if the i-th pair matches the key
    if (keyPairs[i].getKey() == myKey) {
      // store the value
      value = keyPairs[i].getItem();
      break;
    }
  }
  return value;
}
