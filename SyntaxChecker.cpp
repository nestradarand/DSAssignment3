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
