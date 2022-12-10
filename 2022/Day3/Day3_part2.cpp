// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main () {
  string line;
  ifstream myfile ("Input.txt");
  int i = 0;
  int InputSize = 0;
  int NumInc = 0;
  string InputArray[4000]; //Define globally, but redifined later
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      // Count the dataset size
      i++;
    }
    // Now that we have determined the input data size
    // We can reset the search by clearing the flag and starting over
    myfile.clear();
    myfile.seekg(0);
    //string InputArray[i];
    InputSize = i;
    i = 0;
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
      InputArray[i] = line;
      //cout << line << "CurrentLine\n";
      i++;
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
// Get a list of characters in. Split the list at the midpoint
// Find all items that are common in both halves
// Assign values a-z = 1-26; A-Z = 27-52 and sum
string Input1;
string Input2;
string Input3;
string bagFinds;
string lowerCase = "abcdefghijklmnopqrstuvwxyz";
string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int compartmentOneLength;
int numOfMatches;
int roundScore;
int finalScore = 0;
//char* end;
  for(i = 0;i<InputSize-2;i=i+3)
  {
    Input1 = InputArray[i];
    Input2 = InputArray[i+1];
    Input3 = InputArray[i+2];
    // compartmentOne = Input.substr(0,Input.length()/2);
    // compartmentTwo = Input.substr(Input.length()/2,Input.length()/2);
     cout << "Input1: " << Input1 << "\tInput2: " << Input2 << "\tInput3: "<< Input3 <<"\n";
    numOfMatches = 0; // clear the matches
    bagFinds = ""; // Clear the finds
    for(int j = 0; j<Input1.length();j++)
    {
        if( (Input2.find(Input1.at(j)) != string::npos)
        && (Input3.find(Input1.at(j)) != string::npos)
        && (bagFinds.find(Input1.at(j)) == string::npos))
        {
          cout << "Found: " << Input1.at(j) << "\n";
          //string foundChar = string(compartmentOne.at(j));
          bagFinds.append(1,Input1.at(j));
          //numOfMatches++;
          if(lowerCase.find(Input1.at(j))!= string::npos)
          {
            roundScore = Input1.at(j) - 96;
          }
          else if(upperCase.find(Input1.at(j))!= string::npos)
          {
            roundScore = Input1.at(j) - 38;
          }
          finalScore = finalScore + roundScore;
          cout << "Match is worth: " << roundScore << "\n";
          cout << "Current value of matches: " << finalScore << "\n";
        }
    }
  }
  cout << "Final Value: " << finalScore << "\n";
}
