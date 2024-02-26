#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

vector <ull> matrixMultiplier(vector <ull> &A, vector <ull> &B)
{
  ull a{}, b{}, c{}, d{};
  a = A.at(0) * B.at(0) + A.at(1) * B.at(2);
  b = A.at(0) * B.at(1) + A.at(1) * B.at(3);
  c = A.at(2) * B.at(0) + A.at(3) * B.at(2);
  d = A.at(2) * B.at(1) + A.at(3) * B.at(3);

  return {a, b, c, d};
}

vector <ull> moduloFinder (ull power,ull &modNum, vector <ull> currMatrix, set <vector <ull>> &moduloedNum, map <vector<ull>, vector<ull>> &moduloedNum_results)
{
  vector <ull> leftDone{}, rightDone{};
  if (power > 1)
  {
    auto curr_iter = moduloedNum.find({power});
    if (curr_iter != moduloedNum.end())
    {
      return moduloedNum_results.at(*curr_iter);
    }

    leftDone = moduloFinder(power / 2, modNum, currMatrix, moduloedNum, moduloedNum_results);
    rightDone = moduloFinder(power - (power / 2), modNum, currMatrix, moduloedNum, moduloedNum_results);
    for (int i = 0; i < 4; i++)
    {
      leftDone.at(i) %= modNum;
      rightDone.at(i) %= modNum;
    }
    vector <ull> multipliedMatrix = matrixMultiplier(leftDone, rightDone);
    for (int i = 0; i < 4; i++)
    {
      multipliedMatrix.at(i) = multipliedMatrix.at(i) % modNum;
    }

    moduloedNum.insert({power});
    moduloedNum_results.insert({{power}, multipliedMatrix});

    return multipliedMatrix;
  }
  else if (power == 1)
  {
    auto curr_iter = moduloedNum.find(currMatrix);
    if (curr_iter != moduloedNum.end())
    {
      return moduloedNum_results.at(*curr_iter);
    }

    moduloedNum.insert(currMatrix);
    auto currMatrixTemp = currMatrix;

    for (int i = 0; i < 4; i++)
    {
    currMatrix.at(i) = currMatrix.at(i) % modNum;
    }
    
    moduloedNum_results.insert({currMatrixTemp, currMatrix});

    return currMatrix;
  }
  else // power == 0
  {
    return {1, 0, 0, 1};
  }
}

int main()
{
  ull n_power{}, k_mod{};
  cin >> n_power >> k_mod;
  vector <ull> matrix;
  for (int i = 0; i < 4; i++)
  {
    ull input{};
    cin >> input;
    matrix.push_back(input);
  }

  set <vector <ull>> moduloedNum;
  map <vector<ull>, vector<ull>> moduloedNum_results;

  matrix = moduloFinder(n_power, k_mod, matrix, moduloedNum, moduloedNum_results);
  for (auto member : matrix)
  {
    cout << member << " ";
  }

  return 0;
}