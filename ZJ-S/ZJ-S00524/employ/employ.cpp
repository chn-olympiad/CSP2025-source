#include <bits/stdc++.h>
// #define int long long
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define rep(i, x, y) for (int i = (x); i >= (y); i--)
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define pb emplace_back
#define all(v) (v).begin(), (v).end()
using namespace std;
const int N = 505, mod = 998244353;
int n, m;
string s;
int cnt[N];
#define add(x, y) ((x += y) >= mod && (x -= mod))
int f[2][N][N], g[N][N], C[N][N], fac[N], pre[N];
void Main() {
    cin >> n >> m;
    For (i, 0, n) {
        C[i][0] = 1;
        For (j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    fac[0] = 1;
    For (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
    cin >> s; s = " " + s;
    For (i, 1, n) {
        int x; cin >> x;
        cnt[x]++;
    }
    pre[0] = cnt[0];
    For (i, 1, n) pre[i] = pre[i - 1] + cnt[i];
    f[0][0][0] = 1;
    For (i, 0, n - 1) {
        int now = i & 1, nex = now ^ 1;
        memset(g, 0, sizeof g);
        memset(f[nex], 0, sizeof f[nex]);
        For (v, 0, i) {
            For (c, 0, i) {
                if (!f[now][v][c]) continue;
                // cout << i << ' ' << v << ' ' << c << ' ' << f[i][v][c] << '\n';
                if (s[i + 1] == '0') {
                    For (c2, 0, min(cnt[v + 1], i - c)) {
                        add(g[v + 1][c + c2], 1ll * f[now][v][c] * C[i - c][c2] % mod * C[cnt[v + 1]][c2] % mod * fac[c2] % mod);
                    }
                } else {
                    if (pre[v] > c) {
                        For (c2, 0, min(cnt[v + 1], i - c)) {
                            add(f[nex][v + 1][c + c2 + 1], 1ll * f[now][v][c] * (pre[v] - c) % mod * C[i - c][c2] % mod * C[cnt[v + 1]][c2] % mod * fac[c2] % mod);
                        }
                    }
                    if (n - pre[v] > i - c) {
                        add(f[nex][v][c], f[now][v][c]);
                    }
                }
            }
        }
        For (v, 0, i + 1) {
            For (c, 0, i) {
                if (g[v][c]) {
                    if (n - pre[v] > i - c) add(f[nex][v][c], g[v][c]);
                    if (pre[v] > c) add(f[nex][v][c + 1], 1ll * g[v][c] * (pre[v] - c) % mod);
                }
            }
        }
    }
    int ans = 0;
    For (v, 0, n - m) add(ans, 1ll * f[n & 1][v][pre[v]] * fac[n - pre[v]] % mod);
    cout << ans;
    return;
}
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    int T;
    T = 1;
    while (T--) Main();
    return 0;
}