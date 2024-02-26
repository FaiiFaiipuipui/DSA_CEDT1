#include <bits/stdc++.h>
using namespace std;

void Bell_Ford(int &N, vector <vector <float>> &currencyConversionMatrix)
{
  vector <float> currDistance(N, FLT_MAX);
  vector <int> prev(N, -1);

  currDistance[0 /* source */] = 0;
  for (int iteration = 0; iteration < N; iteration++)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (currDistance[j] > currDistance[i] + currencyConversionMatrix[i][j])
        {
          currDistance[j] = currDistance[i] + currencyConversionMatrix[i][j];
          prev[j] = i;
        }
      }
    }
  }

  bool haveCycle{};
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (currDistance[j] > currDistance[i] + currencyConversionMatrix[i][j])
      {
        haveCycle = true;
      }
    }
  }

  if (haveCycle)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}

int main()
{
  int K{}, N{};
  float float_input{};
  cin >> K;
  for (int i0 = 0; i0 < K; i0++)
  {
    cin >> N;
    vector <vector <float>> currencyConversionMatrix(N, vector <float> (N));
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> float_input;
        currencyConversionMatrix[i][j] = -log10f(float_input);
      }
    }

  Bell_Ford(N, currencyConversionMatrix);
  }
}