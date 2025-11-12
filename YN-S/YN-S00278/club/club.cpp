#include <bits/stdc++.h>
using namespace std;
int t, n, ans;

int a[4][100005];
void dfs(int dep, int cnt1, int cnt2, int d) {
	if (dep == n + 1) {
		ans = max(ans, d);
		return;
	}
	if (cnt1 < n / 2)
		dfs(dep + 1, cnt1 + 1, cnt2, cnt3, d + a[1][dep]);
	if (cnt2 < n / 2)
		dfs(dep + 1, cnt1, cnt2 + 1, cnt3, d + a[2][dep]);
	if (cnt3 < n / 2)
		dfs(dep + 1, cnt1, cnt2, cnt3 + 1, d + a[3][dep]);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[j][i];
		}
	}
	if (n <= 18) {
		dfs(1, 0, 0, 0, 0);
		cout << ans << '\n';
	} else {
		sort(a[1] + 1, a[1] + n + 1);
		for (int i = n; i >= (n >> 1); i--) {
			ans += a[1][i];
		}
		cout << ans << '\n';
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
		solve();
	return 0;
}
