#include "SyntaxChecker.h"
#include <iostream>
#include <string>
#include "GenStack.h"

using namespace std;

SyntaxChecker::SyntaxChecker()
{

}
SyntaxChecker::~SyntaxChecker()
{
  delete delimiterStack;
}
bool SyntaxChecker::isLeftDelimiter(char letter)//works
{
  return ((letter == '{') ||
          (letter == '(')||
          (letter == '['));
}
bool SyntaxChecker::isRightDelimiter(char letter)//works
{
  return ((letter == '}') ||
          (letter == ')')||
          (letter == ']'));
}
char SyntaxChecker::getOppositeDelimiter(char letter)
{
  if(letter == '{')
    return '}';
  if(letter == '(')
    return ')';
  if(letter == '[')
    return ']';
  if(letter == '}')
    return '{';
  if(letter == ']')
    return '[';
  if(letter == ')')
    return '(';
}
