#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[11][11], cntn, cntm, xm, ccnt;
int aa[110];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> aa[i];
	}
	xm = aa[1];
	sort(aa + 1, aa + n *m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; i <= n; j++) {
				ccnt++;
				a[i][j] = aa[ccnt];
			}
		} else {
			for (int j = n; i >= 1; j--) {
				ccnt++;
				a[i][j] = aa[ccnt];
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cntm = i;
		if (i % 2 == 1) {
			cntn = 0;
			for (int j = 1; j <= n; j++) {
				cntn = j;
				if (a[i + 1][j + 1] == xm) {
					cout << cntm << ' ' << cntn;
					return 0;
				}
			}
		} else {
			cntn = n;
			for (int j = n; j >= 1; j--) {
				cntn = j;
				if (a[i + 1][j + 1] == xm) {
					cout << cntm << ' ' << cntn;
					return 0;
				}
			}
		}
	}
	cout << cntm << ' ' << cntn;
	return 0;
}
