#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 50;
int n, t, a[N][5], mum, ans, vis[5], c[N];

void dfs(int d, int num) {
	if (d > n) {
		ans = max(ans, num);
		return;
	}
	if (vis[1] < mum) {
		vis[1]++;
		dfs(d + 1, num + a[d][1]);
		vis[1]--;
	}
	if (vis[2] < mum) {
		vis[2]++;
		dfs(d + 1, num + a[d][2]);
		vis[2]--;
	}
	if (vis[3] < mum) {
		vis[3]++;
		dfs(d + 1, num + a[d][3]);
		vis[3]--;
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		int c1, c2, c3;
		mum = n / 2, ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (j == 1 && a[i][j] == 0)
					c1++;
				if (j == 2 && a[i][j] == 0)
					c2++;
				if (j == 3 && a[i][j] == 0)
					c3++;
			}
		}
		if (c2 == c3 == n) {
			for (int i = 1; i <= n; i++) {
				c[i] = a[i][1];
			}
			sort(c + 1, c + n + 1);
			for (int i = n; i >= n - mum + 1; i--) {
				ans += c[i];
			}
		} else {
			memset(vis, 0, sizeof(vis));
			dfs(1, 0);
		}
		cout << ans << '\n';
	}

	return 0;
}
