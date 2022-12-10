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
string opponentsMove;
string myMove;
int score = 0;
int deltaScore = 0;
// Rules to the game: 
// A = Rock 1pt, B = Paper 2pt, C = Scissors 3pt
// X = Rock, Y = Paper, Z = Scissors
// Win 6 pts, Draw 3 pts, Loss 0 pts
  for(i = 0;i<InputSize;i++)
  {
    Input = InputArray[i];
    opponentsMove = Input.at(0);
    myMove = Input.at(2);
    cout << "Input:"<< opponentsMove << " Move: "<< myMove <<"\t";
    int opponentIndex;
    int myIndex;
    int scoreMatrix[3][3] = {{4,8,3},{1,5,9},{7,2,6}};
    // Y = myself, X = opponent
    // RvR(draw+1)   PvR(win+2)    SvR(loss+3)
    // RvP(loss+1)   PvP(draw+2)   SvP(win+3)
    // RvS(win+1)    PvS(loss+2)   SvS(draw+3)

    //Part 1 -------------------------
    /*if(opponentsMove == "A") {opponentIndex = 0;}
    else if(opponentsMove == "B") {opponentIndex = 1;}
    else if(opponentsMove == "C") {opponentIndex = 2;}
    if(myMove == "X") {myIndex = 0;}
    else if(myMove == "Y") {myIndex = 1;}
    else if(myMove == "Z") {myIndex = 2;}*/

    //Part 2 ----------------------
    // X means need to lose
    // Y means need to draw
    // Z means need to win
    if(opponentsMove == "A") 
    {
      opponentIndex = 0;
      if(myMove == "X") {myIndex = 2;}
      else if(myMove == "Y") {myIndex = 0;}
      else if(myMove == "Z") {myIndex = 1;}
    }
    else if(opponentsMove == "B") 
    {
      opponentIndex = 1;
      if(myMove == "X") {myIndex = 0;}
      else if(myMove == "Y") {myIndex = 1;}
      else if(myMove == "Z") {myIndex = 2;}  
    }
    else if(opponentsMove == "C") {
      opponentIndex = 2;
      if(myMove == "X") {myIndex = 1;}
      else if(myMove == "Y") {myIndex = 2;}
      else if(myMove == "Z") {myIndex = 0;}
    }
    score = score + scoreMatrix[opponentIndex][myIndex];
    cout << "RoundScore: " << scoreMatrix[opponentIndex][myIndex] << "\n";
  }
  cout << "Final Score: " << score;
}
