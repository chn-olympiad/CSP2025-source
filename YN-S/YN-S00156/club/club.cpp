#include <bits/stdc++.h>
using namespace std;
int a[100001][11], b[100001], c[100001], d[100001], ba[100001], ca[100001], da[100001], z[100001];

bool cmp1(int x, int y) {
	return a[x][1] < a[y][1];
}

bool cmp2(int x, int y) {
	return a[x][2] < a[y][2];
}

bool cmp3(int x, int y) {
	return a[x][3] < a[y][3];
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		int m, pj, c1 = 0, c2 = 0, c3 = 0;
		cin >> m;
		pj = m / 2;

		for (int j = 1; j <= m; j++) {

			b[j] = j;
			c[j] = j;
			d[j] = j;
			cin >> a[j][1];
			cin >> a[j][2];
			cin >> a[j][3];
			a[j][4] = a[j][2] - a[j][1];
			a[j][5] = a[j][3] - a[j][1];
			a[j][6] = a[j][1] - a[j][2];
			a[j][7] = a[j][3] - a[j][2];
			a[j][8] = a[j][1] - a[j][3];
			a[j][9] = a[j][2] - a[j][3];
		}

		sort(b + 1, b + 1 + m, cmp1);
		sort(c + 1, c + 1 + m, cmp2);
		sort(d + 1, d + 1 + m, cmp3);
		int ls = 0, o = 1, p = 1, l = 1;

		for (int j = 1; j <= m; j++) {


			if (max(a[d[j]][3], max(a[b[j]][1], a[c[j]][2])) == a[c[j]][2] && a[c[j]][10] == 0 && c2 < pj) {
				ls += a[c[j]][2];
				ca[o++] = c[j];
				c2++;
			} else if (max(a[d[j]][3], max(a[b[j]][1], a[c[j]][2])) == a[b[j]][1] && a[b[j]][10] == 0 && c1 < pj) {
				ls += a[b[j]][1];
				ba[p++] = b[j];
				c1++;
			} else if (max(a[d[j]][3], max(a[b[j]][1], a[c[j]][2])) == a[d[j]][3] && a[d[j]][10] == 0 && c3 < pj) {
				c3++;
				da[l++] = d[j];
				ls += a[d[j]][3];
			} else {
				continue;
			}
		}

		int ls2 = 40001;

		for (int j = 1; j < p; j++) {

			for (int k = 1; k < o; k++) {

				if (a[ba[j]][4] + a[ca[k]][6] > 0) {
					ls2 = min(ls2, a[ba[j]][4] + a[ca[k]][6]);
				}
			}
		}

		if (ls2 != 40001) {
			ls += ls2;
			ls2 = 40001;
		}

		for (int j = 1; j < p; j++) {

			int ls2 = 40001;

			for (int k = 1; k < l; k++) {

				if (a[ba[j]][4] + a[da[k]][8] > 0) {
					ls2 = min(ls2, a[ba[j]][4] + a[da[k]][8]);
				}
			}
		}

		if (ls2 != 40001) {
			ls += ls2;
			ls2 = 40001;
		}

		for (int j = 1; j < o; j++) {

			int ls2 = 40001;

			for (int k = 1; k < l; k++) {

				if (a[ca[j]][6] + a[da[k]][8] > 0) {
					ls2 = min(ls2, a[ca[j]][6] + a[da[k]][8]);
				}
			}
		}

		if (ls2 != 40001) {
			ls += ls2;
		}

		cout << ls << endl;
	}

	return 0;
}