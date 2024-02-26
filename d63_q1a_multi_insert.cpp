#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
    vector <int> vecReturn;
    for (int i = 0; i < position; i++)
    {
        vecReturn.push_back(v.at(i));
    }

    for (int i = 0; i < count; i++)
    {
        vecReturn.push_back(value);
    }

    for (int i = position; i < v.size(); i++)
    {
        vecReturn.push_back(v.at(i));
    }

    v.clear();
    for (int i = 0; i < vecReturn.size(); i++)
    {
        v.push_back(vecReturn.at(i));
    }
}
int main() {
 std::ios_base::sync_with_stdio(false);
 cin.tie(0);
 int n,value,position,count;
 cin >> n >> value >> position >> count;
 vector<int> v(n);
 for (int i = 0; i < n; i++) cin >> v[i];
 multiple_add(v,value,position,count);
 cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
 for (auto &x : v) cout << x << " ";
 cout << endl;
}
