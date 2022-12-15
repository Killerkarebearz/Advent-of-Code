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

string Input;
string stacks[10];
char stackChar;
  for(i = 0;i<3;i++)
  {
    
    Input = InputArray[i];
    if(Input[1].compare("1") == )

    for(int j = 0; j<=9; j++)
    {  
      stackChar = Input[4*j+1];
      cout << "Current Line: " << Input << endl;
      cout << "Current Index:" << j << "\tChar: " << Input[4*j+1] << endl;
      if(!isspace(stackChar))
        stacks[j].append(1,stackChar);
    }
  }
  for(int i = 0; i<3; i++)
    cout << stacks[i] << endl;
}