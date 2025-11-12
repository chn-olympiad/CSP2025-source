#include <bits/stdc++.h>
using namespace std;

struct s {
	int o, w, pk;
} p[100010];
int a[3][100010], ww[3], toa[3][50010];
bool b[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, l = 0, i, j, v;
	cin >> t;
	for (i = 1; i <= t; i++) {
		cin >> n;
		memset(p, 0, sizeof(p));
		memset(a, 0, sizeof(a));
		memset(ww, 0, sizeof(ww));
		memset(toa, 0, sizeof(toa));
		memset(b, 0, sizeof(b));
		l = 0;
		for (j = 1; j <= n; j++) {
			cin >> a[0][j] >> a[1][j] >> a[2][j];
			p[j].o = max(a[0][j], max(a[1][j], a[2][j]));
			if (p[j].o == a[0][j]) {
				p[j].w = 0;
				ww[0]++;
				toa[0][ww[0]] = j;
			} else if (p[j].o == a[1][j]) {
				p[j].w = 1;
				ww[1]++;
				toa[1][ww[1]] = j;
			} else {
				p[j].w = 2;
				ww[2]++;
				toa[2][ww[2]] = j;
			}
			if (ww[p[j].w] > n / 2) {
				int sk = p[j].w, w1 = sk == 0 ? 1 : 0, w2 = sk == 2 ? 1 : 2;
				int c, maxc = 100000000, maw;
				int c1 = a[p[j].w][j] - max(a[w1][j], a[w2][j]);
				for (v = 1; v <= n / 2; v++) {
					c = a[p[j].w][toa[sk][v]] - max(a[w1][toa[sk][v]], a[w2][toa[sk][v]]);
					//	cout << c << " ";
					if (c < maxc) {
						maxc = c;
						maw = toa[sk][v];
					}
				}
				//	cout << c1 << " " << maxc << endl;
				if (c1 >=  maxc) {
					int w3 = b[maw] ? p[maw].pk : (a[w1][toa[sk][maw]] > a[w2][toa[sk][maw]] ? w1 : w2);
					p[maw].pk = w1 + w2 - w3;
					p[maw].o = a[w3][maw];
					b[maw] = 1;
					p[maw].w = w3;
					toa[sk][maw] = j;
					ww[w3]++;
					toa[w3][ww[w3]] = maw;
				} else {
					int w3 = b[j] ? p[j].pk : (a[w1][toa[sk][j]] > a[w2][toa[sk][j]] ? w1 : w2);
					p[j].pk = w1 + w2 - w3;
					p[j].o = a[w3][j];
					b[j] = 1;
					p[j].w = w3;
					ww[w3]++;
					toa[w3][ww[w3]] = j;
				}
			}/*
			for (v = 1; v <= j; v++) {
				cout << p[v].w;
			}
			cout << endl;*/
		}
		for (j = 1; j <= n; j++) {
			l += a[p[j].w][j];
			//	cout << a[p[j].w][j];
		}
		cout << l << endl;
	}
	return 0;
}
