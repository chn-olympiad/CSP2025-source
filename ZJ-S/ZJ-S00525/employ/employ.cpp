#include <bits/stdc++.h>
using namespace std; const int N = 505, M = 998244353;
int n, m, c[N], ans; string s; bool vis[N];
void dfs(int dep, int cur) {
	if (dep == n + 1) {
		if (n - cur >= m) ++ans, ans %= M;
		return;
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) {
			vis[i] = 1;
			if (cur >= c[i]) dfs(dep + 1, cur + 1);
			else if (s[dep] == '0') dfs(dep + 1, cur + 1);
			else dfs(dep + 1, cur);
			vis[i] = 0;
		}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m >> s; s = ' ' + s;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	dfs(1, 0); cout << ans << '\n'; return 0;
}