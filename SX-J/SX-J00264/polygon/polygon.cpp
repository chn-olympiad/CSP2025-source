#include <bits/stdc++.h>
using namespace std;
int a[5005];
int xuan[5005];
long long ans = 0;
int n;
int s = 0;

int vis[5005] = {0};
void dfs(int p, int sum, int f) {

	if (p > n)
		return;
	if (sum > 2 * s && p >= 3) {
		ans++;
		s = 0;
		return;
	}
	for (int i = f; i <= n; i++) {
		if (vis[i] == 0) {
			xuan[p] = a[i];
			vis[i] = 1;
			s = max(xuan[p], s);
		}
		dfs(p + 1, sum + a[i], i + 1);
		xuan[p] = 0;
		vis[i] = 0;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans % 998;
	return 0;
}
