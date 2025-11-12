#include <bits/stdc++.h>
using namespace std;
long long T, n, ans;
array<long long, 3> clubs;
vector<short> vis;
vector<array<long long, 3>> a;
void dfs(int idx)
{
    if (idx > n)
    {
        long long sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i][vis[i]];
        ans = max(ans, sum);
    }
    for (int i = 0; i < 3; i++)
    {
        if (clubs[i] < (n >> 1))
        {
            vis[idx] = i;
            ++clubs[i];
            dfs(idx + 1);
            --clubs[i];
        }
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n;
        a.resize(n + 1);
        vis.clear();
        vis.resize(n + 1);
        clubs.fill(0);
        for (int i = 1; i <= n; i++)
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}