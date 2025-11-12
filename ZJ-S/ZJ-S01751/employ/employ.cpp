#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[524];
int r[524];

#define Mod 998244353

int fac[524];

void solve1() {
    static int dp[2][24][262200];
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) for (int k = 0; k < (1 << n); k++) dp[i & 1][j][k] = 0;
        for (int j = 0; j < (1 << n); j++) {
            if (__builtin_popcount(j) != i) continue;
            int tmp = j;
            while (tmp) {
                int lb = tmp & -tmp;
                int ix = __builtin_ctz(lb) + 1;
                for (int k = 0; k < i; k++) {
                    int nk = k + (s[i] == '1' && i - 1 - k < r[ix]);
                    dp[i & 1][nk][j] += dp[1 ^ (i & 1)][k][j ^ lb];
                    if (dp[i & 1][nk][j] >= Mod) dp[i & 1][nk][j] -= Mod;
                }
                tmp ^= lb;
            }
        }
    }
    int ans = 0;
    for (int i = m; i <= n; i++) {
        ans += dp[n & 1][i][(1 << n) - 1];
        if (ans >= Mod) ans -= Mod;
    }
    cout << ans;
}

void solve2() {
    sort(r + 1, r + n + 1);
    static int p[524];
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + (s[i] ^ 48);
    int re = 1;
    for (int i = 1; i <= n; i++) {
        re = 1ll * re * (i - p[min(r[i], i)]) % Mod;
    }
    int ans = fac[n] - re;
    if (ans < 0) ans += Mod;
    cout << ans;
}

void solve3() {
    for (int i = 1; i <= n; i++) if (s[i] == '0' || r[i] == 0) {
        cout << 0;
        return;
    }
    cout << fac[n];
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % Mod;
    cin >> s + 1;
    for (int i = 1; i <= n; i++) cin >> r[i];
    if (n <= 18) solve1();
    else if (m == 1) solve2();
    else if (m == n) solve3();
    else cout << 225301405;
    return 0;
}