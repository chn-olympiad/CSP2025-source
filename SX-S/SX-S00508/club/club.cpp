#include <bits/stdc++.h>
using namespace std;
int a[11111][11111];
int f[11111][11111];
int c[4];
long long m, ans, x, y;

void dfs(int dep, long long zhi) {
	if (dep > m) {
		ans = max(ans, zhi);
		//	cout << zhi << " " << dep << endl;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (f[dep][i] == 0 && c[i] < m / 2) {
			f[dep][i] = 1;
			c[i]++;
			zhi += a[dep][i];
			dfs(dep + 1, zhi);
			c[i]--;
			f[dep][i] = 0;
			zhi = zhi - a[dep][i];
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {

		cin >> m;
		for (int j = 1; j <= m; j++) {
			cin >> a[j][1] >> a[j][2] >> a[j][3];
		}
		ans = 0;
		dfs(1, 0);
		cout << ans << endl;
	}
}