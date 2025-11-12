#include <bits/stdc++.h>
using namespace std;
int n, v1[100005], v2[100005], v3[100005];
int dp1[50005], dp2[50005], dp3[50005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		memset(dp1, 0, sizeof dp1);
		memset(dp2, 0, sizeof dp2);
		memset(dp3, 0, sizeof dp3);
		int mx1 = 0, mx2 = 0, mx3 = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> v1[j] >> v2[j] >> v3[j];
		}
		for (int j = 1; j <= n; j++) {
			for (int o = n / 2; o >= 1; o--) {
//				int x = dp1[o - 1] + v1[j], y = dp2[o - 1] + v2[j], z = dp3[o - 1] + v3[j];
				int x1, y1, z1;
				x1 = dp1[o - 1] + v1[j];
				y1 = dp2[o - 1] + v2[j];
				z1 = dp3[o - 1] + v3[j];
				if (x1 >= y1 && x1 >= z1) {
					dp1[o] = max(dp1[o], dp1[o - 1] + v1[j]);
//					mx1 = max(mx1, x1);
				} else if (y1 >= z1 && y1 > x1) {
					dp2[o] = max(dp2[o], dp2[o - 1] + v2[j]);
//					mx1 = max(mx1, y1);
				} else if (z1 > y1 && z1 > x1) {
					dp3[o] = max(dp3[o], dp3[o - 1] + v3[j]);
//					mx1 = max(mx1, z1);
				}

			}
		}
		for (int j = 1; j <= n / 2; j++) {
			mx1 = max(mx1, dp1[j]);
			mx2 = max(mx2, dp2[j]);
			mx3 = max(mx3, dp3[j]);
//			cout << dp1[j];
		}
		cout << mx1 + mx2 + mx3 << endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
