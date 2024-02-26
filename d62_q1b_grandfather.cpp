#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    map <long long, long long> FS;
    int n{}, m{};
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        long long son{}, father{};
        cin >> father >> son;
        FS[son] = father;
    }

    for (int i = 0; i < m; i++)
    {
        long long Ag{}, Bg{};
        long long A{}, B{};
        cin >> A >> B;
        bool isLPLN = 1;
        if (A == B)
        {
            isLPLN = 0;
            cout << "NO" << endl;
            continue;
        }

        if (FS.count(A))
        {
            long long Asub1 = FS.at(A);
            if (FS.count(Asub1))
            {
                Ag = FS.at(Asub1);
            }
            else
            {
                isLPLN = 0;
            }
        }
        else
        {
            isLPLN = 0;
        }

        if (FS.count(B))
        {
            long long Bsub1 = FS.at(B);
            if (FS.count(Bsub1))
            {
                Bg = FS.at(Bsub1);
            }
            else
            {
                isLPLN = 0;
            }
        }
        else
        {
            isLPLN = 0;
        }

        if ((!isLPLN || Ag != Bg))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}