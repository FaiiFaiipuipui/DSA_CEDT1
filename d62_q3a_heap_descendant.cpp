#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int a{}, n{};
    cin >> n >> a;
    set <int> subjects {a};
    int currentAt{}, left{}, right{};
    currentAt = a;
    while (currentAt <= n - 1)
    {
        left = 2 * currentAt + 1;
        right = 2 * currentAt + 2;
        if (left <= n - 1) subjects.insert(left);
        if (right <= n - 1) subjects.insert(right);
        else break;
        currentAt = *++subjects.find(currentAt);
    }
    cout << subjects.size() << endl;
    for (int descendentOfTheA : subjects)
    {
        cout << descendentOfTheA << " ";
    }
}