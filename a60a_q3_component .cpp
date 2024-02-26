#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int v_node{}, e_edges{};
  cin >> v_node >> e_edges;
  set <int> edgesInfo[v_node + 1];
  int a{}, b{};
  for (int i = 0; i < e_edges; i++)
  {
    cin >> a >> b;
    edgesInfo[a].insert(b);
    edgesInfo[b].insert(a);
  }

  // BFS with component indexing
  vector <pair <int /* component num */, int /* prev node */>> visited(v_node + 1); // why have prev node???
  vector <int> componentSize(v_node + 1);
  int componentIndex = 1;
  for (int i = 0 + 1; i < v_node + 1; i++)
  {
    if (!visited[i].first)
    {
      queue <int> nodeQueue;
      nodeQueue.push(i);
      componentSize[componentIndex]++;
      visited[i] = {componentIndex, i};
      while (!nodeQueue.empty())
      {
        int currNode = nodeQueue.front();
        nodeQueue.pop();
        for (auto edgeIter = edgesInfo[currNode].begin(); edgeIter != edgesInfo[currNode].end(); edgeIter++)
        {
          if (!visited[*edgeIter].first)
          {
            visited[*edgeIter] = {componentIndex, currNode};
            componentSize[componentIndex]++;
            nodeQueue.push(*edgeIter);
          }
        }
      }
      componentIndex++;
    }
  }

  cout << componentIndex - 1;
}