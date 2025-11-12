#include <bits/stdc++.h>
using namespace std;
int t, n, s[4], ans, b;

struct m {
	int f, s, t, maxn, c[4];
} a[100001];

bool p(m x, m y) {
	if (x.maxn == b) {
		if (y.maxn != b)
			return 1;

		if (b == 1) {
			if (min(x.c[2], x.c[3]) <= min(y.c[2], y.c[3]))
				return 1;
			else
				return 0;
		}

		if (b == 2) {
			if (min(x.c[1], x.c[3]) <= min(y.c[1], y.c[3]))
				return 1;
			else
				return 0;
		}

		if (b == 3) {
			if (min(x.c[2], x.c[1]) <= min(y.c[2], y.c[1]))
				return 1;
			else
				return 0;
		}
	} else
		return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;

	for (int x = 1; x <= t; x++) {

		ans = 0;
		s[1] = s[2] = s[3] = 0;
		cin >> n;

		for (int i = 1; i <= n; i++) {

			cin >> a[i].f >> a[i].s >> a[i].t;

			if (a[i].f > a[i].s && a[i].f > a[i].t) {
				a[i].maxn = 1;
				a[i].c[1] = 0;
				a[i].c[2] = a[i].f - a[i].s;
				a[i].c[3] = a[i].f - a[i].t;
				s[1]++;
			} else if (a[i].s > a[i].f && a[i].s > a[i].t) {
				a[i].maxn = 2;
				s[2]++;
				a[i].c[1] = a[i].s - a[i].f;
				a[i].c[2] = 0;
				a[i].c[3] = a[i].s - a[i].t;
			} else {
				a[i].maxn = 3;
				a[i].c[1] = a[i].t - a[i].f;
				a[i].c[2] = a[i].t - a[i].s;
				a[i].c[3] = 0;
				s[3]++;
			}
		}

		if (s[1] > n / 2 || s[2] > n / 2 || s[3] > n / 2) {
			if (s[1] > n / 2)
				b = 1;
			else if (s[2] > n / 2)
				b = 2;
			else
				b = 3;
			sort(a + 1, a + 1 + n, p);
			int i = 1;

			while (s[1] > n / 2 || s[2] > n / 2 || s[3] > n / 2) {
				if (b == 1) {
					if (a[i].c[2] < a[i].c[3]) {
						a[i].maxn = 2;
						s[b]--;
					} else {
						a[i].maxn = 3;
						s[b]--;
					}
				} else if (b == 2) {
					if (a[i].c[1] < a[i].c[3]) {
						a[i].maxn = 1;
						s[b]--;
					} else {
						a[i].maxn = 3;
						s[b]--;
					}
				} else {
					if (a[i].c[2] < a[i].c[1]) {
						a[i].maxn = 2;
						s[b]--;
					} else {
						a[i].maxn = 1;
						s[b]--;
					}
				}

				i++;
			}
		}

		for (int i = 1; i <= n; i++) {

			if (a[i].maxn == 1)
				ans += a[i].f;
			else if (a[i].maxn == 2)
				ans += a[i].s;
			else
				ans += a[i].t;
		}

		cout << ans << endl;
	}

	return 0;
}