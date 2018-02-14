/*------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Description: This is Manager class, which has its constructor and start(), and also used Point2DArray.h in this class.
Date: 02/20/2013
-------------------------------------------------*/


#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "Point2DArray.h"

class Manager {
public:

  // constructor
  Manager(std::istream& is);

  // destructor
  virtual ~Manager();

  // start the process
  void start();

private:
  Point2DArray *ptArray;
};
#endif
