/*
start at 16:50
finish at 17:16
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, ans;
char s[N];
int ct[N], cnt[N];
int C[N][N], A[N][N], fac[N];
void init() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
    for (int i = 0; i < N; ++i) C[i][0] = C[i][i] = 1;
    for (int i = 2; i < N; ++i) for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    for (int i = 0; i < N; ++i) for (int j = 0; j <= i; ++j) A[i][j] = 1ll * C[i][j] * fac[j] % mod;
    return;
}
int f[2][N][N], g[N][N];
inline void Add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
    return;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    init();
    scanf("%d%d%s", &n, &m, s + 1);
    for (int i = 1, x; i <= n; ++i) scanf("%d", &x), ++ct[x];
    cnt[0] = ct[0];
    for (int i = 1; i <= n; ++i) cnt[i] = cnt[i - 1] + ct[i];
    f[0][0][0] = 1;
    for (int i = 1, v; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) for (int k = 0; k <= i; ++k) g[j][k] = f[i & 1][j][k] = 0;
        for (int j = 0; j < i; ++j) for (int k = 0; k < i; ++k) if ((v = f[(i - 1) & 1][j][k])) {
            if (s[i] == '0') Add(g[j + 1][k + 1], v);
            else Add(f[i & 1][j][k + 1], v);
            if (cnt[j] - i + 1 + k > 0) Add(g[j + 1][k], 1ll * v * (cnt[j] - i + 1 + k) % mod);
        }
        for (int j = 0; j <= i; ++j) for (int k = 0; k <= i; ++k) if ((v = g[j][k])){
            for (int l = 0; l <= min(k, ct[j]); ++l)
                Add(f[i & 1][j][k - l], 1ll * v * C[k][l] % mod * A[ct[j]][l] % mod);
        }
    }
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) g[i][j] = 0;
    g[n][0] = 1;
    for (int i = n - 1, v; i >= 0; --i) {
        for (int j = 0; j <= n; ++j) if ((v = g[i + 1][j])) {
            for (int l = 0; l <= ct[i + 1]; ++l) Add(g[i][j + l], 1ll * v * C[ct[i + 1]][l] % mod * fac[l] % mod * C[j + l][l] % mod);
        }
    }
    for (int i = 0, v; i <= n - m; ++i) for (int j = 0; j <= n; ++j) if ((v = f[n & 1][i][j])) Add(ans, 1ll * v * g[i][j] % mod);
    printf("%d\n", ans);
    return 0;
}