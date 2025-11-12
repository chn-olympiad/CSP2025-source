#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define P emplace_back
bool MBE;
namespace SOLVER {
const int N = 505, M = 998244353;
int n, m, a[N], sum[N], C[N][N], fac[N], f[2][N][N], ans; string s;
void add(int &x, int v) {x += v; if(x >= M) x -= M;}
void MAIN() {
    cin >> n >> m >> s; s = '#' + s; rep(i, 1, n) {int x; cin >> x; a[x]++;}
    rep(i, 0, n) rep(j, 0, i) C[i][j] = !j ? 1 : (C[i - 1][j] + C[i - 1][j - 1]) % M;
    fac[0] = 1, sum[0] = a[0]; f[0][0][0] = 1;
    rep(i, 1, n) fac[i] = fac[i - 1] * i % M, sum[i] = sum[i - 1] + a[i];
    rep(i, 0, n - 1) {
        rep(j, 0, min(i, n - m)) {
            rep(k, 0, min(i, n - sum[j])) if(f[0][j][k]) {
                // cerr << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << endl;
                if(sum[j] > i - k) {
                    rep(t, 0, min(a[j + 1], k)) {
                        int nf = f[0][j][k] * C[k][t] % M * C[a[j + 1]][t] % M * fac[t] % M;
                        nf = nf * (sum[j] - (i - k)) % M;
                        add(f[1][j + 1][k - t], nf);  
                    }
                }
                if(s[i + 1] == '0') {
                    rep(t, 0, min(a[j + 1], k + 1)) {
                        int nf = f[0][j][k] * C[k + 1][t] % M * C[a[j + 1]][t] % M * fac[t] % M;
                        add(f[1][j + 1][k + 1 - t], nf);  
                    }
                }
                else add(f[1][j][k + 1], f[0][j][k]);
            }
        }
        rep(j, 0, i + 1) rep(k, 0, i + 1) f[0][j][k] = f[1][j][k], f[1][j][k] = 0;
    }
    // rep(j, 0, n) rep(k, 0, n) if(f[n][j][k]) 
    //     cerr << n << ' ' << j << ' ' << k << ' ' << f[n][j][k] << endl;
    rep(i, 0, n - m) add(ans, f[0][i][n - sum[i]] * fac[n - sum[i]] % M); cout << ans << endl;
}
}
bool MED;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    SOLVER::MAIN();
    cerr << (&MBE - &MED) / 1024 << " kb, " << clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}