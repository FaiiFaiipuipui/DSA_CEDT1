#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n{};
  cin >> n;
  int square[n][n];
  int int_input{};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> int_input;
      square[i][j] = int_input;
    }
  }

  int rowMaxSubArrSize = 1;
  int rowMaxSubArrSum{};
  for (int index = n - 1; index > 1 /* no duplicated calculation*/ ; index--)
  {
    int currGoodSum{};
    for (int startPos = 0; startPos < rowMaxSubArrSize; startPos++)
    {
      currGoodSum = max(square[startPos][index + startPos], currGoodSum + square[startPos][index + startPos]);
      rowMaxSubArrSum = max(rowMaxSubArrSum, currGoodSum);
    }
    rowMaxSubArrSize++;
  }

  int columnMaxSubArrSize = n;
  int columnMaxSubArrSum{};
  for (int index = 0; index < n; index++)
  {
    int currGoodSum{};
    for (int startPos = 0; startPos < columnMaxSubArrSize; startPos++)
    {
        currGoodSum = max(square[index + startPos][startPos], currGoodSum + square[index + startPos][startPos]);
        columnMaxSubArrSum = max(columnMaxSubArrSum, currGoodSum);
    }
    columnMaxSubArrSize--;
  }

  cout << max(columnMaxSubArrSum, rowMaxSubArrSum);
}