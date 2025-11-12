#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int f[N][N][N], g[N][3];
int ans = 0;
int n;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(g, 0, sizeof g);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> g[i][0] >> g[i][1] >> g[i][2];
		}
		memset(f, 0, sizeof f);
		if (n == 2) {
			for (int i = 1; i <= 3; i++)
				for (int j = 1; j <= 3; j++)
					if (i != j)
						ans = max(ans, g[1][i - 1] * i + g[2][j - 1] * j);
			cout << ans << endl;
		} else {
			for (int i = 1; i <= n; i++)
				for (int j = n; j >= 1; j++)
					for (int m = n; m >= 1; m++) {
						int k = n - m - j;
						if (m <= n / 2 && j <= n / 2 && k <= n / 2) {
							f[j][m][k] = max(f[j][m - 1][k] + g[i][1] * 2, f[j][m - 1][k - 1] + g[i][2] * 3);
							f[j][m][k] = max(f[j - 1][m][k] + g[i][0], f[j][m - 1][k - 1] + g[i][2] * 3);
							ans = max(ans, f[j][m][k]);
						}

					}
			cout << ans << endl;
		}

	}
	return 0;
}
