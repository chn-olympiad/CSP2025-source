//cl csp-s T4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5, Mod = 998244353;
ll n, m, s[N], c[N], vis[N], ans;

void dfs(int x, int tot) {
	if (n - x + 1 + tot < m)
		return;
	if (x == n + 1) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			if (s[x]) {
				if (c[i] > (x - tot - 1)) {
					dfs(x + 1, tot + 1);
				} else {
					dfs(x + 1, tot);
				}
			} else {
				dfs(x + 1, tot);
			}
			vis[i] = 0;
		}
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char z;
		cin >> z;
		s[i] = z - '0';
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}