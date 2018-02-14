/*--------------------------------------------------------------------------
Filename: lab2.cpp
Name: Jiahui Wang
KUID: 2586742
Assignment: EECS 268 Lab02
Description: It is the entry of the program. Filename is loaded from the argument
and the translator is used to deal the file.
Date: 02/11/2013
---------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "Translator.cpp"

int main(int argc, const char *argv[]) {
  if (argc <= 1) {
    // number of argument should be larger than 1
    std::cout << "invalid arguments" << std::endl;
  } else {
    // create a input stream by the filename
    std::ifstream is(argv[1]);
    if (is.good()) {
      // if file exists, do translate
      Translator translator(is);
    } else {
      // file not exists
      std::cout << "cannot read file" << std::endl;
    }
  }
  return 0;
}
