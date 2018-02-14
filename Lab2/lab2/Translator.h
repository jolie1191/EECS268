/*------------------------------------------------------------------------------
Filename: Translator.h
Name: Jiahui Wang
KUID: 2586742
Assignment: EECS 268 Lab02
Description: It is Translator class. it could store two keyValuePairs.
It could translate the message coming from the input file and then display
 the message to the screen.
Date: 02/11/2013
--------------------------------------------------------------------------------*/



#ifndef _TRANSLATOR_H_
#define _TRANSLATOR_H_

#include "TranslationTable.cpp"
#include <string>
#include <iostream>

class Translator {
private:
  // a TranslationTable to translate string to int
  TranslationTable <std::string, int>* T1;
  // a TranslationTable to translate int to string
  TranslationTable<int, std::string>* T2;

  // a method to translate the msg coming from the input file.
  void translateMsg(std::istream& is);

public:
  // a constructor to load TranslationTables coming from the input file
  Translator(std::istream& is);
  // destructor
  ~Translator();
};

#endif
