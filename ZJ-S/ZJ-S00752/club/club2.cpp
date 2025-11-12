#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, a[N][10], f[2][N][N];
int main1() {
//	freopen("club1.in", "r", stdin);
//	freopen("club1.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i ++)
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    memset(f, 0, sizeof f);
    for (int i = 1;i <= n;i ++) {
        for (int j = 0;j <= min(n / 2, i);j ++) {
            for (int k = 0, p = i - j - k;k <= min(n / 2, i);k ++, p --) {
                if (p > n / 2) continue;
                if (p < 0) break;
                if (j > 0) f[i & 1][j][k] = max(f[i & 1][j][k], f[i & 1 ^ 1][j - 1][k] + a[i][1]);
                if (k > 0) f[i & 1][j][k] = max(f[i & 1][j][k], f[i & 1 ^ 1][j][k - 1] + a[i][2]);
                if (p > 0) f[i & 1][j][k] = max(f[i & 1][j][k], f[i & 1 ^ 1][j][k] + a[i][3]);
//                cout << j << " " << k << " " << p << " " << i << " " << f[i & 1][j][k] << "\n";
            }
        }
    }
    int ans = 0;
    for (int i = 0;i <= n / 2;i ++) {
        for (int j = 0;j <= n / 2;j ++) {
            if (n - i - j > n / 2) continue;
            ans = max(ans, f[n & 1][i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
int main() {
	int T; cin >> T;
	while (T --) main1();
}