#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
#define ll long long

ll dp[19][(1 << 18)][19];
char s[505];
int c[505];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;cin >> n >> m;
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    if (n > 20) {
        ll sum = 1;
        for (int i = 1; i <= n; i++) {
            sum *= i;sum %= p;
        }
        cout << sum;
        return 0;
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            for (int k = 0; k <= min(n - m, i); k++) {
                if (!dp[i][j][k])continue;
                //cout << i << ":" << j << ":" << k << " " << dp[i][j][k] << endl;
                for (int nxt = 1; nxt <= n; nxt++) {
                    if (j & (1 << (nxt - 1))) {
                        continue;
                    }
                    int nk;
                    if (k >= c[nxt]) {
                        nk = k + 1;
                    }else {
                        nk = k + (s[i + 1] == '0');
                    }
                    //cout << nxt << ":" << nk << endl;
                    if (nk > n - m)continue;
                    dp[i + 1][j | (1 << (nxt - 1))][nk] += dp[i][j][k];
                    dp[i + 1][j | (1 << (nxt - 1))][nk] %= p;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n - m; i++) {
        //cout << n << ":" << (1 << n) - 1 << ":" << i << " " << dp[n][(1 << n) - 1][i] << endl;
        ans += dp[n][(1 << n) - 1][i];
        ans %= p;
    }
    cout << ans;
    return 0;
}


/*


100+[80,100]+[50,100]+20=[250,320]

*/