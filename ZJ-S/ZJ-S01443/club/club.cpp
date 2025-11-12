#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int T, n, a[N], b[N], c[N], p[N], x[3];
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &T);
	while (T --> 0) {
		scanf ("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d%d%d", &x[0], &x[1], &x[2]);
			a[i] = max (max (x[0], x[1]), x[2]);
			if (x[0] == a[i]) {
				b[i] = 1;
			} else if (x[1] == a[i]) {
				b[i] = 2;
			} else {
				b[i] = 3;
			}
			ans += a[i];
			p[i] = i;
			c[i] = x[0] ^ x[1] ^ x[2] ^ a[i] ^ min (min (x[0], x[1]), x[2]);
			c[i] = a[i] - c[i];
		}
		sort (p + 1, p + n + 1, [] (int x, int y) { return c[x] < c[y]; });
		x[0] = x[1] = x[2] = 0;
		for (int i = 1; i <= n; i++) {
			x[b[i] - 1]++; 
		}
		int t = max (max (x[0], x[1]), x[2]), u = 0;
		if (x[0] == t) {
			u = 1;
		} else if (x[1] == t) {
			u = 2;
		} else {
			u = 3;
		}
		if (t > n / 2) {
			for (int i = 1; i <= n; i++) {
				if (b[p[i]] == u) {
					t--;
					ans -= c[p[i]];
				}
				if (t == n / 2) {
					break;
				}
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}