#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans, i, cnt;

void dfs(int step, int sum, int l) {
	if (step == i) {
		if (sum > 2 * a[l]) {
			ans++;
		}
		return ;
	}
	for (int j = l + 1; j < n; j++) {
		dfs(step + 1, sum + a[j], j);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for ( i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for ( i = 3; i <= n; i++) {
		cnt = 0;
		dfs(0, 0, -1);
	}
	cout << ans % 998244353;
	return 0;
}