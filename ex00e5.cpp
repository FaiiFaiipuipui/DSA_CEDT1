#include <bits/stdc++.h>
using namespace std;

void makeBinary(int n, vector <int> &seq)
{
  if (n == 0)
  {
    seq.push_back(0);
    return;
  }
  if (n == 1)
  {
    seq.push_back(1);
    return;
  }

  makeBinary(n / 2, seq);
  seq.push_back(n % 2);

  return;
}

bool checkSeq (vector <int> &seq, int &k)
{
  int samesame{};

  for (int i = 0; i < seq.size(); i++)
  {
    if (seq.at(i) == 1) samesame++;
    if (seq.at(i) == 0) samesame = 0;
    if (samesame == k) return true;
  }

  return false;
}

int main()
{
  int k{}, n{};
  cin >> n >> k;
  int start = pow(2, n - 1);
  int end = pow(2, n) - 1;

  for (int i = 1; i <= end; i++)
  {
    vector <int> seq;
    makeBinary(i, seq);
    while (seq.size() < n)
    {
      seq.insert(seq.begin(), 0);
    }

    if (checkSeq(seq, k))
    {
      for (int member : seq)
      {
        cout << member;
      }
      cout << endl;
    }
    seq.clear();
  }

}