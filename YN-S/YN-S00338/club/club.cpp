//ssj T1
#include <bits/stdc++.h>
using namespace std;

int T;
int k;
struct acb {
	int x, y, z;
} a[100010], b[100010], c[100010];
int n, m, nm;

bool cmpa(acb x, acb y) {
	return min(x.x - x.y, x.x - x.z) > min(y.x - y.y, y.x - y.z);
}

bool cmpb(acb x, acb y) {
	return min(x.y - x.x, x.y - x.z) > min(y.y - y.x, y.y - y.z);
}

bool cmpc(acb x, acb y) {
	return min(x.z - x.y, x.z - x.x) > min(y.z - y.y, y.z - y.x);
}
int sam;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			if (x >= y && x >= z) {
				a[++n].x = x;
				a[n].y = y;
				a[n].z = z;
			}
			if (y > x && y > z) {
				b[++m].x = x;
				b[m].y = y;
				b[m].z = z;
			}
			if (z > y && z > x) {
				c[++nm].x = x;
				c[nm].y = y;
				c[nm].z = z;
			}
		}
		if (n > k / 2) {
			sort(a + 1, a + n + 1, cmpa);
			while (n > k / 2) {
				if (a[n].y >= a[n].z) {
					b[++m].x = a[n].x;
					b[m].y = a[n].y;
					b[m].z = a[n].z;
				} else {
					c[++nm].x = a[n].x;
					c[nm].y = a[n].y;
					c[nm].z = a[n].z;
				}
				n--;
			}
		}
		if (m > k / 2) {
			sort(b + 1, b + m + 1, cmpb);
			while (m > k / 2) {
				if (b[m].x >= b[m].z) {
					a[++n].x = b[m].x;
					a[n].y = b[m].y;
					a[n].z = b[m].z;
				} else {
					c[++nm].x = b[m].x;
					c[nm].y = b[m].y;
					c[nm].z = b[m].z;
				}
				m--;
			}
		}
		if (nm > k / 2) {
			sort(c + 1, c + nm + 1, cmpc);
			while (nm > k / 2) {
				if (c[nm].x >= c[nm].y) {
					a[++n].x = c[nm].x;
					a[n].y = c[nm].y;
					a[n].z = c[nm].z;
				} else {
					b[++m].x = c[nm].x;
					b[m].y = c[nm].y;
					b[m].z = c[nm].z;
				}
				nm--;
			}
		}
		for (int i = 1; i <= n; i++)
			sam += a[i].x;
		for (int i = 1; i <= m; i++)
			sam += b[i].y;
		for (int i = 1; i <= nm; i++)
			sam += c[i].z;
		cout << sam << endl;
		n = m = nm = sam = 0;
	}

	return 0;
}
