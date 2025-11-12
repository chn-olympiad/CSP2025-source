#include <bits/stdc++.h>
using namespace std;
int cs[1000030][5], nc[3000][30000], lu[10010][10010], pd[1000030];
int n, m, k, ans = 210000000;

void dfs(int s, int l, int a) {
	if (s + 1 == l) {
		int he = 0;
		bool d = 0;
		for (int j = 1; j <= n; j++) {
			bool e = 1;
			for (int k = 1; k <= n; k++) {
				if (lu[j][k] != 0) {
					e = 0;
					he += lu[j][k];
				}
			}
			d = e;
			if (d == 1)
				return;
		}
		ans = min(ans, he);
		return ;
	}
	for (int i = a + 1; i <= m + k; i++) {

		if (pd[i] == 0) {
			pd[i] = 1;
			if (i <= m) {
				lu[cs[i][1]][cs[i][2]] = cs[i][3];
				lu[cs[i][2]][cs[i][1]] = cs[i][3];
			} else {
				for (int j = 1; j <= n; j++) {
					lu[j][nc[i - m + 1][1]] = nc[i - m][1];
					lu[nc[i - m + 1][1]][j] = nc[i - m][1];
				}
			}
			dfs(s + 1, l, i);
			if (i <= m) {
				lu[cs[i][1]][cs[i][2]] = 0;
				lu[cs[i][2]][cs[i][1]] = 0;
			} else {
				for (int j = 1; j <= n; j++) {
					lu[j][nc[i - m + 1][1]] = 0;
					lu[nc[i - m + 1][1]][j] = 0;
				}
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n ; i++) {
		cin >> cs[i][1] >> cs[i][2] >> cs[i][3];
	}
	for (int i = 1; i <= k; i++) {

		for (int j = 1; j <= n + 1; j++) {
			cin >> nc[i][j];
		}
	}
	for (int i = n - 2; i <= n + k; i++) {
		dfs(1, i, 0);
	}
	cout << ans;
	return 0;
}