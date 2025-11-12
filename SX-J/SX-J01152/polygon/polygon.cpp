#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int maxn = 0, ans, num;

void dfs(int x) {
	if (x > 3 && x <= n) {
		ans++;
	}
	if (x > n) {
		cout << ans % 998244353;
	}
	for (int i = x; i <= n; i++) {
		num += a[i];
		maxn = max(maxn, a[i]);
		dfs(i + 1);
	}
}

int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);

	return 0;
}
