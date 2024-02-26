#include <bits/stdc++.h>
using namespace std;

void InSeSum(int currentSum, vector <int> seq, int minUsable, int N, int& howMany)
{
  if (minUsable != 0) seq.push_back(minUsable);
  currentSum += minUsable;
  if (currentSum == N)
  {
    /*for (int a : seq)
    {
      cout << a << " ";
    }
    cout << endl;*/
    howMany++;

    return;
  }

  if (currentSum < N)
  {
    for (int i = max(minUsable, 1); i <= N; i++)
    {
      if (currentSum + i > N) break;
      InSeSum(currentSum, seq, i, N, howMany);
    }
  }

  return;
}

int main ()
{
  int N{}, howMany{};
  vector <int> temp;
  cin >> N;
  InSeSum(0, temp, 0, N, howMany);
  cout << howMany << endl;
}