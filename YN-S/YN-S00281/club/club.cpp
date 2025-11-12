#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 78;
long long a[N][9];
long long dp[202][202][202];
long long n;
long long T;
long long aa[N];

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	//
	//
	cin >> T;
	while (T--) {
		long long ans = 0;
		bool f = true;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			aa[i] = a[i][1];
			if (a[i][2] != 0 || a[i][3] != 0) {
				f = false;
			}
		}
		if (f) {
			sort(aa + 1, aa + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += aa[i];
		} else {
			for (long long i = 1; i <= n; i++) {
				for (long long j = 0; j <= min(n / 2, i); j++) {
					for (long long k = 0; k <= min(n / 2, i - j); k++) {
						if (i - j - k + 1 <= n / 2)
							dp[j][k][i - j - k + 1] = dp[j][k][i - j - k] + a[i][3];
						if (j + 1 <= n / 2)
							dp[j + 1][k][i - j - k] = dp[j][k][i - j - k] + a[i][1];
						if (k + 1 <= n / 2)
							dp[j][k + 1][i - j - k] = dp[j][k][i - j - k] + a[i][2];
						ans = max({dp[j][k][i - j - k + 1], dp[j + 1][k][i - j - k], dp[j][k + 1][i - j - k], ans});
					}
				}
			}
		}
		cout << ans << endl;
	}


	return 0;
}