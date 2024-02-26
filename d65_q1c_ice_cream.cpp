#include <bits/stdc++.h>
using namespace std;
int main ()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    unsigned int n{}, m{}, start{}, x{}, P{};
    cin >> n >> m >> start;
    set <unsigned int> moneyChange_Date{0};
    map <unsigned int, unsigned int> moneyChange_Data{{0, start}};
    for (unsigned int i = 0; i < n; i++)
    {
        unsigned int changeDate{}, changeTo{};
        cin >> changeDate >> changeTo;
        moneyChange_Date.insert(changeDate);
        moneyChange_Data[changeDate] = changeTo;
    }

    for (unsigned int i = 0; i < m; i++)
    {
        cin >> P >> x;
    }
}