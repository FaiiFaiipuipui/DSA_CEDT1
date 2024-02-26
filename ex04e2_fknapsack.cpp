#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N{};
  double W{};
  cin >> W >> N;
  double double_Input{};
  vector <tuple <double, double, double>> itemInfos(N);
  for (int i = 0; i < N; i++) // value
  {
    cin >> double_Input;
    get<2>(itemInfos.at(i)) = double_Input;
  }

  for (int i = 0; i < N; i++) // weight
  {
    cin >> double_Input;
    get<1>(itemInfos.at(i)) = double_Input;
    get<0>(itemInfos.at(i)) = get<2>(itemInfos.at(i)) / get<1>(itemInfos.at(i));
  }

  sort(itemInfos.rbegin(), itemInfos.rend());

  int lastItemInserted{};
  while (W > 0 && lastItemInserted < N)
  {
    W -= get<1>(itemInfos.at(lastItemInserted));
    lastItemInserted++;
  }

  double valueSum{};
  if (FP_ZERO == fpclassify(W) || lastItemInserted == N)
  {
    for (int i = 0; i < lastItemInserted; i++)
    {
      valueSum += get<2>(itemInfos.at(i));
    }
    cout << fixed << setprecision(4) << valueSum;
  }
  else
  {
    for (int i = 0; i < lastItemInserted - 1; i++)
    {
      valueSum += get<2>(itemInfos.at(i));
    }
    W += get<1>(itemInfos.at(lastItemInserted - 1));
    valueSum += (W / get<1>(itemInfos.at(lastItemInserted - 1))) * get<2>(itemInfos.at(lastItemInserted - 1));
    cout << fixed << setprecision(4) << valueSum;
  }
}