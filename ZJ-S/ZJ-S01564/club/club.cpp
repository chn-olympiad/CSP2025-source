#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> x, y, z, f;

void dfs(int pos, int now, int a, int b, int c) {
    if (now + f[pos] <= ans) return;
    if (pos == n) {
        ans = max(ans, now);
        return;
    }
    
    if (a < n / 2 && min(y[pos], z[pos]) <= x[pos]) 
        dfs(pos + 1, now + x[pos], a + 1, b, c);
    if (b < n / 2 && min(x[pos], z[pos]) <= y[pos]) 
        dfs(pos + 1, now + y[pos], a, b + 1, c);
    if (c < n / 2 && min(x[pos], y[pos]) <= z[pos]) 
        dfs(pos + 1, now + z[pos], a, b, c + 1);
}

void solve() {
    cin >> n;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> z[i];

    f.resize(n);
    f[n - 1] = max(x[n - 1], max(y[n - 1], z[n - 1]));
    for (int i = n - 2; i >= 0; --i)
        f[i] = f[i - 1] + max(x[i], max(y[i], z[i]));

    ans = INT_MIN;
    dfs(0, 0, 0, 0, 0);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
