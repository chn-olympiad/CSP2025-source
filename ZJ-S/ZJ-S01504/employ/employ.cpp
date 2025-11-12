#include <bits/stdc++.h>
// #define int long long
#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5, mod = 998244353;
bool bg;
int n, m, a[N], c[N];

int dp[19][19][1 << 18];
void add(int &x, int y) {
    if ((x += y) >= mod) x -= mod;
}
bool ed;
signed main() {
    // cerr << (&bg - &ed) / 1048576.0 << '\n';
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    F(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    F(i, 1, n) cin >> c[i];
    dp[0][0][0] = 1;
    F(d, 0, n - 1) F(i, 0, d) {
        for (int s = 0; s < 1 << n; s++) {
            if (__builtin_popcount(s) != d) continue;
            F(j, 1, n) {
                if (s >> j - 1 & 1) continue;
                if (a[d + 1] == 0 || i >= c[j]) {
                    add(dp[d + 1][i + 1][s | (1 << j - 1)], dp[d][i][s]);
                } else {
                    add(dp[d + 1][i][s | (1 << j - 1)], dp[d][i][s]);
                }
            }
        }
    }
    int ans = 0;
    F(i, 0, n - m) {
        add(ans, dp[n][i][(1 << n) - 1]);
    }
    cout << ans << '\n';
    return 0;
}