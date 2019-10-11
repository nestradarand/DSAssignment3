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

  bool isLeftDelimiter(char letter);
  bool isRightDelimiter(char letter);
  char getOppositeDelimiter(char letter);
  //returns '0' if nothing wrong and otherwise returns what should have been in its place
  char checkLineForErrors(std::string inString);
  bool allDone();
  char getLeftover();
};
#endif
