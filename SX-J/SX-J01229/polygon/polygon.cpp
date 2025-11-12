#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], vis[5055], mymax = -1, sum, ans;
void dfs(int x) {
	if (x > n)
		return;
	if (sum >= 3)
		ans++;
	for (int i = x; i <= n; i++) {
		if (vis[i] == 0) {
			sum++;
			vis[i]++;
			dfs(x + 1);
			sum--;
			vis[i]--;
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
	if (n == 3) {
		for (int i = 1; i <= n; i++) {
			if (a[i] > mymax) {
				mymax = a[i];
				sum += a[i];
			}

		}
		if (sum > mymax * 2) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}
