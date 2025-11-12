#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 5001;
int a[N], n, ans, sum[N], maxx, pre[N], total;

inline bool cmp(int a, int b) {
	return a > b;
}

inline void init() {
	pre[0] = 1;
	for (int i = 1; i <= n; i++) {
		pre[i] = (pre[i - 1] * i) % mod;
	}
}

inline int C(int n, int m) {
	return (pre[m] / ((pre[n] * pre[m - n]) % mod)) % mod;
}

inline void dfs(int x, int bs, int maxx, int tot) {
	tot += a[x];
	maxx = max(maxx, a[x]);
	bs++;
	if (bs >= 3 && tot > maxx * 2) {
		ans++;
		ans %= mod;
	}
	for (int i = x + 1; i <= n; i++) {
		dfs(i, bs, maxx, tot);
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	init();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		total += a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if (maxx == 1) {
		for (int i = 3; i <= n; i++) {
			ans = (ans + C(i, n)) % mod;
		}
		cout << ans;
		return 0;
	} else if (total < maxx * 2) {
		cout << 0;
		return 0;
	} else if (total == maxx * 2 +
	           1) {
		cout << 1;
		return 0;
	} else {
		for (int i = 1; i <= n - 2; i++) {
			dfs(i, 0, a[i], 0);
		}
		cout << ans;
		return 0;
	}
	return 0;
}
