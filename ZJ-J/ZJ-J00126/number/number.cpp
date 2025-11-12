#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    string s;
    cin >> s;
    vector<int> res;
    for (auto c : s)
    {
        if ('0' <= c && c <= '9')
        {
            res.push_back(c - '0');
        }
    }
    sort(res.begin(), res.end(), [](int x, int y)
    {
        return x > y;
    });
    for (auto v : res)
    {
        cout << v;
    }
    cout << endl;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    while (_--)
    {
        solve();
    }
    return 0;
}