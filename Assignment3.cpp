#include "SyntaxChecker.h"
#include <iostream>
#include <string>
#include <fstream>
//containes basic logic to run program to check delimiter syntax for a given file
//takes command line argument as parameters for file analysis
using namespace std;

int main(int argc, char** argv)
{
  //if no file path entered, program exits
  if(!argv[1])
  {
    cout << "No file path entered. Program aborted..."<<endl;
    exit(1);
  }
  // if no file name entered, prgram exits
  if(!argv[2])
  {
    cout << "No file name entered. Program aborted..."<<endl;
    exit(1);
  }
  SyntaxChecker *checker = new SyntaxChecker();//syntax checker instance
  string filePath = argv[1],fileName = argv[2],x;//stores command line arguments and later file input
  string totalFile;//compelete file name arugment to read file
  char response;//later used to store user response
  ifstream inputStream;//delceare file inputstream
  bool going = true;//used to control larger while loop
  while(going)
  {
    bool flawed = false;//changes if error found
    totalFile = filePath + "/" +fileName;
    inputStream.open(totalFile);
    //ensures successful input stream established
    //reference: stack overflow
    if(!inputStream)
    {
      cout << "Error opening file..." << endl;
      exit(1);
    }
    cout << "File Successfully opened..."<<endl;
    int lineCount = 1;//stores number of lines that have been read to inform user where error lies
    //loop runs to analyze each line of text until either file end is reached or error is found
    while(getline(inputStream,x) && !flawed)
    {
      response = checker -> checkLineForErrors(x);//checks entire line of text file for error
      //return of zero indicates not errors were found
      if(response != '0')//if error found (returns zero for no errors)
      {
        if(checker ->isLeftDelimiter(response))//if the missing delimiter was a left delimiter
        {
          cout << "Error found in line " << lineCount <<endl;
          cout << x << endl;
          cout << checker -> getOppositeDelimiter(response) << " missing opening: "<<response <<endl;
          flawed  = true;//used to indicate flaw found
        }
        else//otherwise use this to display error
        {
          cout << "\nError found in line " << lineCount<<endl;
          cout << x<< endl;
          cout << "Expected: " << response << endl;
          flawed = true;//indicative of flaw found
        }
      }
      lineCount ++;//increments line count
    }
    //close file stream
    inputStream.close();
    if(!flawed)//if no flaw found
    {
      if(!checker ->allDone())//returns if there are any closing delimiters ),],} missing from end of file
      {
        char correctDelimiter = checker -> getOppositeDelimiter(checker ->getLeftover());
        cout << "\nEnd of file reached; missing: " << correctDelimiter << endl;
      }
      else//otherwise display success message
        cout << "\nNo delimiter errors found.\nDelimiter syntax correct for: "<<fileName << endl;
    }
    //used to clear out any remaining characters in the stack, regardless of errors found
    checker -> makeEmpty();
    //prompt user if they would like to continue using the program
    cout << "Would you like to read in another file to check its delimiters?"<<endl;
    cout << "Type 'y' to continue or 'n' to stop: ";
    cin >>response;
    response = tolower(response);
    //until y or n is entered, the user will be prompted until they answer yes or no to coninue
    while(response != 'n'&&response != 'y')
    {
      cout<< "Invalid command entered. Try again." <<endl;
      cin >> response;
    }
    if(response == 'n') //breaks the initial while loop and ends programs
      going  = false;
    else if(response  == 'y')
    {
      //prompt user for new file path and name to read in
      cout << "Enter the directory of the file you would like to use next: " <<endl;
      cin >>filePath;
      cout << "Now enter the name of the file you wish to analyze: "<<endl;
      cin >>fileName;
    }
  }
  cout << "Program exited."<<endl;
  //deallocate memory used for the SyntaxChecker
  delete checker;
}
