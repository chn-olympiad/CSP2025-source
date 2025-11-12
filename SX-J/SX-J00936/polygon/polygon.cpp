#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5005, P = 998244353;
int n;
int a[N], s[N];
int f[2][N * 5000][3][2]; //0:ans 1:lst
int cnt = 0;

void dfs(int c, int sum, int ct) {
	if (c == n + 1) {
		return;
	}
	if (ct < 2) {
		dfs(c + 1, sum + a[c], ct + 1);
	} else {
		if (sum > a[c]) {
			cnt++;
			cnt %= P;
		}
		dfs(c + 1, sum + a[c], ct);
	}
	dfs(c + 1, sum, ct);
}
int fac[N];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int fl = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			fl = 0;
		}
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + 1 + n);
	if (fl) {
		fac[1] = 1;
		fac[0] = 1;
		for (int i = 2; i <= n; i++) {
			fac[i] = i * fac[i - 1];
			fac[i] %= P;
		}
		int sum = 0;
		for (int i = 3; i <= n; i++) {
			sum += fac[n] / fac[n - i] / fac[i];
			sum %= P;
		}
		cout << sum;
		return 0;
	}
	if (n <= 10) {
		dfs(1, 0, 0);
		cout << cnt;
		return 0;
	}
	f[1][0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s[i] - a[i]; j++) {
			f[(i + 1) & 1][j + a[i]][1][0] += f[i & 1][j][0][0];
			f[(i + 1) & 1][j + a[i]][1][0] %= P;
			f[(i + 1) & 1][j + a[i]][2][0] += f[i & 1][j][1][0];
			f[(i + 1) & 1][j + a[i]][2][0] %= P;
			f[(i + 1) & 1][j + a[i]][2][0] += f[i & 1][j][2][0];
			f[(i + 1) & 1][j + a[i]][2][0] %= P;

			f[(i + 1) & 1][j + a[i]][1][1] = a[i];
			f[(i + 1) & 1][j + a[i]][2][1] = a[i];
			f[(i + 1) & 1][j + a[i]][2][1] = a[i];

			f[(i + 1) & 1][j][0][0] = f[i & 1][j][0][0];
			f[(i + 1) & 1][j][1][0] = f[i & 1][j][1][0];
			f[(i + 1) & 1][j][2][0] = f[i & 1][j][2][0];

			f[(i + 1) & 1][j][0][1] = f[i & 1][j][0][1];
			f[(i + 1) & 1][j][1][1] = f[i & 1][j][1][1];
			f[(i + 1) & 1][j][2][1] = f[i & 1][j][2][1];
		}
	}
	int sum = 0;
	for (int i = 1; i <= s[n]; i++) {
		if (f[(n + 1) & 1][i][2][1] * 2 < i) {
			sum += f[(n + 1) & 1][i][2][0];
			sum %= P;
		}
	}
	cout << sum ;
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/