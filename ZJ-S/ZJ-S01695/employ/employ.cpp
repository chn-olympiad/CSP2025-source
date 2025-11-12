#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace Qiuyu3600 {
const int N = 18;
const int mod = 998244353;
inline void cadd(int &a, int b) {(a += b) >= mod && (a -= mod);}
int n, m, st[N + 1], c[N];
int f[2][1 << N][N + 1], ans;
void Hutao() {
    cin >> n >> m;
    char ch;
    for(int i = 1; i <= n; i ++) cin >> ch, st[i] = ch ^ '0';
    for(int i = 0; i < n; i ++) cin >> c[i];
    int cur = 0;
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        cur ^= 1;
        for(int s = 0; s < 1 << n; s ++)
            for(int j = 0; j <= i; j ++)
                f[cur][s][j] = 0;
        for(int s = 0; s < 1 << n; s ++)
            for(int j = 0; j < i; j ++) if(f[cur ^ 1][s][j]) {
                for(int k = 0; k < n; k ++) if(!(s >> k & 1)) {
                    cadd(f[cur][s ^ 1 << k][j + (st[i] == 0 || j >= c[k])], f[cur ^ 1][s][j]);
                }
            }
    }
    for(int j = 0; j <= n - m; j ++) cadd(ans, f[cur][(1 << n) - 1][j]);
    cout << ans;
}
}
int main() {
    #ifndef DB
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #endif
    int t = 1; while(t --) Qiuyu3600::Hutao();
    return 0;
}