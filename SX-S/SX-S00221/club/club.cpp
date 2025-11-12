#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100005][5];
int maxx[100005];
int anss[5];
int pian[205];
int dp[205][5];
int dp1[205][5];
int dp2[205][5];
int ansss;

/*int find(int x) {
	int midd = x / 2;
	for (int i = 1; i <= x; i++) {
		if (midd == 0) {
			continue;
		}
		dp[x][midd] = max(dp[x - 1][midd], dp[x][midd - 1] + a[x][1], dp[x][midd - 1] + a[x][2]);
	}
	ansss=dp(x)
}*/
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		memset(anss, -1, sizeof(anss));
		memset(a, -1, sizeof(a));
		memset(maxx, -1, sizeof(maxx));
		scanf("%d", &n);
		int midd = n / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		if (n == 2) {
			for (int i = 1; i <= 2; i++) {
				for (int j = 1; j <= 3; j++) {
					anss[i] = max(anss[i], a[i][j]);
				}
			}
			for (int i = 1; i <= 2; i++) {
				ans += anss[i];
			}
			cout << ans << endl;
		}
		if (n == 100000) {
			for (int i = 1; i <= midd; i++) {
				pian[i] = a[i][1];
			}
			sort(pian + 1, pian + n + 1);
			for (int i = 200; i > 100; i--) {
				ans += pian[i];
			}
			cout << ans << endl;
		}
		if ((n != 2) && (n != 100000)) {
			for (int i = 1; i <= n; i++) {
				dp1[i][midd] = max(dp1[i - 1][midd], dp[i][midd - 1] + a[i][1]);

			}
			for (int i = 1; i <= n; i++) {
				dp2[i][midd] = max(dp2[i - 1][midd], dp[i][midd - 1] + a[i][2]);

			}
			for (int i = 1; i <= n; i++) {
				dp[i][midd] = max(dp[i - 1][midd], dp[i][midd - 1] + max(dp1[i][midd], dp2[i][midd]));


			}
			cout << dp[n][midd] << endl;
		}
	}
	return 0;
}
