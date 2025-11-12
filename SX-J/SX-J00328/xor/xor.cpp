#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5, M = (1LL << 20) + 5;
int dp[N], mx[M];
int s[N], a[N];
int n, k;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	memset(mx, 0xcf, sizeof mx);
	mx[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = max(mx[s[i] ^ k] + 1, dp[i - 1]);
		mx[s[i]] = max(dp[i], mx[s[i]]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}
