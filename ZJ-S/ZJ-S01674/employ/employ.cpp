#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 1e4 + 5;
const int mod = 998244353;
typedef pair<int, int> pll;
int n, m, a[maxn], c[maxn], cnt[maxn], pre[maxn], dp[505][505][505];
int vis[maxn], ans;
void dfs(int d, int now, int w) {
    if (d == n) {
        if (w >= m) ans = (ans + 1) % mod;
        return;
    }
    if (vis[now]) return;
    vis[now] = 1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (c[i] <= d - w) dfs(d + 1, i, w);
        else if (a[d + 1] == 1) dfs(d + 1, i, w + 1);
        else if (a[d + 1] == 0) dfs(d + 1, i, w);
    }
    vis[now] = 0;
}
void one() {
    ans = 0;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    dfs(0, 0, 0);
    cout << ans % mod << endl;
}
void two() {
    if (n - cnt[0] < m) {
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans % mod * i % mod;
    }
    cout << ans % mod << endl;
}
void four() {
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0 || c[i] == 0) {
            cout << 0 << endl;
            return;
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * i % mod;
    }
    cout << ans % mod << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int Flag = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char x;
        cin >> x;
        a[i] = x - '0';
        if (a[i] != 1) Flag = 0;
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++) cnt[c[i]]++;
    pre[0] = cnt[0];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + cnt[i];
    if (n <= 18) {
        one();
        return 0;
    }
    if (m == n) {
        four();
        return 0;
    }
    if (Flag) {
        two();
        return 0;
    }
    if (n - cnt[0] < m) {
        cout << 0 << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}
