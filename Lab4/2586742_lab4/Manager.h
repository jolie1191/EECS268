/*--------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assigment: Lab4
Description: This is Manager.h class.It contains its constructor, destructor and the istance of Manager. In this class, "LinkedBag.h" is also used.
Date: 2/26/2013
*/


#ifndef _MANAGER
#define _MANAGER

#include <iostream>
#include <string>
#include "LinkedBag.h"

class Manager
{
public:

  // constructor
  Manager(std::istream& inp);

  // destructor
  virtual ~Manager();

  // start the process
  void start();

private:
  LinkedBag<std::string> bag;
};

#include "Manager.cpp"
#endif
