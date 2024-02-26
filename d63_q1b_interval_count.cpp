#include <bits/stdc++.h>
using namespace std;

int main ()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n{},m{},k{};
    cin >> n >> m >> k;
    vector <int> vecInput;
    for (int i = 0; i < n; i++)
    {
        int temp{};
        cin >> temp;
        vecInput.push_back(temp);
    }

    sort(vecInput.begin(), vecInput.end());

    string ans;
    for (int i = 0; i < m; i++)
    {
        int p{};
        cin >> p;
        int lowEnd = p - k;
        int highEnd = p + k;
        auto lowEndPos_iter = lower_bound(vecInput.begin(), vecInput.end(), lowEnd);
        auto highEndPos_iter = upper_bound(vecInput.begin(), vecInput.end(), highEnd);
        int dis = highEndPos_iter - lowEndPos_iter;
        cout << dis << ' ';
    }
}