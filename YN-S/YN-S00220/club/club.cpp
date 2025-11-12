#include <bits/stdc++.h>
using namespace std;

struct sb {
	int y, e, s;
} a[2000006];
int t, m, ans = -100;

void dfs(int dep, int sum, int fr, int se, int tr, int n) {
	if (dep > m) {
		ans = max(sum, ans);
	} else {
		if (fr + 1 <= n / 2) {
			dfs(dep + 1, sum + a[dep].y, fr + 1, se, tr, n);
		}
		if (se + 1 <= n / 2) {
			dfs(dep + 1, sum + a[dep].e, fr, se + 1, tr, n);
		}
		if (tr + 1 <= n / 2) {
			dfs(dep + 1, sum + a[dep].s, fr, se, tr + 1, n);
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	for (int k = 1; k <= t; k++) {
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a[i].y >> a[i].e >> a[i].s;
		}
		dfs(1, 0, 0, 0, 0, m);
		cout << ans << '\n';
		ans = -10;
	}
	return 0;
}