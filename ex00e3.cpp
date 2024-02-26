#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N{};
    cin >> N;
    unordered_set <int> A;

    for (int i = 0; i < N; i++)
    {
        long long d{};
        cin >> d;
        if (d < 1 || d > N)
        {
            cout << "NO" << endl;
            return 0;
        }

        else A.insert(d);
    }

    if (A.size() == N)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}