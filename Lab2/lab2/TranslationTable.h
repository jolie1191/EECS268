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



#ifndef _TRANSLATION_TABLE_H_
#define _TRANSLATION_TABLE_H_

#include "KeyValuePair.cpp"

template<typename Key, typename Value>
class TranslationTable {
private:
  // number of key-value-pairs
  int numPairs;
  // array of key-value-pairs
  KeyValuePair<Key, Value> *keyPairs;

public:

  // a constructor to load key-value-pairs coming from the input file
  TranslationTable(std::istream& is);

  //a destructor
  ~TranslationTable();

  // find value matches the given key
  Value getValue(Key myKey);
};


#endif

