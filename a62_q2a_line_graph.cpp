#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int v_node{}, e_edges{};
  cin >> v_node >> e_edges;
  set <int> edgesInfo[v_node];
  int a{}, b{};
  for (int i = 0; i < e_edges; i++)
  {
    cin >> a >> b;
    edgesInfo[a].insert(b);
    edgesInfo[b].insert(a);
  }

  // BFS with component indexing
  vector <pair <int /* component num */, int /* prev node */>> visited(v_node); // why have prev node???
  vector <int> componentSize(v_node + 1);
  int componentIndex = 1;
  for (int i = 0; i < v_node; i++)
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

  vector <int> oneEdge(componentIndex + 1);
  vector <bool> definiteFalse(componentIndex + 1);
  for (int i = 0; i < v_node; i++)
  {
    if (edgesInfo[i].size() > 2)
    {
      definiteFalse[visited.at(i).first] = true;
    }
    else if (edgesInfo[i].size() == 1)
    {
      oneEdge[visited.at(i).first /* component num */]++;
    }
  }

  int straightGraph{};
  for (int i = 1; i < componentIndex; i++)
  {
    if (!definiteFalse[i] && oneEdge[i] == 2 || componentSize[i] == 1) straightGraph++;
  }

  cout << straightGraph;
}