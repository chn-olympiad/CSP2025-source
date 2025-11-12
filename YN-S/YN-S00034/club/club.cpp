#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T, n, a[N][5], dp[N][5], f[N][5][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		int k = n / 2;
		memset(dp, 0 - 0x7f, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				for (int l = 1; l <= 3; l++) {
					f[i][j][l] = k;
				}
			}
		}
		dp[0][1] = dp[0][2] = dp[0][3] = 0;
		dp[1][1] = a[1][1];
		dp[1][2] = a[1][2];
		dp[1][3] = a[1][3];
		if (a[1][1] != 0) {
			f[1][1][1]--;
		}
		if (a[1][2] != 0) {
			f[1][2][2]--;
		}
		if (a[1][3] != 0) {
			f[1][3][3]-- ;
		}
		for (int i = 2; i <= n; i++) {
			for (int l = 1; l <= 3; l++) {
				int fl = -1;
				for (int j = 1; j <= 3; j++) {
					f[i][l][j] = f[i - 1][l][j];
					if (f[i - 1][l][j]) {
						if (dp[i][l] < dp[i - 1][j] + a[i][l]) {
							dp[i][l] = dp[i - 1][j] + a[i][l];
							fl = j;
						}
					} else {
						dp[i][l] = dp[i - 1][j];
					}
				}
				if (fl != -1) {
					f[i][l][fl]--;
				}

			}
		}
		cout << max(max(dp[n][1], dp[n][2]), dp[n][3]) << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}