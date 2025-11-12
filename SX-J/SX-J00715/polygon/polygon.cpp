#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[5005], sum;

void dfs(int deep, int mx, int x) {
	if (deep > 2) {
		sum++;
		sum %= 998244353;
	}
	if (deep > n) {
		return ;
	}
	if (deep < 3) {
		for (int i = deep + 1; i <= n; i++) {
			dfs(i, max(mx, a[i]), x + a[i]);
		}
		return ;
	}
	for (int i = deep + 1; i <= n; i++) {
		if (x > a[i]) {
			dfs(i, max(mx, a[i]), x + a[i]);
		}
	}
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << sum << endl;
	return 0;
}