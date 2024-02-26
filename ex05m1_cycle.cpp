#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T_graphsToCheck{};
  cin >> T_graphsToCheck;
  int N{}, E{};
  int a{}, b{};
  for (int i = 0; i < T_graphsToCheck; i++)
  {
    cin >> N >> E;
    set <int> EdgesPair[N];
    for (int j = 0; j < E; j++)
    {
      cin >> a >> b;
      EdgesPair[a].insert(b);
      EdgesPair[b].insert(a);
    }

    bool isACycle{};
    vector <bool> visited(N);
    vector <int> prev(N, -1);
    for (int j = 0; j < N; j++)
    {
      if (!visited[j])
      {
        visited[j] = true;
        queue <int> nodeQ;
        nodeQ.push(j);
        while (!nodeQ.empty())
        {
          int currNode = nodeQ.front();
          nodeQ.pop();
          for (auto edgesIter = EdgesPair[currNode].begin(); edgesIter != EdgesPair[currNode].end(); edgesIter++)
          {
            if (!visited[*edgesIter])
            {
              visited[*edgesIter] = true;
              nodeQ.push(*edgesIter);
              prev[*edgesIter] = currNode;
            }
            else if (prev[currNode] != *edgesIter)
            {
              isACycle = true;
              break;
            }
          }
        }
        if (isACycle) break;
      }
    }

    if (isACycle)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}