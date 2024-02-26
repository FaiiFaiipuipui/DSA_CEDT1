#include <bits/stdc++.h>
using namespace std;

int main ()
{
  list <int> buds;
  int N{}, K{}, V{};
  cin >> N >> K >> V;
  for (int i = 0; i < N; i++)
  {
    int value{};
    cin >> value;
    buds.push_back(value);
  }

  auto curr = buds.begin();
  for (int i = 0; i < K; i++) curr++;
  curr = buds.insert(curr, V);

  bool stillMore = true, FirstRun = true;
  while (stillMore)
  {
    int value = *curr;
    auto leftMost = curr;
    while (*prev(leftMost) == value && leftMost != buds.begin())
    {
      leftMost--;
    }

    auto rightMost = curr;
    while (*next(rightMost) == value && rightMost != buds.end())
    {
      rightMost++;
    }
    rightMost++;
    
    int duplicate = distance(leftMost, rightMost);
    if (duplicate < 3 || (leftMost == curr && !FirstRun) || leftMost == rightMost)
    {
      stillMore = false;
      break;
    }

    curr = buds.erase(leftMost, rightMost);
    FirstRun = false;

  }

  
  for (auto member : buds)
  {
    cout << member << " ";
  }
}