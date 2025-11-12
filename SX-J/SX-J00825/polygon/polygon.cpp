#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
int a[5099], f[5099][21];
int vis[10009];
int mod = 998244353;
int p;

void dfs( int now, int tim, int sum, int mx) {
	if (tim >= 3) {
		if (sum > mx * 2)
			cnt++;
	}
	for (int i = now; i <= n; i++) {
		p++;
		dfs( i + 1, tim + 1, sum + a[i], max(mx, a[i]));
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 1, 0, -1e9);
	cout << cnt % mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}