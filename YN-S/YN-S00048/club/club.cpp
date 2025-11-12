#include <bits/stdc++.h>
using namespace std;
int a[100050][5], maxn[100050], f[3], zd2 = -1, zd3 = -1;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, l, di2, di3, sum = 0, x, y, z, nowmaxmin = INT_MAX, x3, x2;
		cin >> n;
		f[1] = 0, f[2] = 0, f[3] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
//			if (a[i][1] > a[i][2] > a[i][3])
//				maxn[i] = a[i][1];
//			if (a[i][1] > a[i][3] > a[i][2])
//				maxn[i] = a[i][1];
//			if (a[i][2] > a[i][3] > a[i][1])
//				maxn[i] = a[i][2];
//			if (a[i][2] > a[i][1] > a[i][3])
//				maxn[i] = a[i][2];
//			if (a[i][3] > a[i][2] > a[i][1])
//				maxn[i] = a[i][3];
//			if (a[i][3] > a[i][1] > a[i][2])
//				maxn[i] = a[i][3];
			maxn[i] = max(a[i][1], a[i][2]);
			maxn[i] = max(maxn[i], a[i][3]);
			if (maxn[i] == a[i][1])
				f[1]++, l = 1;
			else if (maxn[i] == a[i][2])
				f[2]++, l = 2;
			else if (maxn[i] == a[i][3])
				f[3]++, l = 3;
			if (l == 3) {
				if (a[i][1] >= a[i][2])
					di2 = 1, di3 = 2;
				else
					di2 = 2, di3 = 1;
			} else if (l == 1) {
				if (a[i][2] >= a[i][3])
					di2 = 2, di3 = 3;
				else
					di2 = 3, di3 = 2;
			} else if (l == 2) {
				if (a[i][1] >= a[i][3])
					di2 = 1, di3 = 3;
				else
					di2 = 3, di3 = 1;
			}
			zd2 = max(zd2, a[i][di2]);
			if (zd2 == a[i][di2])
				x = i;
			zd3 = max(zd3, a[i][di3]);
			if (zd3 == a[i][di3])
				y = i;
			nowmaxmin = min(nowmaxmin, maxn[i]);
			if (nowmaxmin == maxn[i])
				z = i, x2 = di2, x3 = di3;
//			cout << nowmaxmin << " " << x << " " << y << " " << z << " " << x2 << " " << x3 << endl;
			if (f[1] * 2 <= n && f[2] * 2 <= n && f[3] * 2 <= n)
				sum += maxn[i];
			else {
				if (f[1] * 2 > n) {
					if (maxn[i] > nowmaxmin) {
						sum -= nowmaxmin;
						sum += maxn[i];
						di2 = x2, di3 = x3;
					} else if (maxn[i] <= nowmaxmin) {
						if (nowmaxmin + zd2 > sum)
							sum = nowmaxmin + zd2;
					} else if (f[di2] + 1 <= n / 2) {
						sum += a[i][di2];
						f[di2]++, f[1]--;
					} else if (f[di2] + 1 > n / 2)
						sum += a[i][di3];
					f[di3]++, f[1]--;
				} else if (f[2] * 2 > n) {
					if (maxn[i] > nowmaxmin) {
						sum -= nowmaxmin;
						sum += maxn[i];
						di2 = x2, di3 = x3;
					} else if (maxn[i] <= nowmaxmin) {
						if (nowmaxmin + zd2 > sum)
							sum = nowmaxmin + zd2;
					} else if (f[di2] + 1 <= n / 2) {
						sum += a[i][di2];
						f[di2]++, f[2]--;
					} else if (f[di2] + 1 > n / 2)
						sum += a[i][di3];
					f[di3]++, f[2]--;
				} else if (f[3] * 2 > n) {
					if (maxn[i] > nowmaxmin) {
						sum -= nowmaxmin;
						sum += maxn[i];
						di2 = x2, di3 = x3;
					} else if (maxn[i] <= nowmaxmin) {
						if (nowmaxmin + zd2 > sum)
							sum = nowmaxmin + zd2;
					} else if (f[di2] + 1 <= n / 2) {
						sum += a[i][di2];
						f[di2]++, f[3]--;
					} else if (f[di2] + 1 > n / 2)
						sum += a[i][di3];
					f[di3]++, f[3]--;
				}
			}
		}
		cout << sum << '\n';
	}
	return 0;
}