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
char SyntaxChecker::checkLineForErrors(string inString)
{
  for(int i =0; i < inString.size();++i)
  {
    char current = inString[i];
    if(isLeftDelimiter(current))
      delimiterStack -> push(current);
    else if(isRightDelimiter(current))
    {
      char correctDelimiter =getOppositeDelimiter(current);
      if(delimiterStack -> isEmpty())
        return correctDelimiter;
      if(delimiterStack -> peek() == correctDelimiter)
        delimiterStack -> pop();
      else
      {
        return getOppositeDelimiter(delimiterStack -> peek());
        break;
      }
    }
  }
  return '0';
}
bool SyntaxChecker::allDone()
{
  if(!delimiterStack -> isEmpty())
    return false;
  return true;
}
//returns what is leftover if anything in the stack
char SyntaxChecker::getLeftover()
{
  if(delimiterStack -> isEmpty())
    throw runtime_error("There is nothing left in the stack. All delimiters matched");
  return delimiterStack -> pop();
}
void SyntaxChecker::makeEmpty()
{
  while(!delimiterStack -> isEmpty())
    delimiterStack -> pop();
}
