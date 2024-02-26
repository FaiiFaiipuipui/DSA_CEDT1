#include <bits/stdc++.h>
using namespace std;

void bfs(int a, vector <vector <int>> &adjList, vector <int> &friendsAtK, vector <int> distance, int &K, int &maxAtK)
{
  queue <int> q;
  q.push(a);
  distance[a] = 0;
  while (q.size() > 0)
  {
    int u = q.front();
    q.pop();
    for (auto b = adjList.at(u).begin(); b != adjList.at(u).end(); b++)
    {
      if (distance[*b] == -1)
      {
        distance[*b] = distance[u] + 1;
        if (distance[*b] <= K)
        {
          q.push(*b);
          if (distance[*b] <= K) friendsAtK[a]++;
        }
        maxAtK = max(maxAtK, friendsAtK[a]);
      }
    }
  }
}

int main()
{
  int N{}, E{}, K{};
  cin >> N >> E >> K;
  vector <vector <int>> adjList(N);
  vector <int> friendsAtK(N, 1);
  int a{}, b{};
  for (int i = 0; i < E; i++)
  {
    cin >> a >> b;
    adjList.at(a).push_back(b);
    adjList.at(b).push_back(a);
  }

  vector <int> distance(N, -1);
  int maxAtK{};
  for (int i = 0; i < N; i++)
  {
    bfs(i, adjList, friendsAtK, distance, K, maxAtK);
  }

  cout << maxAtK;
}