#include <bits/stdc++.h>
#define maxn 5005
using namespace std;
int n, a[maxn], ans, mod = 998244353;

void dfs(int u, int num, int maxx, int h, int b) {
	if (u > n)
		return;

	if (num == 0) {
		if (h > maxx * 2 && b >= 3) {
			ans++;
			ans %= mod;
		}
		return;
	}
	for (int i = u + 1; i <= n; i++) {
		dfs(i, num - 1, max(maxx, a[u]), h + a[u], b + 1);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygen.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 3; j <= n; j++) {
			dfs(i, j - 1, a[i], a[i], 1);
		}
	}
	cout << ans;
	return 0;
}
