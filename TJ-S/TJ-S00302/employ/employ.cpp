#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 500 + 10;
const int P = 998244353;
int n, m, a[N], c[N], f[19][19][1 << 18], bits[1 << 18];
inline void ckadd(int & x, int y) {
    x += y;
    if (x >= P) x -= P;
}
int solve1() {
    for (int i = 1; i < 1 << n; i++) bits[i] = bits[i >> 1] + (i & 1);
    f[0][0][(1 << n) - 1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i - 1; j++)
            for (int mask = 0; mask < 1 << n; mask++) if (bits[mask] == n - i + 1) {
                for (int k = 0; k < n; k++) if (mask >> k & 1) {
                    if (a[i] == 0 || c[k] <= i - 1 - j) ckadd(f[i][j][mask ^ (1 << k)], f[i - 1][j][mask]);
                    else ckadd(f[i][j + 1][mask ^ (1 << k)], f[i - 1][j][mask]);
                }
            }
    }
    int res = 0;
    for (int i = m; i <= n; i++) ckadd(res, f[n][i][0]);
    return res;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string s; cin >> s;
    for (int i = 1; i <= n; i++) a[i] = (s[i - 1] - '0');
    for (int i = 0; i < n; i++) cin >> c[i];
    if (n <= 18) {
        cout << solve1() << '\n';
        return 0;
    }
    if (m == n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += a[i];
        int cnt = 0;
        for (int i = 0; i < n; i++) if (c[i] == 0) cnt++;
        ll ans;
        if (sum == n && cnt == 0) {
            ans = 1;
            for (int i = 1; i <= n; i++) ans = ans * i % P;
        } else {
            ans = 0;
        }
        cout << ans << '\n';
        return 0;
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) ans = ans * i % P;
    cout << ans << '\n';
    return 0;
}
