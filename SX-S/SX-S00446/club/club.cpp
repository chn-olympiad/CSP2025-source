#include <bits/stdc++.h>
using namespace std;
int b1, b2, b3;
long long ans;

struct xxx {
	int x, y, z, s;
} a[500005], a1[500005], a2[500005], a3[500005];

bool cmp(xxx x, xxx y) {
	int x1 = 0, y0 = 0;
	if (max(max(x.x, x.y), x.z) == x.x) {
		if (x.y >= x.z)
			x1 = x.y;
		else
			x1 = x.z;
		if (y.y >= y.z)
			y0 = y.y;
		else
			y0 = y.z;
		return x.x - x1 < y.x - y0;
	} else {
		if (max(max(x.x, x.y), x.z) == x.y) {
			if (x.x >= x.z)
				x1 = x.x;
			else
				x1 = x.z;
			if (y.x >= y.z)
				y0 = y.x;
			else
				y0 = y.z;
			return x.y - x1 < y.y - y0;
		} else {
			if (max(max(x.x, x.y), x.z) == x.z) {
				if (x.x >= x.y)
					x1 = x.x;
				else
					x1 = x.y;
				if (y.x >= y.y)
					y0 = y.x;
				else
					y0 = y.y;
				return x.z - x1 < y.z - y0;
			}
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		ans = 0;
		b1 = 0;
		b2 = 0;
		b3 = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].s = max(max(a[i].x, a[i].y), a[i].z);
			ans += a[i].s;
			if (a[i].s == a[i].x) {
				b1++;
				a1[b1] = a[i];
			} else {
				if (a[i].s == a[i].y) {
					b2++;
					a2[b2] = a[i];
				} else {
					if (a[i].s == a[i].z) {
						b3++;
						a3[b3] = a[i];
					}
				}
			}
		}
		long long m = n / 2;
		if (b1 > m) {
			int q = b1 - m;
			sort(a1 + 1, a1 + b1 + 1, cmp);
			for (int i = 1; i <= q; i++) {
				ans -= a1[i].x;
				b1--;
				if (a[i].y >= a[i].z && b2 + 1 <= m) {
					b2++;
					a2[b2] = a[i];
					ans += a2[b2].y;
				} else {
					b3++;
					a2[b3] = a[i];
					ans += a3[b3].z;
				}
			}
		}
		if (b2 > m) {
			int q = b2 - m;
			sort(a2 + 1, a2 + b2 + 1, cmp);
			for (int i = 1; i <= q; i++) {
				ans -= a2[i].y;
				b2--;
				if (a[i].x >= a[i].z && b1 + 1 <= m) {
					b1++;
					a1[b1] = a[i];
					ans += a1[b1].x;
				} else {
					b3++;
					a2[b3] = a[i];
					ans += a3[b3].z;
				}
			}
		}
		if (b3 > m) {
			int q = b3 - m;
			sort(a3 + 1, a3 + b3 + 1, cmp);
			for (int i = 1; i <= q; i++) {
				ans -= a3[i].z;
				b3--;
				if (a[i].x >= a[i].y && b1 + 1 <= m) {
					b1++;
					a1[b1] = a[i];
					ans += a1[b1].x;
				} else {
					b2++;
					a2[b2] = a[i];
					ans += a2[b2].y;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}