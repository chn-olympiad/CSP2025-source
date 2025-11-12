#include <bits/stdc++.h>
using namespace std;

int n, a[5005], ans = 0, b[5005];
bool f[5005];

void dfs(int x, int l, int lst) {
	if (x > l) {
		int mx = -1, sum = 0;
		for (int i = 1; i <= l; i++) {
			mx = max(mx, b[i]);
			sum += b[i];
		}
		if (sum > 2 * mx)
			ans++;
		return;
	}
	for (int i = lst + 1; i <= n; i++) {
		if (f[i] == false && i != 0) {
			f[i] = true;
			b[x] = a[i];
			dfs(x + 1, l, i);
			b[x] = 0;
			f[i] = false;
		}
	}
}


int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int len = 1; len <= n; len++) {
		dfs(1, len, 0);
	}
	cout << ans << endl;
	return 0;
}
