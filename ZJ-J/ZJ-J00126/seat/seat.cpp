#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    int tot = n * m;
    vector<int> a(tot + 1);
    for (int i = 1; i <= tot; i++)
    {
        cin >> a[i];
    }
    int mvalawa = a[1];
    int x = 1, y = 1;
    sort(a.begin() + 1, a.end(), [](int x, int y)
    {
        return x > y;
    });
    vector<vector<int>> ans(n + 1, vector<int>(m + 1));
    int flag = 1;
    for (int i = 1; i <= tot; i++)
    {
        if (x > n || x < 1)
        {
            if (flag == 1)
            {
                x = n;
            }
            else
            {
                x = 1;
            }
            flag = -flag;
            y++;
        }
        ans[x][y] = a[i];
        x += flag;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ans[i][j] == mvalawa)
            {
                cout << j << " " << i << endl;
                return;
            }
        }
    }
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
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