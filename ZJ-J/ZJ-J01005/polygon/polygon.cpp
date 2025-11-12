#include <bits/stdc++.h>
using namespace std;
int n, a[5010], ans;
void dfs(int sum, int k, int cur, int depth) {
	ans = (ans + ((depth >= 3 && sum > (cur << 1)) ? 1 : 0)) % 998244353;
	for (int i = k; i < n; i++) {
		dfs(sum + a[i], i + 1, a[i], depth + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	dfs(0, 0, 0, 0);
	cout << ans;
	return 0;
}
