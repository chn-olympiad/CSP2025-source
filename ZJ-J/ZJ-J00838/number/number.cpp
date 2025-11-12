#include <bits/stdc++.h>
using namespace std;
string s, nums;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> s;
    for (auto X : s)
        if (isdigit(X))
            nums.push_back(X);
    sort(nums.begin(), nums.end(), greater<char>());
    cout << nums << endl;
    return 0;
}