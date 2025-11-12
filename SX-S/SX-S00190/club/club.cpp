#include <bits/stdc++.h>
using namespace std;
int t, n, c1, c2, c3, ans, b;

struct T {
	int a1, a2, a3, ch, maxx, minn, mid;
} a[100005];

bool cmp(T x, T y) {
	if (x.ch != y.ch)
		return x.ch > y.ch;
	if (x.maxx == y.maxx) {
		if (x.mid == y.mid) {
			return x.minn > y.minn;
		}
		return x.mid > y.mid;
	}
	return x.maxx > y.maxx;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		c1 = c2 = c3 = ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			b = a[i].a1 + a[i].a2 + a[i].a3;
			a[i].maxx = max(a[i].a1, max(a[i].a2, a[i].a3));
			a[i].minn = min(a[i].a1, min(a[i].a2, a[i].a3));
			a[i].mid = b - a[i].maxx - a[i].minn;
			a[i].ch = a[i].maxx - a[i].minn;
		}
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			if (a[i].maxx == a[i].a1 && c1 < n / 2) {
				c1++;
				ans += a[i].maxx;
			} else if (a[i].maxx == a[i].a2 && c2 < n / 2) {
				c2++;
				ans += a[i].maxx;
			} else if (a[i].maxx == a[i].a3 && c3 < n / 2) {
				c3++;
				ans += a[i].maxx;
			} else if (a[i].mid == a[i].a1 && c1 < n / 2) {
				c1++;
				ans += a[i].mid;
			} else if (a[i].mid == a[i].a2 && c2 < n / 2) {
				c2++;
				ans += a[i].mid;
			} else if (a[i].mid == a[i].a3 && c3 < n / 2) {
				c3++;
				ans += a[i].mid;
			} else if (a[i].mid == a[i].a1 && c1 < n / 2) {
				c1++;
				ans += a[i].minn;
			} else if (a[i].mid == a[i].a2 && c2 < n / 2) {
				c2++;
				ans += a[i].minn;
			} else if (a[i].mid == a[i].a3 && c3 < n / 2) {
				c3++;
				ans += a[i].minn;
			}
		}
		cout << ans << endl;
	}
	return 0;
}









