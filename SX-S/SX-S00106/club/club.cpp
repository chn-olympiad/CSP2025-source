#include <bits/stdc++.h>
using namespace std;
int t, sum, ans, n, an, bn, cn, am, bm, cm, k, q, l, h, w, r, u;

struct node {
	int x, y, z;
} a[10086];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ans = 0;
		an = 0;
		bn = 0;
		cn = 0;
		am = 0;
		bm = 0;
		cm = 0;
		k = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].x >> a[j].y >> a[j].z;
			an = max(an, a[j].x);
		}
		for (int j = 1; j <= n; j++) {
			bn = max(bn, a[j].y);
		}
		for (int j = 1; j <= n; j++) {
			cn = max(cn, a[j].z);
		}
		for (int j = 1; j <= n; j++) {
			if (a[j].x < an && a[j].x > am) {
				am = a[j].x;
			}
			if (a[j].y < bn && a[j].y > bm) {
				bm = a[j].y;
			}
			if (a[j].z < cn && a[j].z > cm) {
				cm = a[j].z;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (a[j].x == an)
				w = j;
			if (a[j].y == bn)
				r = j;
			if (a[j].z == cn)
				u = j;
		}
		l = max(max(an, bn), cn);
		h = min(min(an, bn), cn);
		if (an != l && an != h)
			q = an;
		if (bn != l && bn != h)
			q = bn;
		if (cn != l && cn != h)
			q = cn;

		k = max(max(am, bm), cm);

		if (an + bn + cn + k > q + k + am && an + bn + cn + k > q + k + bm && an + bn + cn + k > q + k + cm && (w != r
		        || an != bn) &&  (w != u || an != cn) && (r != u || bn != cn)
		        && r != u) {
			ans = ans + an + bn + cn + k;
			cout << ans << endl;
			continue;
		}

		if ((an == 0 && bn == 0) || (bn == 0 && cn == 0) || (cn == 0 && an == 0)) {
			ans = ans + an + bn + cn ;
			cout << ans << endl;
			continue;
		}

		else {
			if (k != am) {
				if (am + q + k > ans)
					ans = am + q + k;
			}
			if (k != bm) {
				if (bm + q + k > ans)
					ans = bm + q + k;
			}
			if (k != cm) {
				if (cm + q + k > ans)
					ans = cm + q + k;
			}
		}

		cout << ans << endl;


	}
	return 0;
}

