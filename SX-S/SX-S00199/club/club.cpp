#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], c[100010];
int dp[1010][1010][1010];
int maxx = -1;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			for (int q = n; q >= 1; q--) {
				for (int w = n ; w >= 1; w--) {
					for (int e = n; e >= 1; e--) {
						if (q > n / 2 || w > n / 2 || e > n / 2 || e == 0) {
							continue;
						}
						dp[q][w][e] = max(dp[q - 1][w][e] + a[i], max(dp[q][w - 1][e] + a[i], dp[q][w][e - 1] + a[i]));
						maxx = max(maxx, dp[q][w][e]);
					}


				}
			}
		}

	}
	cout << maxx;
	return 0;
}
