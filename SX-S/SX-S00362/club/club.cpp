#include <bits/stdc++.h>
using namespace std;

struct my {
	int x, y, z;
} a[100005];
int dp[205][205][205];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = n / 2; j >= 1; j--) {
				for (int k = n / 2; k >= 1; k--) {
					for (int l = n / 2; l >= 1; l--) {
						dp[j][k][l] = max(dp[j][k][l], max(dp[j - 1][k][l] + a[i].x, max(dp[j][k - 1][l] + a[i].y, dp[j][k][l - 1] + a[i].z)));
						//cout << dp[j][k][l] << endl;
					}

				}
			}

		}
		cout << dp[n / 2][n / 2][n / 2] << endl;
	}
	return 0;
}/*
1 4
4 0 0
10 9 8
7 3 6
1 5 9
*/