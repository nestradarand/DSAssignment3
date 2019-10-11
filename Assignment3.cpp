#include "GenStack.h"
#include "SyntaxChecker.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  if(!argv[1])
  {
    cout << "No file entered. Program aborted"<<endl;
    exit(1);
  }
  GenStack<char> *delimiterStack = new GenStack<char>(15);
  SyntaxChecker *checker = new SyntaxChecker();
  string fileName = argv[1],x;
  ifstream inputStream;
  string finalMessage = "No errors found.";
  while(true)
  {
    inputStream.open(fileName);
    //ensures successful input stream established
    //reference: stack overflow
    if(!inputStream)
    {
      cout << "" << endl;
      exit(1);
    }
    int lineCount = 1;
    while(inputStream >> x)
    {
      for(int i =0; i < x.size();++i)
      {
        char current = x[i];
        if(checker -> isLeftDelimiter(current))
          delimiterStack -> push(current);
        if(checker -> isRightDelimiter(current))
        {
          char correctDelimiter = checker -> getOppositeDelimiter(current);
          if(delimiterStack -> peek() == correctDelimiter)
            delimiterStack -> pop();
          else
          {
            finalMessage = ("Error found in line " + to_string(lineCount) +
                            checker -> getOppositeDelimiter(delimiterStack ->peek()) + " expected.");
            break;
          }
        }
      }
      lineCount ++;
    }
    if(!delimiterStack -> isEmpty())
    {
      cout << "End of file reached; Missing the following:" << endl;
      while(!delimiterStack -> isEmpty())
      {
        char newMissing = checker -> getOppositeDelimiter(delimiterStack -> pop());
        cout<< newMissing << endl;
        break;
      }
    }
    else
    {
      cout << finalMessage << endl;
      break;
    }
  }



  delete checker;
  delete delimiterStack;
}
