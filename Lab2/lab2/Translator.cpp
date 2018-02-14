/*------------------------------------------------------------------------------
Filename: Translator.cpp
Name: Jiahui Wang
KUID: 2586742
Assignment: EECS 268 Lab02
Description: It is Translator class. it could store two keyValuePairs.
It could translate the message coming from the input file and then display
 the message to the screen.
Date: 02/11/2013
--------------------------------------------------------------------------------*/

#include "Translator.h"

Translator::Translator(std::istream& is) {

  //create table from input file.
  T1 = new TranslationTable<std::string, int>(is);
  T2 = new TranslationTable<int, std::string>(is);
  //translate msg.
  translateMsg(is);
}

// destructor
Translator::~Translator() {
  // deallocate memory
  delete T1, T2;
}

// a method to translate the msg coming from the input file.
void Translator::translateMsg(std::istream& is) {
  //declare a string and integer variables to store.
  std::string str;
  // while not reach the end of the file
  while (!is.eof()) {
    // read a string
    is >> str;
    // translate the string by two tables and print the result
    std::cout << T2->getValue(T1->getValue(str)) << " ";
  }
  std::cout << std::endl;
}