#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <string>
#include "LinkedList.h"
using namespace std;

class Evaluator {
public:
  // Constructor to load number pairs
  Evaluator();

  // Convert postfix to infix
  string post2in(string postfix) throw (PrecondViolatedExcep);

  // Evaluate value of the postfix
  double evaluate(string postfix) throw (PrecondViolatedExcep);

private:
  class Entry {
  public:
    Entry(char letter);
    Entry(string exp, char op);
    Entry(string left, char op, string right);
    string exp;
    char op;
  };

  // Calculates numbers
  double calc(double left, char op, double right);

  // Inserts a (letter,number) pair to the linked list in alphabetical order.
  void insert(pair<char, double> pair);

  // Returns the number of letter
  // Returns 0 if letter not exists
  double getNumber(char c);

  // Load (letter,number) pairs pairs from the file
  void loadNumbers();

  // A linked list of (letter,number) pairs
  LinkedList<pair<char, double> > pairList;
};


#endif
