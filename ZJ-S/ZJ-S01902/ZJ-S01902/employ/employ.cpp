#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
char s[19];
int c[19];
int dp[1 << 18][19];
void upd(int &x, int y) {
    x = (x + y) % mod;
}
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin >> n >> m >> (s + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    dp[0][0] = 1;
    for (int w = 0; w < (1 << n); w++) {
        int siz = __builtin_popcount(w);
        for (int j = 0; j <= n; j++) {
            if (!dp[w][j]) continue;
            for (int k = 1; k <= n; k++) {
                if ((w >> (k - 1) & 1)) continue;
                if (s[siz + 1] == '0' || j >= c[k]) {
                    upd(dp[w | (1 << (k - 1))][j + 1], dp[w][j]);
                } else {
                    upd(dp[w | (1 << (k - 1))][j], dp[w][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (n - i >= m) {
            upd(ans, dp[(1 << n) - 1][i]);
        }
    }
    cout << ans << endl;
    return 0;
}