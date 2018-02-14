#include "KeyValuePair.h"

// default constructor
template<typename Key, typename Value>
KeyValuePair<Key, Value>::KeyValuePair() {
}

// constructor with key and value
template<typename Key, typename Value>
KeyValuePair<Key, Value>::KeyValuePair(Key k, Value v) {
  pairKey = k;
  pairItem = v;
}

// set key and value to the pair
template <typename Key, typename Value>
void KeyValuePair<Key, Value>::SetPair(Key k, Value v) {
  pairItem = v;
  pairKey = k;
}

// return the key of pair
template<typename Key, typename Value>
Key KeyValuePair<Key, Value>::getKey() {
  return pairKey;
}

// return the value of pair
template<typename Key, typename Value>
Value KeyValuePair<Key, Value>::getItem() {
  return pairItem;
}
