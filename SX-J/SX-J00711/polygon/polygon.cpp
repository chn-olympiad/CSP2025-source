#include <bits/stdc++.h>
using namespace std;
int a[5005];
int n;
int ans = 0;

void dfs(int kn, int mmax, int sum) {
	if (kn > n)
		return;
	if (sum > mmax * 2) {
		ans++;
		return;
	}
	for (int k = 3 ; k <= kn; k++) {
		for (int i = 1; i <= n; i++) {
			dfs(kn + 1, max(mmax, a[i]), sum + a[i]);
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
	if (n < 3) {
		cout << 0;
		return 0;
	}

	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
