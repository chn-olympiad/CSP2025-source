#include <bits/stdc++.h>
using namespace std;
const int N = 105, mod = 998244353;
int n, m, s[505], buc[505], f[N][N][N], g[N][N][N], ct0[505], fac[505], ifac[505];
char str[505];
inline void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}
inline int pls(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
inline int ksm(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod, y >>= 1;
    }
    return res;
}
namespace subtask1 {
inline void solve(){
    g[0][0][buc[0]] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i && j + m <= n; j++) for(int k = 0; k < i; k++) for(int l = 0; l <= s[j]; l++) if(g[j][k][l]){
            if(str[i] == '0') {
                for(int o = 0, cf; o <= buc[j + 1] && o <= k; o++) {
                    cf = 1ll * g[j][k][l] * fac[k] % mod * fac[buc[j + 1]] % mod * ifac[o] % mod * ifac[k - o] % mod * ifac[buc[j + 1] - o] % mod;
                    add(f[j + 1][k - o + 1][l + buc[j + 1] - o], cf);
                    if(l || o < buc[j + 1]) add(f[j + 1][k - o][l + buc[j + 1] - o - 1], 1ll * cf * (l + buc[j + 1] - o) % mod);
                }
            }
            else {
                add(f[j][k + 1][l], g[j][k][l]);
                if(l) for(int o = 0, cf; o <= buc[j + 1] && o <= k; o++) {
                    cf = 1ll * g[j][k][l] * fac[k] % mod * fac[buc[j + 1]] % mod * ifac[o] % mod * ifac[k - o] % mod * ifac[buc[j + 1] - o] % mod;
                    add(f[j + 1][k - o][l + buc[j + 1] - o - 1], 1ll * cf * l % mod);
                }
            }
        }
        for(int j = 0; j <= i && j + m <= n; j++) for(int k = 0; k <= i; k++) for(int l = 0; l <= s[j]; l++) {
            g[j][k][l] = f[j][k][l], f[j][k][l] = 0;
            // if(g[j][k][l]) {
            //     printf("dp[%d][%d][%d][%d] = %d\n", i, j, k, l, g[j][k][l]);
            // }
        }
    }
    int ans = 0;
    for(int j = 0; j + m <= n; j++) {
        add(ans, 1ll * g[j][s[n] - s[j]][0] * fac[s[n] - s[j]] % mod);
    }
    printf("%d\n", ans), exit(0);
}
}
namespace subtask2 {
inline void solve() {
    int ans = 0;
    for(int i = 1, cf, m, ok; i <= n; i++) if(str[i] == '1'){
        cf = 1, m = n - i, ok = 0;
        for(int j = 1; j < i; j++) {
            if(str[j] == '0') m++;
            else cf = 1ll * cf * (s[j - 1] - ok) % mod, ok++;
        }
        if(cf) cf = 1ll * cf * (s[n] - s[i - 1]) % mod * fac[m] % mod;
        add(ans, cf);
    }
    printf("%d\n", ans), exit(0);
}
}
namespace subtask3 {
inline bool check() {
    for(int i = 1; i <= n; i++) if(str[i] == '0') return false;
    return true;
}
int f[505], g[505];
inline void solve() {
    // cerr << "ok\n";
    int ans = 0;
    auto C = [&](int n, int m) {
        if(n < m || m < 0) return 0;
        return (int)(1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod);
    };
    auto S = [&](int n, int m) {
        if(n == 0) return m == 0 ? 1 : 0;
        return C(n + m - 1, n - 1);
    };
    g[buc[0]] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= s[i - 1]; j++) if(g[j]) for(int k = 0; k <= buc[i]; k++) {
            add(f[j + k], 1ll * g[j] * S(max(0, j - i + 1), k) % mod * S(s[i - 1] + 1 - max(0, j - i + 1), buc[i] - k) % mod);
            // cerr << i << ' ' << j << ' ' << k << ' ' << g[j] << ' ' << S(max(0, j - i + 1), k) << ' ' << S(s[i - 1] + 1 - max(0, j - i + 1), buc[i] - k) << '\n';
        }
        for(int j = 0; j <= s[i]; j++) g[j] = f[j], f[j] = 0;
    }
    for(int i = 0; i + m <= n; i++) add(ans, g[i]);
    for(int i = 0; i <= n; i++) ans = 1ll * ans * fac[buc[i]] % mod;
    printf("%d\n", ans), exit(0);
}
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d%s", &n, &m, str + 1);
    for(int i = 1; i <= n; i++) if(str[i] == '0') {
        ct0[i] = 1;
    }
    for(int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        s[x]++, buc[x]++;
    }
    for(int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        ct0[i] += ct0[i - 1];
    }
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[n] = ksm(fac[n], mod - 2);
    for(int i = n - 1; ~i; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    if(n <= 100) subtask1::solve();
    if(m == 1) subtask2::solve();
    if(subtask3::check()) subtask3::solve();
    return 0;
}