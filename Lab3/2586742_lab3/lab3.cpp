

#include <iostream>
#include <fstream>
#include "Manager.h"

// main function
int main(int argc, char *argv[]) {
  // create a ifstream using the filename
  std::ifstream fin(argv[1]);
  // create a manager
  Manager mgr(fin);
  // run the manager
  mgr.start();
  return 0;
}
