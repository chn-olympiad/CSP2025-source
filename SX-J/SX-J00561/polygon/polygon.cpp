#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5020], ans, c[5020][5020];

void dfs(int id, int sum, int m, int mx) {
	if (id > n) {
		if (m >= 3 && sum > mx * 2)

			ans = (ans + 1) % mod;
		return ;
	}
	dfs(id + 1, sum + a[id], m + 1, max(mx, a[id]));
	dfs(id + 1, sum, m, mx);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n <= 28) {
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		dfs(1, 0, 0, 0);
	} else {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++) {
				if (i == j)
					c[i][j] = 1;
				else
					c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
			}
		for (int i = 3; i <= n; i++)
			ans = (ans + c[n][i]) % mod;
	}
	cout << ans ;
	return 0;
}
