#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010][3];
struct node{
	ll x, s1, s2, s3;
}dp[100010][3];
int x[6], y[6];
dp1[]
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, l;
		cin >> n;
		l = n / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				if (dp[i - 1][0].s1 == l - 1) {
					if (dp[i - 1][0].x > dp[x[0]][y[0]].x) {
						
					}
				}
				if (i > l) {
					ll b, c, d;
					if (j == 0) {
						if (dp[i - 1][0].s1 == l) {
							if (x[3]) {
								b = dp[x[0]]
							}
						}
					}
				} else {
					ll b = dp[i - 1][(j + 1) % 3].x + a[i][j], c = dp[i - 1][(j + 2) % 3].x + a[i][j], d = dp[i - 1][j].x + a[i][j];
					ll ma = max(max(b, c), d);
					dp[i][j].x = ma;
					if (ma == b) {
						if (j == 0) {
							dp[i][j].s1 = dp[i - 1][(j + 1) % 3].s1 + 1;
							dp[i][j].s2 = dp[i - 1][(j + 1) % 3].s2;
							dp[i][j].s3 = dp[i - 1][(j + 1) % 3].s3;
						}
						if (j == 1) {
							dp[i][j].s1 = dp[i - 1][(j + 1) % 3].s1;
							dp[i][j].s2 = dp[i - 1][(j + 1) % 3].s2 + 1;
							dp[i][j].s3 = dp[i - 1][(j + 1) % 3].s3;
						}
						if (j == 2) {
							dp[i][j].s1 = dp[i - 1][(j + 1) % 3].s1;
							dp[i][j].s2 = dp[i - 1][(j + 1) % 3].s2;
							dp[i][j].s3 = dp[i - 1][(j + 1) % 3].s3 + 1;
						}
					} else if (ma == c) {
						if (j == 0) {
							dp[i][j].s1 = dp[i - 1][(j + 2) % 3].s1 + 1;
							dp[i][j].s2 = dp[i - 1][(j + 2) % 3].s2;
							dp[i][j].s3 = dp[i - 1][(j + 2) % 3].s3;
						}
						if (j == 1) {
							dp[i][j].s1 = dp[i - 1][(j + 2) % 3].s1;
							dp[i][j].s2 = dp[i - 1][(j + 2) % 3].s2 + 1;
							dp[i][j].s3 = dp[i - 1][(j + 2) % 3].s3;
						}
						if (j == 2) {
							dp[i][j].s1 = dp[i - 1][(j + 2) % 3].s1;
							dp[i][j].s2 = dp[i - 1][(j + 2) % 3].s2;
							dp[i][j].s3 = dp[i - 1][(j + 2) % 3].s3 + 1;
						}
					} else if (ma == d) {
						if (j == 0) {
							dp[i][j].s1 = dp[i - 1][j].s1 + 1;
							dp[i][j].s2 = dp[i - 1][j].s2;
							dp[i][j].s3 = dp[i - 1][j].s3;
						}
						if (j == 1) {
							dp[i][j].s1 = dp[i - 1][j].s1;
							dp[i][j].s2 = dp[i - 1][j].s2 + 1;
							dp[i][j].s3 = dp[i - 1][j].s3;
						}
						if (j == 2) {
							dp[i][j].s1 = dp[i - 1][j].s1;
							dp[i][j].s2 = dp[i - 1][j].s2;
							dp[i][j].s3 = dp[i - 1][j].s3 + 1;
						}
					}
				}
			}
		}
	}
	return 0;
}
