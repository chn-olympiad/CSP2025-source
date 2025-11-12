#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010][5], b[100010];
int g, c, d, ans, f;

void dfs(int x, int y, int z, int e, int step) {
	if (step == n) {
		if (e > ans) {
			ans = e;
		}
		return;
	}
	if (x != 0) {
		dfs(x - 1, y, z, e + a[step + 1][1], step + 1);
	}
	if (y != 0) {
		dfs(x, y - 1, z, e + a[step + 1][2], step + 1);
	}
	if (z != 0) {
		dfs(x, y, z - 1, e + a[step + 1][3], step + 1);
	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		f = 0;
		cin >> n;
		g = n / 2;
		c = n / 2;
		d = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[i] = a[i][1];
			if (a[i][2] != 0 || a[i][3] != 0) {
				f = 1;
			}
		}
		if (f == 0) {
			sort(b + 1, b + n + 1);
			for (int i = n; i > c; i--) {
				ans += b[i];
			}
			cout << ans;
			ans = 0;
			continue;
		}
		dfs(g, c, d, 0, 0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
