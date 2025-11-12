#include <bits/stdc++.h>
#define int long long
using namespace std;
int c[5005][5005];
int a[5005], n, ans, x[5005];
bool flag[5005];
void dfs(int deep, int m) {
	if (deep == m + 1) {
		int sum = 0, mx = 0;
		for (int i = 1; i <= m; i ++) {
			sum += a[x[i]];
			mx = max(mx, a[x[i]]);
		}
		if (sum > mx * 2) 	ans ++;
		return;
	}
	for (int i = x[deep - 1] + 1; i <= n; i ++) {
		if (flag[i] == 0) {
			x[deep] = i;
			flag[i] = 1;
			dfs(deep + 1, m);
			flag[i] = 0;
		}
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	if (n == 3) {//12#
		int mx = max(a[1], max(a[2], a[3]));
		int su = a[1] + a[2] + a[3];
		if (su > mx * 2) 	cout << 1;
		else				cout << 0;
		return 0;
	} else if (n <= 20) {//28#
		for (int i = 3; i <= n; i ++)	dfs(1, i);
		cout << ans;
	} else {//24#
		int s = 0;
		c[0][0] = 1;
		for (int i = 1; i <= 5000; i ++) {
			c[i][0] = 1;
			for (int j = 1; j <= i; j ++) {
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
		for (int i = 3; i <= n; i ++) 	s += c[n][i];
		cout << s;
	}
	return 0;
}