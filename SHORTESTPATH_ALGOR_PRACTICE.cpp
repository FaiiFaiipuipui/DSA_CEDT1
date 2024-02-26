#include <bits/stdc++.h>
using namespace std;

void Bellman_Ford(int &Node, vector <vector <int>> &edges, int &startNode) // Directed Graph
{
  vector <int> currDistance(Node, INT_MAX);
  vector <int> prev(Node, -1); // Ini
  currDistance[startNode] = 0;

  for (int i = 0; i < Node - 1; i++) // Calc Shortest Distance
  {
    for (auto edge : edges)
    {
      int& u = edge[0], v = edge[1], weight = edge[2];
      int distanceCandidate = currDistance[u] + weight;
      if (currDistance[v] > distanceCandidate)
      {
        currDistance[v] = distanceCandidate;
        prev[v] = u;
      }
    }
  }

  bool haveCycle{}; // negative cycle detection
  for (auto edge : edges)
  {
    int& u = edge[0], v = edge[1], weight = edge[2];
    if (currDistance[v] < currDistance[u] + weight)
    {
      haveCycle = true;
      break;
    }
  }

  return;
}

int main() {
    int Node = 5;
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int startNode = 0;

    Bellman_Ford(Node, edges, startNode);

    return 0;
}