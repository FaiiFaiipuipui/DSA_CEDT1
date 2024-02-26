#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
  int districtNum{};
  cin >> districtNum;
  vector <ull> districtID(districtNum);
  ull ull_input;
  for (int i = 0; i < districtNum; i++)
  {
    cin >> ull_input;
    districtID[i] = ull_input;
  }
  map <set <int>, ull> beautyScore;
  ull maxBeautyOfZeroNode{};
  for (int i = 0; i < districtNum - 1; i++)
  {
    for (int j = i + 1; j < districtNum; j++)
    {
      beautyScore[{i, j}] = districtID[i] ^ districtID[j];
      //if (i == 0) maxBeautyOfZeroNode = max(maxBeautyOfZeroNode, districtID[i] ^ districtID[j]);
    }
  }

  // prims
  ull beautyScoreSum{};
  vector <bool> taken(districtNum);
  vector <int> prev(districtNum, -1);
  vector <ull> currBeauty(districtNum, 0);
  priority_queue<std::pair<int, int>> connectibleNode;
  connectibleNode.push({0, 0});
  while (!connectibleNode.empty())
  {
    int currNode = connectibleNode.top().second;
    connectibleNode.pop();
    taken[currNode] = true;

    for (int adjIter = 0; adjIter < districtNum; adjIter++)
    {
      if (adjIter == currNode || taken[adjIter]) continue;
      auto currBeautyScore = beautyScore.at({currNode, adjIter});
      if (currBeauty[adjIter] < currBeautyScore)
      {
        connectibleNode.push({currBeautyScore, adjIter});
        prev[adjIter] = currNode;
        currBeauty[adjIter] = currBeautyScore;
      }
    }
  }

  for (auto member : currBeauty)
  {
    beautyScoreSum += member;
  }

  cout << beautyScoreSum;
}

