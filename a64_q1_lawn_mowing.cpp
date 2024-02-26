#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll priceCalc(vector <ll> &lawnSumPure, vector <ll> &lawnSumWithK, ll &k_PricePerArea, ll startPos, ll budget)
{
  ll endPos = startPos;
  ll pseudoBudget{};
  if (startPos != 0) pseudoBudget = lawnSumWithK[startPos - 1];
  pseudoBudget += budget;
  auto mowed_End = --(upper_bound(lawnSumWithK.begin(), lawnSumWithK.end(), pseudoBudget));
  ll mowed_End_Index = mowed_End - lawnSumWithK.begin();
  ll mowedGrassSum{};
  if (mowed_End_Index >= 0) mowedGrassSum = lawnSumPure.at(mowed_End_Index);
  if (startPos > 0) mowedGrassSum -= lawnSumPure.at(startPos - 1);
  if (mowed_End_Index >= 0) if (*mowed_End - pseudoBudget > k_PricePerArea) mowedGrassSum += *mowed_End - pseudoBudget - k_PricePerArea;

  return mowedGrassSum;
}

int main ()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n_LawnSpace{}, m_NumOfQuestion{};
  ll k_PricePerArea{};
  cin >> n_LawnSpace >> m_NumOfQuestion >> k_PricePerArea;

  vector <ll> lawnSumPure, lawnSumWithK;
  lawnSumPure.reserve(n_LawnSpace);
  lawnSumWithK.reserve(n_LawnSpace);
  ll input_int{};
  cin >> input_int;
  lawnSumPure.push_back(input_int);
  lawnSumWithK.push_back(input_int + k_PricePerArea);
  for (int i = 1; i < n_LawnSpace; i++)
  {
    cin >> input_int;
    lawnSumPure.push_back(input_int + lawnSumPure.at(i - 1));
    lawnSumWithK.push_back(input_int + lawnSumWithK.at(i - 1) + k_PricePerArea);
  }

  ll startPos{}, budget{};
  for (int i = 0; i < m_NumOfQuestion; i++)
  {
    cin >> startPos >> budget;
    cout << priceCalc(lawnSumPure, lawnSumWithK, k_PricePerArea, startPos, budget) << "\n";
  }
}