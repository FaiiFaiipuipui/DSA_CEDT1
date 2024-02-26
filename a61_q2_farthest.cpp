 #include <bits/stdc++.h>
using namespace std;

int main()
{
  int N{}, int_input{};
  cin >> N;
  vector <vector <int>> adjMatrix(N, vector <int>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> int_input;
      adjMatrix[i][j] = int_input;
    }
  }

  // Dijkestra (Prim with Distance)
  vector <int> prev(N, -1);
  vector <int> dist(N, INT_MAX);
  vector <bool> taken(N, false);
  priority_queue <pair <int /* distance */, int /* node */>, vector < pair <int, int>>, greater<pair <int, int> > > connectible;
  connectible.push({0, 0});
  dist[0] = 0;
  while (!connectible.empty())
  {
    int currNode = connectible.top().second;
    connectible.pop();
    taken[currNode] = true;
    for (int i = 0; i < N; i++)
    {
      if (i != currNode && adjMatrix[currNode][i] != -1 && !taken[i])
      {
        if (dist[i] > dist[currNode] + adjMatrix[currNode][i] && dist[currNode] != INT_MAX)
        {
          connectible.push({dist[currNode] + adjMatrix[currNode][i], i});
          dist[i] = dist[currNode] + adjMatrix[currNode][i];
          prev[i] = currNode;
        }
      }
    }
  }

  int longestPath{};
  bool cantTravel{};
  for (int i = 0; i < N; i++)
  {
    longestPath = max(dist[i], longestPath);
    if (!taken[i])
    {
      cantTravel = true;
      break;
    }
  }
  if (cantTravel)
  {
    cout << "-1";
  }
  else
  {
    cout << longestPath;
  }
}