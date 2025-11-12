#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 50, mod = 998244353;
int n, m, a[N], sum = 1, dp[N], ys[N], g, ans = 1;
string s, tmp;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		tmp += "1";
		cin >> a[i];
		sum *= n % mod;
	}
	if (s != tmp) {
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			if (a[i] == a[i - 1]) {
				ys[g]++;
//				cout << ys[g] << " ";
			} else {
				g++;
			}
			if (s[i - 1] == '0' || a[i] <= dp[i - 1]) {
				dp[i] = dp[i - 1] + 1;
			} else {
				dp[i] = dp[i - 1];
			}
//			cout << dp[i] << " ";
		}
//		cout << dp[n];
		if (n - dp[n] >= m) {
			for (int i = 1; i < g; i++) {
//				cout << ys[i] + 1 << " ";
				ans *= ys[i] + 1;
			}
			ans %= mod;
			cout << ans;
		} else
			cout << 0;
	} else
		cout << sum % mod;

	return 0;
}
