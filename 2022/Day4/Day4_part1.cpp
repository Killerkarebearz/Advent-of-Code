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

int matches = 0;
string Input;
int searchStartIndex = 0;
size_t foundPos;
int oneStart;
int oneEnd;
int twoStart;
int twoEnd;
  for(i = 0;i<InputSize;i++)
  {
    /* === String Parsing === */
    foundPos = 0;
    searchStartIndex = 0;
    Input = InputArray[i];
    // I should really learn regex... for now just manually substring what I need
    foundPos = Input.find("-");
    if (foundPos!=std::string::npos)
      {
      oneStart = stoi(Input.substr(searchStartIndex,foundPos - searchStartIndex));
      searchStartIndex = foundPos+1; 
      }
    foundPos = Input.find(",",searchStartIndex);
    if (foundPos!=std::string::npos)
      {
      oneEnd = stoi(Input.substr(searchStartIndex,foundPos - searchStartIndex));
      searchStartIndex = foundPos+1; 
      }
    foundPos = Input.find("-",searchStartIndex);
    if (foundPos!=std::string::npos)
      {
      twoStart = stoi(Input.substr(searchStartIndex,foundPos - searchStartIndex));
      searchStartIndex = foundPos+1; 
      }
    twoEnd = stoi(Input.substr(searchStartIndex)); // we trust that this is end of line
    cout << "oneStart: " << oneStart << "\toneEnd: " << oneEnd << "\t";
    cout << "twoStart: " << twoStart << "\ttwoEnd: " << twoEnd << endl;

    /* === Determine Full Overlaps ===*/
    // First Range Fully Overlaps the Second //
    if(oneStart <= twoStart && oneEnd >= twoEnd)
      {  
      matches++;
      cout << "First Pair Overlap, running total: " << matches << endl;
      }
    //If the first pair overlapped, no need to check the reverse
    else if(twoStart <= oneStart && twoEnd >= oneEnd) 
      {
      matches++;
      cout << "Second Pair Overlap, running total: " << matches  << endl;
      }
  }
  cout << "Final Number of overlaps: " << matches << endl;
}