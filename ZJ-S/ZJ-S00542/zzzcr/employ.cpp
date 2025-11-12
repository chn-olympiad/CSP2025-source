#include <bits/stdc++.h>
using namespace std;

#define file(name) assert(freopen(#name".in", "r", stdin)), assert(freopen(#name".out", "w", stdout))
#define _f(i, a, b) for(int i = a; i <= b; ++i)
#define _d(i, a, b) for(int i = a; i >= b; --i)
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define all(container) container.begin(), container.end()

constexpr int N = 5e2 + 5, mod = 998244353;

int n, m, c[N], dp[1 << 18][19], pc[1 << 18], f[2][105][105][105], cnt[N], fac[N], ifac[N];
string s;

void add(int &x, int y) { x += y; if(x >= mod) x -= mod; }
int ksm(int x, int y = mod - 2){
    int ret = 1;
    while(y) {
        if(y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod, y >>= 1;
    }
    return ret;
}

void solve() {
    cin >> n >> m >> s;
    if(n <= 18) {
        _f(i, 0, n - 1) cin >> c[i];
        dp[0][0] = 1;
        _f(i, 1, (1 << n) - 1) pc[i] = pc[i >> 1] + (i & 1);
        _f(i, 0, (1 << n) - 2) _f(j, 0, n - 1) if(dp[i][j]) {
            _f(k, 0, n - 1) if(~i >> k & 1) {
                if(s[pc[i]] == '0') add(dp[i ^ (1 << k)][j + 1], dp[i][j]);
                else {
                    if(j >= c[k]) add(dp[i ^ (1 << k)][j + 1], dp[i][j]);
                    else add(dp[i ^ (1 << k)][j], dp[i][j]);
                }
            }
        }
        int ans = 0;
        _f(i, 0, n - m) add(ans, dp[(1 << n) - 1][i]);
        cout << ans << '\n';
        return ;
    }
    if(m == n) {
        bool flg = 1;
        _f(i, 0, n - 1) {
            flg &= (s[i] == '1');
            cin >> c[i];
            flg &= (c[i] > 0);
        }
        int ans = (int)flg;
        _f(i, 1, n) ans = 1ll * ans * i % mod;
        cout << ans << '\n';
        return ;
    }
    bool flg = 1;
    _f(i, 0, n - 1) flg &= (s[i] == '1');
    fac[0] = ifac[0] = 1;
    _f(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[n] = ksm(fac[n]);
    _d(i, n - 1, 1) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    auto C = [&](int n, int m) -> int {
        if(n < m || n < 0 || m < 0) return 0;
        return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
    } ;
    // if(flg) {
    //     _f(i, 1, n) cin >> c[i], cnt[c[i]]++;
    //     sort(c + 1, c + n + 1);
    //     assert(c[1] == 0);
    //     int now = 0, lst = 1;
    //     f[now][0][n - 1][0] = n;
    //     // f[0][0][n][0] = 1;
    //     _f(i, 2, n) {
    //         cerr << i << '\n';
    //         if(c[i] != c[i - 1]) {
    //             swap(now, lst);
    //             memset(f[now], 0, sizeof f[now]);
    //             _f(j, 0, n) _f(k, 0, n) _f(l, 0, n) if(f[lst][j][k][l]) _f(t, 0, n) {
    //                 if(j + t <= n && k >= t) add(f[now][j + t][k - t][l], f[lst][j][k][l]);
    //             }    
    //         }
    //         cout << i << '\n';
    //         _f(j, 0, n) _f(k, 0, n) _f(l, 0, n) if(f[now][j][k][l]) {
    //             cout << j << ' ' << k << ' ' << l << ' '<< f[now][j][k][l] << '\n';
    //         }
    //         swap(now, lst);
    //         memset(f[now], 0, sizeof f[now]);
    //         _f(j, 0, n) _f(k, 0, n) _f(l, 0, n) if(f[lst][j][k][l]) {
    //             if(j) add(f[now][j - 1][k][l + 1], 1ll * f[lst][j][k][l] * j % mod);
    //             if(k) add(f[now][j][k - 1][l], 1ll * f[lst][j][k][l] * k % mod);
    //         }
    //         cout << i << '\n';
    //         _f(j, 0, n) _f(k, 0, n) _f(l, 0, n) if(f[now][j][k][l]) {
    //             cout << j << ' ' << k << ' ' << l << ' '<< f[now][j][k][l] << '\n';
    //         }
    //     }
    //     int ans = 0;
    //     _f(i, 0, n) add(ans, f[now][0][0][i]);
    //     _f(i, 0, n) ans = 1ll * ans * ifac[cnt[i]] % mod;
    //     cout << ans << '\n';
    // }
}

signed main() {
    file(employ1);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

// lky 