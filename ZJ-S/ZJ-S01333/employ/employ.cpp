#include <bits/stdc++.h>
using namespace std;

#define MAXN 18

int c[MAXN], dp[MAXN][MAXN][1 << MAXN];

int main() {
	freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, res = 0;
    string s;
    cin >> n >> m >> s;
    if (n > 18) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i ++) {
        cin >> c[i];
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= i; j ++) {
            for (int k = 0; k < (1 << n) - 1; k ++) {
                for (int l = 0; l < n; l ++) {
                    if ((k & (1 << l)) == 0) {
                        if (c[l] <= j || s[i] == '0') {
                            dp[i + 1][j + 1][k | (1 << l)] += dp[i][j][k] %= 998244353;
                        } else {
                            (dp[i + 1][j][k | (1 << l)] += dp[i][j][k]) %= 998244353;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i <= n - m; i ++) {
        (res += dp[n][i][(1 << n) - 1]) %= 998244353;
    }
    cout << res << '\n';
    return 0;
}