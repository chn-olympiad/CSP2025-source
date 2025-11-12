#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, mod = 998244353, ans, a[505], path[505], bk[505];
string s;

void dfs(int u) {
	if (u == n + 1) {
		int cnt = 0, tot = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt >= a[path[i]]) {
				cnt++;
				continue;
			}
			if (s[i - 1] == '1')
				tot++;
			else
				cnt++;
		}
		ans += (tot >= m), ans %= mod;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!bk[i]) {
			path[u] = i;
			bk[i] = 1;
			dfs(u + 1);
			path[u] = 0;
			bk[i] = 0;
		}
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 10) {
		dfs(1);
		cout << ans;
	} else {
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '0' || a[i] == 0) {
				cout << 0;
				return 0;
			}
		}
		ans = 1;
		for (int i = 1; i <= n; i++)
			ans = (ans % mod) * (i % mod), ans %= mod;
		cout << ans;
	}
	return 0;
}