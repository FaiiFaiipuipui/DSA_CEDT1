#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n{};
  cin >> n;
  set <int> adjList[n];
  int a{}, b{};
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    adjList[a].insert(b);
    adjList[b].insert(a);
  }

  // DFS
  vector <int> prev(n, -1);
  vector <bool> visited(n, false);
  int cycleNode = -1;
  bool foundCycle{};
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      stack <int> nodeStack;
      nodeStack.push(i);
      visited[i] = true;
      while (!nodeStack.empty())
      {
        int currNode = nodeStack.top();
        nodeStack.pop();
        for (auto adjIter = adjList[currNode].begin(); adjIter != adjList[currNode].end(); adjIter++)
        {
          if (!visited[*adjIter])
          {
            nodeStack.push(*adjIter);
            visited[*adjIter] = true;
            prev[*adjIter] = currNode;
          }
          else if (prev[currNode] != *adjIter)
          {
            prev[*adjIter] = currNode;
            cycleNode = currNode;
            foundCycle = true;
          }
        }
        //if (foundCycle) break;
      }
    }
    //if (foundCycle) break;
  }

  int currNode = cycleNode;
  int cycleSize{};
  bool sizeDetermined{};
  while (!sizeDetermined)
  {
    currNode = prev[currNode];
    if (prev[currNode] == cycleNode)
    {
      sizeDetermined = true;
      break;
    }
    cycleSize++;
  }
  cout << cycleSize + 2;
}