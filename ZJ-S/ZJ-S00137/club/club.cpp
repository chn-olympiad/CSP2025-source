#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

struct Node
{
    int v[3];
};

void solve()
{
    using val_t = pair<int, int>;
    int n;
    cin >> n;
    vector<array<val_t, 3>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0].first >> a[i][1].first >> a[i][2].first;
        a[i][0].second = 0, a[i][1].second = 1, a[i][2].second = 2;
        sort(a[i].begin(), a[i].end(), [](val_t x, val_t y)
        {
            return x.first > y.first;
        });
    }
    int Lim = n / 2;
    i64 ans = 0;
    int cnt[3] = {0};
    priority_queue<val_t, vector<val_t>, greater<val_t>> Q[3];
    for (int i = 1; i <= n; i++)
    {
        Q[a[i][0].second].push({a[i][0].first - a[i][1].first, i});
        ans += a[i][0].first;
    }
    for (int i = 0; i <= 2; i++)
    {
        while (Q[i].size() > Lim)
        {
            val_t top = Q[i].top();
            Q[i].pop();
            ans -= top.first;
        }
    }
    cout << ans << endl;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}