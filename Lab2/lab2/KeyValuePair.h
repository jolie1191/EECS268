/*-----------------------------------------------------------------------------
Filename: KeyValuePair.h
Name: Jiahui Wang
KUID: 2586742
Assignment: EECS 268 Lab02
Description: defrine KeyValuePair and function storing. Moreover, return the values.
Date: 02/11/2013
------------------------------------------------------------------------------*/


#ifndef _KEY_VALUE_PAIR_H_
#define _KEY_VALUE_PAIR_H_

#include <iostream>
#include <string>

template<typename Key, typename Value>
class KeyValuePair {
private:
  // key of the pair
  Key pairKey;
  // value of the pair
  Value pairItem;

public:

  // default constructor
  KeyValuePair();

  // constructor with key and value
  KeyValuePair(Key k, Value v);

  // set key and value to the pair
  void SetPair(Key k, Value v);

  // return the key of pair
  Key getKey();

  // return the value of pair
  Value getItem();

};


#endif

 

