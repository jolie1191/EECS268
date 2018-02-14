#include <iostream>
#include "Evaluator.h"
using namespace std;

int main() {
  Evaluator evaluator;
  string postfix;

  while (true) {

    // Prompt to enter a string
    cout << "Enter a string: ";
    getline(cin, postfix);

    if (postfix == "#") {
      // Exit
      break;
    }
    try {
      // Phase 1:  Display infix exp
      cout << "This is a valid string: " << evaluator.post2in(postfix) << endl;
      cout << "This is a valid string that evaluates to :" << evaluator.evaluate(postfix) << endl;
      }
    catch (PrecondViolatedExcep exc) {
      // Display error
      cout << "This string is invalid: " << exc.what() << endl;
    }
  }
  return 0;
}
