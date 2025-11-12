#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T;
int dp[100100][4], lik[101000][4], wor[101000][4][4], wmzl[101000];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for (int op = 1; op <= T; op++) {
		int n, flag = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++) {
				cin >> lik[i][j];
				if (j == 2 && lik[i][j] != 0)
					flag = 1;
				if (j == 3 && lik[i][j] != 0)
					flag = 1;
				if (j == 1)
					wmzl[i] = lik[i][j];
			}
		//cout << flag << "aaaaaaaaaaaaa ";
		if (flag == 0) {
			sort(wmzl + 1, wmzl + 1 + n, cmp);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += wmzl[i];
			}
			cout << ans << '\n';
			continue;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				dp[i][j] = 0;
			}
		}
		/*
		wor[1][1][1] = 1, wor[1][1][2] = 0, wor[1][1][3] = 0;
		wor[1][2][1] = 0, wor[1][2][2] = 1, wor[1][2][3] = 0;
		wor[1][3][1] = 0, wor[1][3][2] = 0, wor[1][3][3] = 1;
		dp[1][1] = lik[1][1], dp[1][2] = lik[1][2], dp[1][3] = lik[1][3];
		*/
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				int opt1 = 0, opt2 = 0, opt3 = 0;
				if (wor[i - 1][1][j] < n / 2 && dp[i - 1][1] + lik[i][j] >= dp[i][j]) {
					opt1 = max(opt1, dp[i - 1][1] + lik[i][j]);
				}

				if (wor[i - 1][2][j] < n / 2 && dp[i - 1][2] + lik[i][j] >= dp[i][j]) {
					opt2 = max(opt2, dp[i - 1][2] + lik[i][j]);
				}

				if (wor[i - 1][3][j] < n / 2 && dp[i - 1][3] + lik[i][j] >= dp[i][j]) {
					opt3 = max(opt3, dp[i - 1][3] + lik[i][j]);
				}
				if (opt1 >= opt2 && opt1 >= opt3 && opt1 != -1) {
					dp[i][j] = opt1;
					wor[i][j][1] = wor[i - 1][1][1];
					wor[i][j][2] = wor[i - 1][1][2];
					wor[i][j][3] = wor[i - 1][1][3];
					wor[i][j][j]++;
					//cout << i << " " << j << " " << wor[i][j][1] << wor[i][j][2] << wor[i][j][3] << '\n';
					//	wor[i][j][j]++;
					continue;
				}

				if (opt2 >= opt1 && opt2 >= opt3 && opt2 != -1) {
					dp[i][j] = opt2;
					wor[i][j][1] = wor[i - 1][2][1];
					wor[i][j][2] = wor[i - 1][2][2];
					wor[i][j][3] = wor[i - 1][2][3];
					wor[i][j][j]++;
					//cout << i << " " << j << " " << wor[i][j][1] << wor[i][j][2] << wor[i][j][3] << '\n';

					//	wor[i][j][j]++;
					continue;
				}
				if (opt3 >= opt1 && opt3 >= opt2 && opt3 != -1) {
					dp[i][j] = opt3;
					wor[i][j][1] = wor[i - 1][3][1];
					wor[i][j][2] = wor[i - 1][3][2];
					wor[i][j][3] = wor[i - 1][3][3];
					wor[i][j][j]++;
					//cout << i << " " << j << " " << wor[i][j][1] << wor[i][j][2] << wor[i][j][3] << '\n';

					//	wor[i][j][j]++;
					continue;
				}
			}
		}
		//cout << "'''''''''''''''''''''''''''''" << '\n';

		if (dp[n][1] >= dp[n][2] && dp[n][1] >= dp[n][3]) {
			cout << dp[n][1] << '\n';
			continue;
		}
		if (dp[n][2] >= dp[n][1] && dp[n][2] >= dp[n][3]) {
			cout << dp[n][2] << '\n';
			continue;
		}
		if (dp[n][3] >= dp[n][2] && dp[n][3] >= dp[n][1]) {
			cout << dp[n][3] << '\n';
			continue;
		}

	}
	return 0;
}
