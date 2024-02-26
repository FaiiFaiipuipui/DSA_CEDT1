#include <bits/stdc++.h>
using namespace std;

int main ()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n{}, m{};
    set <int> pubYear{};
    map <int, set<int>> pub{};
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int Y{}, M{};
        cin >> Y >> M;
        pubYear.insert(Y);
        pub[Y].insert(M);
    }

    //sort (pubYear.begin(), pubYear.end());
    for (int i = 0; i < m; i++)
    {
        int Y{}, M{};
        cin >> Y >> M;

        if (pubYear.find(Y) != pubYear.end()) // RIGHT
        {
            if (pub.at(Y).find(M) != pub.at(Y).end())
            {
                cout << "0 0 ";
                continue;
            }
        }

        if (Y < *pubYear.begin()) // RIGHT
        {
            cout << "-1 -1 ";
            continue;
        }

        if (Y == *pubYear.begin()) // RIGHT
        {
            if (M < *pub.at(Y).begin())
            {
                cout << "-1 -1 ";
                continue;
            }

            cout << Y << " " << *--pub.at(Y).lower_bound(M) << " ";
            continue;
        }


        auto closestYearToY = --pubYear.upper_bound(Y); // first that not > Y, so x that is <= Y

        if (*closestYearToY == Y)
        {
            if (closestYearToY == pubYear.begin())
            {
                if (M < *pub.at(Y).begin())
                {
                    cout << "-1 -1 ";
                    continue;
                }

                // if M == begin then it would have COUT

                cout << Y << " " << *--pub.at(Y).lower_bound(M) << " ";
                continue;
            }
            else
            {
                if (M > *pub.at(*closestYearToY).begin()) // START CRASH HERE, this line is to ensure that there is a possible answer for that year
                {
                cout << *closestYearToY << " " << *(--pub.at(*closestYearToY).upper_bound(M)) << " ";
                continue;
                }
            }
        }
        
        if (*closestYearToY < Y)
        {
            /*if (closestYearToY == pubYear.begin())
            {
                if (M < *pub.at(*closestYearToY).begin())
                {
                    cout << "-1 -1 ";
                    continue;
                }
                else
                {
                cout << *closestYearToY << " " << *--pub.at(*closestYearToY).lower_bound(M) << " ";
                continue;
                }
            }
            else */
            cout << *closestYearToY << " " << *(pub.at(*closestYearToY).rbegin()) << " ";
            continue;
        }
        
        closestYearToY--;

        if (closestYearToY == pubYear.begin())
        {
            if (M < *pub.at(*closestYearToY).begin())
            {
                cout << "-1 -1 ";
                continue;
            }

            cout << Y << " " << *--pub.at(*closestYearToY).lower_bound(M) << " ";
            continue;
        }
        else if (*closestYearToY > *pubYear.begin())
        {
            cout << *closestYearToY << " " << *(pub.at(*closestYearToY).rbegin()) << " ";
        }
        
    }
}