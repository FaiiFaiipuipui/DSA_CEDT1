#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int K{}, N{};
    cin >> N >> K;

    map <string, int> nameToScore;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        if (nameToScore.count(name) == 0) nameToScore[name] = 1;
        else nameToScore[name]++;
    }

    priority_queue <int> scoreSort;
    for (auto n : nameToScore)
    {
        scoreSort.push(n.second);
    }

    int ogSize = scoreSort.size();

    int lowestScore{};
    if (scoreSort.size() < K)
    {
        while (scoreSort.size() != 0 && scoreSort.top() != 0)
        {
            lowestScore = scoreSort.top();
            scoreSort.pop();
        }
    }
    else
    {
        while (scoreSort.top() != 0 && scoreSort.size() > ogSize - K)
        {
            lowestScore = scoreSort.top();
            scoreSort.pop();
        }
    }

    cout << lowestScore << endl;

}