#include <bits/stdc++.h>
using namespace std;
int a[5005], vis[5005], n, w, ans = 0;

void dfs(int next, int sum, int i) {
	if (i == w + 1 && a[next] * 2 < sum)
		ans = (ans + 1) % 998244353;
	for (int j = next + 1; j <= n; j++) {
		if (!vis[j]) {
			vis[j] = 1;
			dfs(j, sum + a[j], i + 1);
			vis[j] = 0;
		}
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 3; i <= n; i++) {
		w = i;
		dfs(0, 0, 1);
	}
	cout << ans;
	return 0;
}
