#include <bits/stdc++.h>
using namespace std;

int bfs(vector <vector <int>> &countries, int &Tpass, queue <pair <int, int>> &nextInfect, int &row, int &column)
{
  int infectedArea = nextInfect.size();
  int Tcurr = 0;
  while (!nextInfect.empty() && Tcurr <= Tpass)
  {
    pair <int, int> currInfectCenter = nextInfect.front();
    nextInfect.pop();
    if (currInfectCenter.first + 1 < row) if (countries.at(currInfectCenter.first + 1).at(currInfectCenter.second) == 0)
    {
      countries.at(currInfectCenter.first + 1).at(currInfectCenter.second) = 1;
      nextInfect.push(make_pair(currInfectCenter.first + 1, currInfectCenter.second));
      infectedArea++;
    }
    
    if (currInfectCenter.first - 1 > 0) if (countries.at(currInfectCenter.first - 1).at(currInfectCenter.second) == 0)
    {
      countries.at(currInfectCenter.first - 1).at(currInfectCenter.second) = 1;
      nextInfect.push(make_pair(currInfectCenter.first - 1, currInfectCenter.second));
      infectedArea++;
    }

    if (currInfectCenter.second + 1 < column) if (countries.at(currInfectCenter.first).at(currInfectCenter.second + 1) == 0)
    {
      countries.at(currInfectCenter.first).at(currInfectCenter.second + 1) = 1;
      nextInfect.push(make_pair(currInfectCenter.first, currInfectCenter.second + 1));
      infectedArea++;
    }
    
    if (currInfectCenter.second - 1 > 0) if (countries.at(currInfectCenter.first).at(currInfectCenter.second - 1) == 0)
    {
      countries.at(currInfectCenter.first).at(currInfectCenter.second - 1) = 1;
      nextInfect.push(make_pair(currInfectCenter.first, currInfectCenter.second - 1));
      infectedArea++;
    }

    Tcurr++;
  }

  return infectedArea;
}

int main()
{
  int row{}, column{}, Tpass{};
  cin >> row >> column >> Tpass;
  vector <vector <int>> countries(row);
  queue <pair <int, int>> nextInfect;
  int int_input{};
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      cin >> int_input;
      countries.at(i).push_back(int_input);
      if (int_input == 1) nextInfect.push(make_pair(i, j));
    }
  }

  int infectedArea = bfs(countries, Tpass, nextInfect, row, column);
  cout << infectedArea;
}