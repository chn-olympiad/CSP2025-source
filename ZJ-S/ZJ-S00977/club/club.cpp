#include <bits/stdc++.h>
using namespace std;

int a[10005], b[10005], c[10005], n, ans;

void dfs(int x, int ca, int cb, int cc, int sum) {
	if (x > n) {
		ans = max(ans, sum);
		return;
	}
	if (ca < n / 2)
		dfs(x + 1, ca + 1, cb, cc, sum + a[x]);
	if (cb < n / 2)
		dfs(x + 1, ca, cb + 1, cc, sum + b[x]);
	if (cc < n / 2)
		dfs(x + 1, ca, cb, cc + 1, sum + c[x]);
}

void dfs2(int x, int ca, int cb, int sum) {
	if (x > n) {
		ans = max(ans, sum);
		return;
	}
	if (ca < n / 2)
		dfs2(x + 1, ca + 1, cb, sum + a[x]);
	if (cb < n / 2)
		dfs2(x + 1, ca, cb + 1, sum + b[x]);
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		ans = -1;
		cin >> n;
		bool A = true, B = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] || c[i]) A = false;
			if (c[i]) B = false;
		}
		if (A == true) {
			int ans = 0;
			sort(a + 1, a + 1 + n);
			for (int i = n; i > n / 2; i--) {
				ans += a[i];
			}
			cout << ans << "\n";
		} else if (B == true) {
			dfs2(1, 0, 0, 0);
			cout << ans << "\n";
		} else {
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
		}
	}
	return 0;
}
