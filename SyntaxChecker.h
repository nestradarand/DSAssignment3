#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H
#include "GenStack.h"
#include "SyntaxChecker.h"

//meant to be used on one file at a time
class SyntaxChecker
{
public:
  GenStack<char> *delimiterStack = new GenStack<char>(15);
  SyntaxChecker();
  ~SyntaxChecker();

  //checks if given parameter is left delimiter or not
  bool isLeftDelimiter(char letter);
  //checks if given parameter is right delimiter or not
  bool isRightDelimiter(char letter);
  //returns opposite delimiter of whatever is passed into it
  char getOppositeDelimiter(char letter);
  //returns '0' if nothing wrong and otherwise returns what should have been in its place
  char checkLineForErrors(std::string inString);
  //checks to see if there is anything left on the stack; indicative of missing delimiter
  bool allDone();
  //returns the leftover character in the stack; throws error if empty
  char getLeftover();
  void makeEmpty();
};
#endif
