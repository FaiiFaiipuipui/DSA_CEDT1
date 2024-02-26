#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int n{}, m{}, k{}, w{};
  cin >> n >> m >> k >> w;
  int p[m];
  for (int i = 0; i < m; i++)
  {
    int temp{};
    cin >> temp;
    p[i] = temp;
  }

  int h[m];
  for (int i = 0; i < m; i++)
  {
    int temp{};
    cin >> temp;
    h[i] = temp;
  }

  int t[k];
  for (int i = 0; i < k; i++)
  {
    int temp{};
    cin >> temp;
    t[i] = temp;
  }

  for (int i = 0; i < k; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (p[j] <= t[i] + w && p[j] >= t[i] - w)
      {
        if (h[j] > 0)
        {
          h[j]--;
          break;
        }
      }
    }
  }

  int sum{};
  for (int i = 0; i < m; i++)
  {
    sum += h[i];
  }
  cout << sum << endl;
}