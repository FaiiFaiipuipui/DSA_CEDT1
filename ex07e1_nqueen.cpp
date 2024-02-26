#include <bits/stdc++.h>
using namespace std;

bool conflict(int i1, int j1, int i2, int j2)
{
  if ((i1 == i2) || (j1 == j2)) return 1;
  if (abs(i1 - i2) == abs(j1 - j2)) return 1;

  return 0;
}

int PossibleWays(/*vector <pair <int, int>> vec*/ pair <int, int> (&vec)[12], int& n, int currRow)
{
  bool conflicted{};
  int ways{};
  currRow++;

  if (currRow == n - 1)
  {
    for (int i = currRow; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        conflicted = false;
        for (int k = 0; k < /*vec.size()*/ currRow; k++)
        {
          if (conflict(/*vec.at(k).first, vec.at(k).second,*/ vec[k].first, vec[k].second, i, j))
          {
            conflicted = true;
            break;
          }
        }

        if (conflicted) continue;
        else
        {
          ways++;
        }
      }
    }

    return ways;
  }

  for (int i = currRow; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      conflicted = false;
      for (int k = 0; k < /*vec.size()*/ currRow; k++)
      {
        if (conflict(/*vec.at(k).first, vec.at(k).second,*/ vec[k].first, vec[k].second, i, j))
        {
          conflicted = true;
          break;
        }
      }

      if (conflicted) continue;
      else
      {
        //vec.push_back({i, j});
        vec[currRow] = {i, j};
        ways += PossibleWays(vec, n, currRow);
        //vec.pop_back();
      }
    }
  }

  return ways;

}

int main ()
{
  int n{}, waysSum{};
  cin >> n;

  //vector <pair <int, int>> vec;
  pair <int, int> vec[12];
  for (int i = 0; i < n; i++) // choose first queen
  {
    {
      //vec.push_back({0, i});
      vec[0] = {0,i};
      waysSum += PossibleWays(vec, n, 0);
      //vec.pop_back();
    }
  }

  cout << waysSum << endl;
}