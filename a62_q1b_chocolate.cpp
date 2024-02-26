#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll waysToEat(ll piecesLeft, vector <ll> &piecesToEat, int &vecSize, vector <ll> &piecesMemory)
{
  if (piecesLeft < 0) return 0;
  if (piecesLeft == 0) return 1;
  if (piecesMemory[piecesLeft] != -1) return piecesMemory[piecesLeft];

  ll currSum{};
  for (int index = 0; index < vecSize; index++)
  {
    ll newPiecesLeft = piecesLeft - piecesToEat[index];
    if (newPiecesLeft > 0)
    {
      currSum += waysToEat(newPiecesLeft, piecesToEat, vecSize, piecesMemory) % 1000003;
    }
    else if (newPiecesLeft == 0)
    {
      currSum++;
    }
  }

  piecesMemory[piecesLeft] = currSum % 1000003;
  return currSum % 1000003;
}


int main()
{
  ll n{};
  int s{};
  cin >> n >> s;
  vector <ll> piecesToEat;
  vector <ll> piecesMemory(n + 1, -1);
  for (int i = 0; i < s; i++)
  {
    ll ll_input{};
    cin >> ll_input;
    piecesToEat.push_back(ll_input);
  }

  ll allWaysToEat = waysToEat(n, piecesToEat, s, piecesMemory);
  cout << allWaysToEat;
}