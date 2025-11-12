#include <bits/stdc++.h>
using namespace std;
long long a[5][100010];
long long x[5];
long long dp[5][100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	long long t;
	scanf("%lld", &t);

	for (long long i = 1; i <= t; i++) {

		long long n;
		scanf("%lld", &n);

		for (long long j = 1; j <= n; j++) {//输入
			for (long long k = 1; k <= 3; k++) {
				cin >> a[j][k];//找见错处了
				dp[j][k] = a[j][k];
			}
		}

		for (int j = 1; j <= n; j++) {
			int jj = 1;
			for (int k = 1; k <= 3; k++) {
				if (x[k] + 1 <= n / 2 && jj != k) {
					dp[j][k] = max(dp[j][k - 1], dp[j - 1][jj] + a[j][k]);
					jj = k;
				}
			}
			x[jj]++;
		}
		cout << dp[n][3] << endl;
	}
	return 0;
}
