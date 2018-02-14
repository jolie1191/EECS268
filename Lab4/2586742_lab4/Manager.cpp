/*---------------------------------------------------
Name: Jiahui Wang
KUID: 2586742
Assignment: Lab4
Description: This is Manager class.It contains its constructor and starting the process method. Moreover, the loop in this class is used for removing items one by one from the bag and printing on screen when bag is empty.
-----------------------------------------------------*/

#include "Manager.h"

// constructor
Manager::Manager(std::istream& inp)
{
  std::string item;
  while (!inp.eof())
  {
    inp >> item;
    bag.add(item);
  }
} // end Manager

// destructor
Manager::~Manager()
{
} // end ~Manager

// start the process
void Manager::start()
{
  // prompt the user to enter an item
  std::cout << "Enter an item to be gathered: ";
  std::string item;
  std::cin >> item;

  // gather the item entered
  bag.gather(item);

  // loop using retrieve to remove items one by one from the Bag
  // printing them to the screen until the Bag is empty.
  while (bag.getCurrentSize() > 0)
  {
    if (bag.retrieve(item))
      std::cout << "I got " << item << std::endl;
    else
      std::cout << "The bag was empty!" << std::endl;
  } // end while


// try to retrieve from an empty bag
  if (bag.retrieve(item))
    std::cout << "I got " << item << std::endl;
  else
    std::cout << "The bag was empty!" << std::endl;
 

} // end start
