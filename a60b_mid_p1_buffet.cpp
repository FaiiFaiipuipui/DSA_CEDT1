#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int f{}, w{}, n{};
  cin >> f >> w >> n;
  set <int> foodHere;
  int int_input{};
  for (int i = 0; i < f; i++)
  {
    cin >> int_input;
    foodHere.insert(int_input);
  }

  set <int> lightPos;
  lightPos.insert(*foodHere.begin() + w);
  int lastSpotRight = *lightPos.begin() + w;
  for (auto foodSpot = next(foodHere.begin()); foodSpot != foodHere.end(); foodSpot++)
  {
    if (*foodSpot > lastSpotRight)
    {
      lightPos.insert(*foodSpot);
      lastSpotRight = *foodSpot + 2 * w;
    }
  }

  cout << lightPos.size();
}