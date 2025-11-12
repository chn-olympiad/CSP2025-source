#include <bits/stdc++.h>
using namespace std;
long long T, n, a[1000005][5], q[1000005][5], sn, d[15], o, ma = -1, s, h, p;

struct node {
	long long f, u;
} c1[1000005];

bool cmp(node bb, node b) {
	return bb.f < b.f;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			if (a[j][1] >= a[j][2] && a[j][2] >= a[j][3]) {
				q[j][1] = 1;
				c1[j].f = a[j][1] - a[j][2], c1[j].u = 1;
			} else if (a[j][1] >= a[j][2] && a[j][2] <= a[j][3] && a[j][1] >= a[j][3]) {
				q[j][1] = 1;
				c1[j].f = a[j][1] - a[j][3], c1[j].u = 1;
			} else if (a[j][1] <= a[j][2] && a[j][2] <= a[j][3]) {
				q[j][1] = 3;
				c1[j].f = a[j][3] - a[j][2], c1[j].u = 3;
			} else if (a[j][1] <= a[j][2] && a[j][2] >= a[j][3] && a[j][1] <= a[j][3]) {
				q[j][1] = 2;
				c1[j].f = a[j][2] - a[j][3], c1[j].u = 2;
			} else if (a[j][1] <= a[j][2] && a[j][2] >= a[j][3] && a[j][3] <= a[j][1]) {
				q[j][1] = 2;
				c1[j].f = a[j][2] - a[j][1], c1[j].u = 2;
			} else if (a[j][1] >= a[j][2] && a[j][2] <= a[j][3] && a[j][1] <= a[j][3]) {
				q[j][1] = 3;
				c1[j].f = a[j][3] - a[j][1], c1[j].u = 3;
			}
		}
		for (int k = 1; k <= n; k++) {
			if (q[k][1] == 1)
				d[1]++;
			else if (q[k][1] == 2)
				d[2]++;
			else
				d[3]++;
		}
		ma = max(d[1], max(d[2], d[3]));
		if (d[1] == ma)
			o = 1;
		else if (ma == d[2])
			o = 2;
		else
			o = 3;
		sn = 0;
		for (int j = 1; j <= n; j++) {
			sn += a[j][q[j][1]];
		}
		if (ma < n / 2) {
			cout << sn << endl;
		} else {
			p = 1;
			sort(c1 + 1, c1 + 1 + n, cmp);
			while (ma > n / 2) {
				if (c1[p].u == o) {
					ma--;
					sn -= c1[p].f;
				}
				p++;
			}
			cout << sn << endl;
		}
		sn = 0, ma = -1;
		memset(d, 0, sizeof(d));
		memset(a, 0, sizeof(a));
		memset(c1, 0, sizeof(c1));
		memset(q, 0, sizeof(q));
	}
	return 0;
}
