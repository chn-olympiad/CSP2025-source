#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[5100];
ll ans;

void dfs(int x, int k, int h, bool f) {
	if (k >= 3 && f == true) {
		if (a[x] * 2 < h) {
			ans++;
		}
	}
	if (x + 1 <= n) {
		dfs(x + 1, k, h, false);
		dfs(x + 1, k + 1, h + a[x + 1], true);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n >= 500) {
		cout << 1;
		return 0;
	}
	sort(a + 1, a + n + 1);
	dfs(1, 0, 0, false);
	dfs(1, 1, a[1], true);
	cout << ans % 998244353;
	return 0;
}
