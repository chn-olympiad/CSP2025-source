#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a = 0, b = 0, c = 0;
		int a1[n + 1], a2[n + 1], a3[n + 1];
		vector<int> za, zb, zc;
		za.push_back(0);
		zb.push_back(0);
		zc.push_back(0);
		int num = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			if (a1[i] >= a2[i] && a1[i] >= a3[i]) {
				za.push_back(i);
				a++;
			} else if (a2[i] >= a1[i] && a2[i] >= a3[i]) {
				zb.push_back(i);
				b++;
			} else {
				zc.push_back(i);
				c++;
			}
		}
		int ma = 0, mb = 0, mc = 0;
		if (a > n / 2) {
			for (int i = 1; i <= a; i++) {
				for (int j = i + 1; j <= a; j++) {
					if (min(a1[za[i]] - a2[za[i]], a1[za[i]] - a3[za[i]]) < min(a1[za[j]] - a2[za[j]], a1[za[j]] - a3[za[j]])) {
						swap(za[i], za[j]);
					}

				}
			}
			for (int i = n / 2 + 1; i <= a; i++) {
				if (a2[za[i]] >= a3[za[i]] && b < n / 2) {
					//cout << za[i] << ' ';
					zb.push_back(za[i]);
					ma++;
					b++;
					//cout << za[i];
				} else {
					zc.push_back(za[i]);
					ma++;
					c++;
				}
			}
		}
		a -= ma;
		//cout << a << ' ' << b << ' ' << c << endl;
		if (b > n / 2) {
			for (int i = 1; i <= b; i++) {
				for (int j = i + 1; j <= b; j++) {
					if (min(a2[zb[i]] - a1[zb[i]], a2[zb[i]] - a3[zb[i]]) < min(a2[zb[j]] - a1[zb[j]], a2[zb[j]] - a3[zb[j]]))
						swap(zb[i], zb[j]);
				}
			}
			for (int i = n / 2 + 1; i <= b; i++) {
				if (a1[zb[i]] >= a3[zb[i]] && a < n / 2) {
					za.push_back(zb[i]);
					mb++;
					a++;
				} else {
					zc.push_back(zb[i]);
					mb++;
					c++;
				}
			}
		}
		b -= mb;
		if (c > n / 2) {
			for (int i = 1; i <= c; i++) {
				for (int j = i + 1; j <= c; j++) {
					if (min(a3[zc[i]] - a1[zc[i]], a3[zc[i]] - a2[zc[i]]) < min(a3[zc[j]] - a1[zc[j]], a3[zc[j]] - a2[zc[j]]))
						swap(zc[i], zc[j]);
				}
			}
			for (int i = n / 2 + 1; i <= c; i++) {
				if (a1[zc[i]] >= a2[zc[i]] && a < n / 2) {
					za.push_back(zc[i]);
					mc++;
					a++;
				} else {
					zb.push_back(zc[i]);
					mc++;
					b++;
				}
			}
		}
		c -= mc;
		for (int i = 1; i <= a; i++) {
			num += a1[za[i]];
			//cout << "a:" << za[i] << ' ';
		}
		for (int i = 1; i <= b; i++) {
			num += a2[zb[i]];
			//cout << "b:" << zb[i] << ' ';
		}
		for (int i = 1; i <= c; i++) {
			num += a3[zc[i]];
			//cout << "c:" << zc[i] << ' ';
		}
		cout << num << endl;
	}
	return 0;
}
