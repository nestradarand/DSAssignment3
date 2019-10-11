#include "SyntaxChecker.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  if(!argv[1])
  {
    cout << "No file entered. Program aborted..."<<endl;
    exit(1);
  }
  SyntaxChecker *checker = new SyntaxChecker();
  string fileName = argv[1],x;
  char response;
  ifstream inputStream;
  bool going = true;
  while(going)
  {
    bool flawed = false;
    inputStream.open(fileName);
    //ensures successful input stream established
    //reference: stack overflow
    if(!inputStream)
    {
      cout << "Error opening file..." << endl;
      exit(1);
    }
    cout << "File Successfully opened..."<<endl;
    int lineCount = 1;
    while(inputStream >> x&& !flawed)
    {
      response = checker -> checkLineForErrors(x);
      if(response != '0')
      {
        cout << "\nError found in line " << lineCount<<endl;
        cout << "Expected: " << response << endl;
        flawed = true;
      }
      lineCount ++;
    }
    //close file stream
    inputStream.close();
    if(!flawed)
    {
      if(!checker ->allDone())
      {
        char correctDelimiter = checker -> getOppositeDelimiter(checker ->getLeftover());
        cout << "\nEnd of file reached; missing: " << correctDelimiter << endl;
      }
      else
        cout << "\nNo delimiter errors found.\nDelimiter syntax correct for: "<<fileName << endl;
    }
    //used to clear out any remaining characters in the stack
    checker -> makeEmpty();
    cout << "Would you like to read in another file to check its delimiters"<<endl;
    cout << "Type 'y' to continue or 'n' to stop: ";
    cin >>response;
    response = tolower(response);
    //until y or n is entered, the user will be prompted until they answer yes or not to continuing
    while(response != 'n'&&response != 'y')
    {
      cout<< "Invalid command entered. Try again." <<endl;
      cin >> response;
    }
    if(response == 'n') //breaks the initial while loop and ends programs
      going  = false;
    else if(response  == 'y')
    {
      //prompt user for new file name to read in
      cout << "Type the name of the file you would like to use next: " <<endl;
      cin >>fileName;
    }
  }
  cout << "Program closed."<<endl;

  delete checker;
}
