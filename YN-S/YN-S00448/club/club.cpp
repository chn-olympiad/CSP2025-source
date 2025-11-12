#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, vis[5];
int a[N][5], ans = -1;

void dfs(int k, int sum) {
	if (k == n + 1) {
		ans = max(sum, ans);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if ((vis[i] + 1) <= (n / 2)) {
			vis[i]++;
			dfs(k + 1, sum + a[k][i]);
			vis[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		memset(vis, 0, sizeof(vis));
		ans = -1;
		dfs(1, 0);
		cout << ans << "\n";
	}

	return 0;
}
