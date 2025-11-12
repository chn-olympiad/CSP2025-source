#include <bits/stdc++.h>
using namespace std;
int am[100010][5], bm[100010][5], cm[100010][5], zj[100010][5], pd[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t1;
	cin >> t1;
	for (int i = 1; i <= t1; i++) {
		long long n, a1 = 0, b1 = 0, c1 = 0, ans = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> am[j][1] >> bm[j][1] >> cm[j][1];
			am[j][2] = j;
			bm[j][2] = j;
			cm[j][2] = j;
			if (am[j][1] > bm[j][1]) {
				if (am[j][1] > cm[j][1]) {
					ans += am[j][1];
					a1++;
					pd[j] = 1;
				}
				if (am[j][1] < cm[j][1]) {
					ans += cm[j][1];
					c1++;
					pd[j] = 3;
				}
			}
			if (am[j][1] < bm[j][1]) {
				if (bm[j][1] > cm[j][1]) {
					ans += bm[j][1];
					b1++;
					pd[j] = 2;
				}
				if (bm[j][1] < cm[j][1]) {
					ans += cm[j][1];
					c1++;
					pd[j] = 3;
				}
			}
		}
		if (a1 > n / 2) {
			for (int j = 1; j <= n; j++) {
				if (pd[j] != 1) {
					zj[j][1] = -2100000000;
					continue;
				}
				if (bm[j][1] - am[j][1] > cm[j][1] - am[j][1]) {
					zj[j][1] = bm[j][1] - am[j][1];
					zj[j][2] = j;
				} else {
					zj[j][1] = cm[j][1] - am[j][1];
					zj[j][2] = j;
				}
			}
			for (int j = n; j >= 1; j--) {
				for (int k = 1; k <= j; k++) {
					if (zj[j][1] > zj[k][1]) {
						int a = zj[j][1];
						zj[j][1] = zj[k][1];
						zj[k][1] = a;
						int b = zj[j][2];
						zj[j][2] = zj[k][2];
						zj[k][2] = b;
					}

				}
			}
			for (int j = 1; a1 > n / 2; j++) {
				//ans -= am[zj[j][2]][1];
				a1--;
				ans += zj[j][1];
				//cout << zj[j][2] << " ";
			}
		}
		if (b1 > n / 2) {
			for (int j = 1; j <= n; j++) {
				if (pd[j] != 2) {
					zj[j][1] = -2100000000;
					continue;
				}
				if (am[j][1] - bm[j][1] > cm[j][1] - bm[j][1]) {
					zj[j][1] = am[j][1] - bm[j][1];
					zj[j][2] = j;
				} else {
					zj[j][1] = cm[j][1] - bm[j][1];
					zj[j][2] = j;
				}
			}
			for (int j = n; j >= 1; j--) {

				for (int k = 1; k <= j; k++) {
					if (zj[j][1] > zj[k][1]) {
						int a = zj[j][1];
						zj[j][1] = zj[k][1];
						zj[k][1] = a;
						int b = zj[j][2];
						zj[j][2] = zj[k][2];
						zj[k][2] = b;
					}

				}
			}
			for (int j = 1; b1 > n / 2; j++) {
				//ans -= bm[zj[j][2]][1];
				b1--;
				ans += zj[j][1];
				//cout << zj[j][2] << " ";
			}
		}
		if (c1 > n / 2) {
			for (int j = 1; j <= n; j++) {
				if (pd[j] != 3) {
					zj[j][1] = -2100000000;
					continue;
				}
				if (bm[j][1] - cm[j][1] > am[j][1] - cm[j][1]) {
					zj[j][1] = bm[j][1] - cm[j][1];
					zj[j][2] = j;
				} else {
					zj[j][1] = am[j][1] - cm[j][1];
					zj[j][2] = j;
				}
			}
			for (int j = n; j >= 1; j--) {

				for (int k = 1; k <= j; k++) {
					if (zj[j][1] > zj[k][1]) {
						int a = zj[j][1];
						zj[j][1] = zj[k][1];
						zj[k][1] = a;
						int b = zj[j][2];
						zj[j][2] = zj[k][2];
						zj[k][2] = b;
					}

				}
			}
			for (int j = 1; c1 > n / 2; j++) {
				//ans -= cm[zj[j][2]][1];
				c1--;
				ans += zj[j][1];
				//cout << zj[j][2] << " ";
			}
		}
		cout << ans << endl;
	}
	return 0;
}