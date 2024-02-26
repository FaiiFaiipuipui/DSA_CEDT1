#include <bits/stdc++.h>
using namespace std;

int KRUSKEL_FINDSET(vector <int> &DisjointSet, int node)
{
  if (DisjointSet.at(node) == -1) return node;

  // path compression
  DisjointSet.at(node) = KRUSKEL_FINDSET(DisjointSet, DisjointSet.at(node));

  return DisjointSet.at(node);
}

void KRUSKEL_UNION(vector <int> &DisjointSet, vector <int> &treeSize, int &node1, int &node2)
{
  int root1 = KRUSKEL_FINDSET(DisjointSet, node1);
  int root2 = KRUSKEL_FINDSET(DisjointSet, node2);

  if (treeSize[root1] > treeSize[root2])
  {
    DisjointSet[root2] = root1; // parent of root2 is root1
    treeSize[root1] = treeSize[root1] + treeSize[root2];
  }
  else
  {
    DisjointSet[root1] = root2;
    treeSize[root2] = treeSize[root2] + treeSize[root1];
  }
}

vector <pair <int, int>> KRUSKAL_MST(vector <vector <int>> &adjList,   set <tuple <int, int, int>> gWeights, vector <int> &treeSize)
{
  vector <int> DisjointSet(adjList.size(), -1);
  vector <pair <int, int>> ansEdge;
  vector <pair <int, int>> sortedEdge;
  for (auto i = gWeights.begin(); i != gWeights.end(); i++)
  {
    sortedEdge.push_back(make_pair(get<1>(*i), get<2>(*i)));
  }

  for (auto i = sortedEdge.begin(); i != sortedEdge.end(); i++)
  {
    if (KRUSKEL_FINDSET(DisjointSet, i->first) != KRUSKEL_FINDSET(DisjointSet, i->second))
    {
      ansEdge.push_back(*i);
      KRUSKEL_UNION(DisjointSet, treeSize, i->first, i->second);
    }
  }

  return ansEdge;
}

int main()
{
  int N{};
  cin >> N;
  vector <vector <int>> adjList(N);
  set <tuple <int, int, int>> gWeights;
  map <pair <int, int>, int> gWeightsMap;
  int intInput{};
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      cin >> intInput;
      adjList.at(i).push_back(j);
      adjList.at(j).push_back(i);
      gWeights.insert(make_tuple(intInput, i, j));
      gWeightsMap[make_pair(i, j)] = intInput;
    }
  }
  vector <int> treeSize(N, 1);
  vector <pair <int, int>> edgeAns = KRUSKAL_MST(adjList, gWeights, treeSize);
  int costSum{};
  for (auto member : edgeAns)
  {
    costSum += gWeightsMap.at(member);
  }

  cout << costSum;
}