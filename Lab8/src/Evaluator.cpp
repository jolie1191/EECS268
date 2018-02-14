#include <fstream>
#include <iostream>
#include <sstream>
#include "Evaluator.h"
#include "LinkedStack.h"

Evaluator::Entry::Entry(char letter) {
  ostringstream os;
  os << letter;
  exp = os.str();
  op = ' ';
}

Evaluator::Entry::Entry(string exp, char op) : exp(exp), op(op) {
}

Evaluator::Entry::Entry(string left, char op, string right) : op(op) {
  ostringstream os;
  os << left << op << right;
  exp = os.str();
}

// Constructor to load number pairs
Evaluator::Evaluator() {
  loadNumbers();
}

// Convert postfix to infix
string Evaluator::post2in(string postfix) throw (PrecondViolatedExcep) {
  // Create a stack of entries
  LinkedStack<Entry *> stack;
  // Loop for each char in the postfix
  for (int i = 0; i < postfix.size(); ++i) {
    char token = postfix[i];

    if (token == '+' || token == '-') {
      // Pop two entries from the stack
      if (stack.isEmpty())
        throw PrecondViolatedExcep("it is missing operands");
      Entry *rightEntry = stack.peek();
      stack.pop();
      if (stack.isEmpty())
        throw PrecondViolatedExcep("it is missing operands");
      Entry *leftEntry = stack.peek();
      stack.pop();

      // Push a new entry to the stack
      stack.push(new Entry(leftEntry->exp, token, rightEntry->exp));
      delete leftEntry;
      delete rightEntry;

    } else if (token == '*' || token == '/') {
      // Pop two entries from the stack
      if (stack.isEmpty())
        throw PrecondViolatedExcep("it is missing operands");
      Entry *rightEntry = stack.peek();
      stack.pop();
      if (stack.isEmpty())
        throw PrecondViolatedExcep("it is missing operands");
      Entry *leftEntry = stack.peek();
      stack.pop();

      // If the left exp has lower priority, add bracket to it
      string leftExp;
      if (leftEntry->op == '+' || leftEntry->op == '-') {
        leftExp = "(" + leftEntry->exp + ")";
      } else {
        leftExp = leftEntry->exp;
      }

      // If the right exp has lower priority, add bracket to it
      string rightExp;
      if (rightEntry->op == '+' || rightEntry->op == '-') {
        rightExp = "(" + rightEntry->exp + ")";
      } else {
        rightExp = rightEntry->exp;
      }

      // Push a new entry to the stack
      stack.push(new Entry(leftExp, token, rightExp));
      delete leftEntry;
      delete rightEntry;

    } else if (isalpha(token)) {
      // Push a letter to the stack
      stack.push(new Entry(token));

    } else {
      // Illegal character
      ostringstream os;
      os << "Illegal character: " << token;
      throw PrecondViolatedExcep(os.str());
    }
  }

  // Pop the infix exp
  string exp = stack.peek()->exp;
  stack.pop();
  // Illegal if stack is not empty
  if (!stack.isEmpty())
    throw PrecondViolatedExcep("it is missing one or more operators");
  return exp;
}

// Evaluate value of the postfix
double Evaluator::evaluate(string postfix) throw (PrecondViolatedExcep) {
  // Create a stack of double values
  LinkedStack<double> stack;

  // Loop for each char in the postfix
  for (int i = 0; i < postfix.size(); ++i) {
    char token = postfix[i];
    if (token == '+' || token == '-' || token == '*' || token == '/') {
      // If the token is an operator, pop two numbers from the stack
      if (stack.isEmpty())
        throw PrecondViolatedExcep("it is missing operands");
      double rightValue = stack.peek();
      stack.pop();
      if (stack.isEmpty())
        throw PrecondViolatedExcep("it is missing operands");
      double leftValue = stack.peek();
      stack.pop();

      // Push the result to the stack
      stack.push(calc(rightValue, token, leftValue));

    } else if (isalpha(token)) {
      // If the token is a letter,
      // find the number from the pair list and push it to the stack
      stack.push(getNumber(token));
    }
  }
  return stack.peek();
}

// Calculates numbers
double Evaluator::calc(double left, char op, double right) {
  switch(op) {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/': return left / right;
    default: return 0;
  }
}

// Inserts a (letter,number) pair to the linked list in alphabetical order.
void Evaluator::insert(pair<char, double> pair) {
  if (pairList.isEmpty()) {
    pairList.insert(1, pair);
  } else {
    for (int i = 1; i <= pairList.getLength(); i++) {
      if (pairList.getEntry(i).first > pair.first) {
        pairList.insert(i, pair);
        return;
      }
    }
    pairList.insert(pairList.getLength() + 1, pair);
  }
}

// Returns the number of letter
// Returns 0 if letter not exists
double Evaluator::getNumber(char c) {
  for (int i = 1; i <= pairList.getLength(); i++) {
    if (pairList.getEntry(i).first == c)
      return pairList.getEntry(i).second;
  }
  return 0;
}


// Load (letter,number) pairs pairs from the file
void Evaluator::loadNumbers() {
  ifstream in("numbers.txt");
  if (in.good()) {
    char c;
    double value;
    // Read from the file
    while (in >> c >> value) {
      // Insert to the linked list
      insert(make_pair(c, value));
    }

    // When you encounter the end of file, print the elements of the list
    cout << "Number list: " << endl;
    for (int i = 1; i <= pairList.getLength(); i++) {
      cout << pairList.getEntry(i).first << ": "
          << pairList.getEntry(i).second << endl;
    }
  } else {
    cerr << "Error: number.txt not found." << endl;
    exit(-1);

    }
  
}
