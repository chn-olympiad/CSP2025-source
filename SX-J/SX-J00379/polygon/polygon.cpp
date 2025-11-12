#include <bits/stdc++.h>
using namespace std;
int	a[5050], allsum, n;

void dfs(int i, int maxx, int sum, int ans) {
	maxx = max(maxx, a[i]);
	sum += a[i];
	ans++;
	if (ans >= 3) {
		if (sum > 2 * maxx) {
			allsum++;
		}

	}
	for (int j = i + 1; j <= n; j++) {
		dfs(j, maxx, sum, ans);
	}
	return;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 2; i++) {
		dfs(i, 0, 0, 0);
	}
	allsum %= 998;
	allsum %= 244;
	allsum %= 353;
	cout << allsum;
	return 0;
}
