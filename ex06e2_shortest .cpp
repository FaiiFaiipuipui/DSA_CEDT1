#include <bits/stdc++.h>
using namespace std;

void Bellman_Ford(int &Node, vector <vector <int>> &edges, int &startNode, bool &haveCycle, vector <int> &currDistance) // Directed Graph
{
  vector <bool> visited(Node, false);
  vector <int> prev(Node, -1); // Ini
  currDistance[startNode] = 0;

  for (int i = 0; i < Node - 1; i++) // Calc Shortest Distance
  {
    for (auto edge : edges)
    {
      int& u = edge[0], v = edge[1], weight = edge[2];
      int distanceCandidate = currDistance[u] + weight;
      if (currDistance[v] > distanceCandidate && currDistance[u] != INT_MAX)
      {
        currDistance[v] = distanceCandidate;
        prev[v] = u;
      }
    }
  }

  for (auto edge : edges) // negative cycle detection
  {
    int& u = edge[0], v = edge[1], weight = edge[2];
    if (currDistance[v] > currDistance[u] + weight)
    {
      haveCycle = true;
      break;
    }
  }


  return;
}

int main()
{
  int N{}, E{}, S{};
  cin >> N >> E >> S;
  vector <vector <int>> edges;
  int a{}, b{}, c{};
  for (int i = 0; i < E; i++)
  {
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  vector <int> currDistance(N, INT_MAX);
  bool haveCycle{};
  Bellman_Ford(N, edges, S, haveCycle, currDistance);

  if (haveCycle)
  {
    cout << "-1" << endl;
  }
  else
  {
    for (auto member : currDistance)
    {
      cout << member << " ";
    }
    cout << endl;
  }
}