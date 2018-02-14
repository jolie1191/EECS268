#include "Manager.h"
#include <fstream>
/*----------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assignment: Lab4
Description: This is main class. In this class, I create a ifstream using the filename, and create manager, finally, run the manager.
Date: 2/26/2013
*/
// main function
int main(int argc, char* argv[])
{
  // create a ifstream using the filename
  std::ifstream inp(argv[1]);
  // create a manager
  Manager mgr(inp);
  // run the manager
  mgr.start();
  return 0;
}
