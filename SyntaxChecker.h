#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H
#include "GenStack.h"

class SyntaxChecker
{
public:
  GenStack<char> *delimiterStack = new GenStack<char>(15);
  SyntaxChecker();
  ~SyntaxChecker();

  bool isLeftDelimiter(char letter);
  bool isRightDelimiter(char letter);
  char getOppositeDelimiter(char letter);
};
#endif
