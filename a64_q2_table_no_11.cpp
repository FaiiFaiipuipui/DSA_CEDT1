#include <bits/stdc++.h>
using namespace std;

typedef unsigned long ll;

int main()
{
  ll n{};
  cin >> n;
  ll allZero_old = 1;
  ll someOne_old = 2;
  ll allZero_new = allZero_old;
  ll someOne_new = someOne_old;
  for (int i = 1; i < n; i++)
  {
    allZero_new = (allZero_old + someOne_old) % 100000007;
    someOne_new = (2 * allZero_old + someOne_old) % 100000007;
    allZero_old = allZero_new;
    someOne_old = someOne_new;
  }

  cout << (allZero_new + someOne_new) % 100000007;

}