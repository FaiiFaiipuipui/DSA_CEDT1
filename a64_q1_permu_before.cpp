#include <bits/stdc++.h>
using namespace std;

bool conflict(vector <int> &arrPos, vector <int> &arrSeq, vector <vector <int>> &permCondition, int& n, int& m)
{
  for (int i = 0; i < permCondition.size(); i++)
  {
    for (int j = 1; j < permCondition.at(i).size(); i++)
    {
      if (arrPos.at(permCondition.at(i).at(j - 1)) == n || arrPos.at(permCondition.at(i).at(j)) == n) return false; 
      if (arrPos.at(permCondition.at(i).at(j - 1)) >= arrPos.at(permCondition.at(i).at(j))) return true;
    }
  }

  return false;
}

void permutator(vector <int> arrPos, vector <int> arrSeq, int length, int &n, vector <vector <int>> &permCondition, int &ConditionNum)
{
  if (length == n)
  {
    for (int i = 0; i < n; i++)
    {
      cout << arrSeq[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (arrPos[i] == n) // if not inserted yet
    {
      arrSeq[length] = i;
      arrPos[i] = length;
      if (conflict(arrPos, arrSeq, permCondition, n, ConditionNum)) continue;
      permutator(arrPos, arrSeq, length + 1, n, permCondition, ConditionNum);
      arrPos[i] = n;
    }
  }
}


int main ()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n{}, m{};
  cin >> n;
  vector <int> arrSeq(n,n);
  vector <int> arrPos(n,n);

  cin >> m;
  vector <vector <int>> permCondition;
  for (int i = 0; i < m; i++)
  {
    int a{}, b{};
    cin >> a >> b;
    bool inserted{};
    for (int j = 0; j < permCondition.size(); j++)
    {
      for (int k = 0; k < permCondition.at(j).size(); k++)
      {
        if (permCondition.at(j).at(k) == a)
        {
          permCondition.at(j).push_back(b);
          inserted = true;
          break;
        }
        if (find(permCondition.at(j).begin(), permCondition.at(j).end(), b) != permCondition.at(j).end())
        {
          permCondition.at(j).insert(permCondition.at(j).begin(), a);
          inserted = true;
          break;
        }
      }

      if (inserted) break;
    }

    if (!inserted) permCondition.push_back({a, b});
  }


  permutator(arrPos, arrSeq, 0, n, permCondition, m);
}