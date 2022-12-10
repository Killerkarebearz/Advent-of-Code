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
      cout << line << '\n';
      InputArray[i] = line;
      i++;
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 

int CurrentMax[InputSize] ={0};
int calories = 0;
int Elf = 0;
  for(i = 0;i<InputSize;i++)
  {
    if(!InputArray[i].empty())
    {
        calories = calories + stoi(InputArray[i]);
    }
    else
    {
        CurrentMax[Elf] = calories;
        Elf++;
        calories = 0;
    }
  }
  int n = sizeof(CurrentMax) / sizeof(CurrentMax[0]);
  sort(CurrentMax, CurrentMax + n,greater<int>());
  int sum = CurrentMax[0] + CurrentMax[1] + CurrentMax[2];
  cout << "Final Count: " << "\n";
  cout << CurrentMax[0] << "\n";
  cout << CurrentMax[1] << "\n";
  cout << CurrentMax[2] << "\n";
  cout << sum << "\n";
  return 0;
}
