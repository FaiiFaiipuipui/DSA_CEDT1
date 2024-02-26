#include <bits/stdc++.h>
using namespace std;

void  PRIMS_MST(vector <vector <int>> &adjList, vector <pair <int, int>> &edgesWeight)
{
  vector <bool> taken(adjList.size(), false);
  vector <int> cost(adjList.size(), INT_MAX);
  vector <int> prev(adjList.size(), -1);
  set <pair <int, int>> minCost;
  minCost.insert(make_pair(0, 0));
  while (!minCost.empty())
  {
    pair <int, int> currCalc = *minCost.begin();
    int& currCost = currCalc.first;
    int& currNode = currCalc.second;
    minCost.erase(currCalc);
    taken.at(currNode) = true;
    for (auto edgesIndex = adjList.at(currNode).begin(); edgesIndex != adjList.at(currNode).end(); edgesIndex++)
    {
      if (cost.at(*edgesIndex) > currCost && taken[*edgesIndex] == false)
      {
        auto changesInfo = minCost.find(make_pair(cost.at(*edgesIndex), *edgesIndex));
        if (changesInfo != minCost.end()) minCost.erase(changesInfo);

        prev[*edgesIndex] = currNode;
        cost[*edgesIndex] = currCost;
        minCost.insert(make_pair(currCost, *edgesIndex));
      }
    }
  }
}

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

vector <pair <int, int>> KRUSKAL_MST(vector <vector <int>> &adjList, map <pair <int, int>, int> &gWeights, vector <int> &cost, vector <int> &prevNode, vector <bool> &taken, vector <int> &treeSize)
{
  vector <int> DisjointSet(adjList.size(), -1);
  vector <pair <int, int>> ansEdge;
  vector <pair <int, int>> sortedEdge;
  for (auto i = gWeights.begin(); i != gWeights.end(); i++)
  {
    sortedEdge.push_back(i->first);
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
  vector <vector <int>> adjList(N);
  vector <int> gWeights;
  vector <int> cost(N, INT_MAX);
  vector <int> prevNode(N, -1);
  vector <bool> taken(N, false);
  vector <int> treeSize(N, 1);
}