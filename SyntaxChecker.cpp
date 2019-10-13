#include "SyntaxChecker.h"
#include <iostream>
#include <string>
#include "GenStack.h"
//implementation for SyntaxChecker.h
using namespace std;

//nothing needed to initialize
SyntaxChecker::SyntaxChecker()
{

}
//deletes the stack used for analyses of delimiters
SyntaxChecker::~SyntaxChecker()
{
  delete delimiterStack;
}
//checks to see if a given character is an opening delimiter
bool SyntaxChecker::isLeftDelimiter(char letter)//works
{
  return ((letter == '{') ||
          (letter == '(')||
          (letter == '['));
}
//checks if a given character is a closing delimiter
bool SyntaxChecker::isRightDelimiter(char letter)//works
{
  return ((letter == '}') ||
          (letter == ')')||
          (letter == ']'));
}
//retutns the delimiter oppostie of what is entered
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
  else
    return '0';
}
//checks a given string for errors in delimiters
//intended to be used to scan over an entire file; keeps a running record of previous delimiters
char SyntaxChecker::checkLineForErrors(string inString)
{
  for(int i =0; i < inString.size();++i)
  {
    char current = inString[i];
    //if a delimiter is an opening delimiter push it to the stack
    if(isLeftDelimiter(current))
      delimiterStack -> push(current);
    //otherwise compare the closing delimiter to what is on the stack
    else if(isRightDelimiter(current))
    {
      char correctDelimiter =getOppositeDelimiter(current);
      //if ther is nothing to compare to, indicates an error; returns the correct delimiter
      if(delimiterStack -> isEmpty())
        return correctDelimiter;
      //if the delimiter stack is not empty and the matching delimiter is on top, we pop it from the stack and continue on
      if(delimiterStack -> peek() == correctDelimiter)
        delimiterStack -> pop();
      else
      {
        //returns what should be there if the current delimiter and what is on the stack do not match
        return getOppositeDelimiter(delimiterStack -> peek());
        break;
      }
    }
  }
  //zero returned if there is nothing wrong
  return '0';
}
//checks to see if there are any leftover items in the stack once the end of a file is reached
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
//clears the stack to be used on a new set of text
void SyntaxChecker::makeEmpty()
{
  while(!delimiterStack -> isEmpty())
    delimiterStack -> pop();
}
