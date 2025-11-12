#include <bits/stdc++.h>
using namespace std;
int a[10005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	int s[t + 5] = {0};
	for (int z = 1; z <= t; z++) {
		int n = 0;
		cin >> n;
		int x1 = n / 2, x2 = n / 2, x3 = n / 2;
		int xzd1 = 9999, xzd2 = 9999, xzd3 = 9999;
		int pos = 0;
		for (int i = 1; i <= n; i++) {//4ÂÖ
			for (int j = 1; j <= 3; j++) {//3Öµ
				cin >> a[j];
			}
			xzd1 = min(a[1], xzd1);
			xzd2 = min(a[2], xzd2);
			xzd3 = min(a[3], xzd2);
			int zd = 0;
			pos = 2;
			a[4] = -1;
			for (int q = 1; q <= 3; q++) {
				zd = max(a[q + 1], a[q]);
			}//zd
			for (int q = 1; q <= 3; q++) {
				if (a[q] == zd)
					pos = q;
			}//zd wz
			if (pos == 1) {
				if (x1 > 0) {
					x1--;
					s[z] += zd;
				} else {
					s[z] = s[z] + zd - xzd1;
				}
				if (pos == 2) {
					if (x2 > 0) {
						x2--;
						s[z] += zd;
					} else {
						s[z] = s[z] + zd - xzd2;
					}
				}
				if (pos == 3) {
					if (x3 > 0) {
						x3--;
						s[z] += zd;
					} else {
						s[z] = s[z] + zd - xzd3;
					}
				}
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		cout << s[i] << endl;
	}
	return 0;
}
//2
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
