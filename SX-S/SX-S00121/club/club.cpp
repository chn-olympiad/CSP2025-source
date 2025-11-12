#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int t;
int n, ch[N];

struct st {
	int x, y;
} a[N], b[N], c[N];

bool cmp(st l, st r) {
	return l.x > r.x;
}

bool cmp2(int l, int r) {
	return l < r;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	for (int j = 1; j <= t; j++) {

		for (int i = 1; i <= 10000; i++) {
			a[i].x = 0;
			a[i].y = 0;
			b[i].x = 0;
			b[i].y = 0;
			c[i].x = 0;
			c[i].y = 0;
		}
		cin >> n;
		int m1 = 0, m2 = 0, ans = 0, e = 0, ma = n / 2, maa = 0, mab = 0, mac = 0;
		for (int i = 1; i <= 100; i++) {
			ch[i] = 1e9;
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> b[i].x >> c[i].x;
			if (b[i].x == 0 && c[i].x == 0) {
				m1++;
			} else if (c[i].x == 0) {
				m2++;
			}
		}
		if (m1 == n) {
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].x;
			}
			cout << ans << "\n";
			continue;
		} else if (m2 == n) {
			for (int i = 1; i <= n; i++) {
				if (a[i].x > b[i].x) {
					ans += a[i].x;
					a[i].y = 1;
					maa++;
				} else {
					ans += b[i].x;
					b[i].y = 1;
					mab++;
				}
			}
			if (maa == ma) {
				cout << ans << "\n";
				continue;
			} else {
				if (maa > ma) {
					e = maa - ma;
					for (int i = 1; i <= n; i++) {
						if (a[i].y) {
							ch[i] = a[i].x - b[i].x;
						}
					}
				} else {
					e = mab - ma;
					for (int i = 1; i <= n; i++) {
						if (b[i].y) {
							ch[i] = b[i].x - a[i].x;
						}
					}
				}
				sort(ch + 1, ch + n + 1, cmp2);
				for (int i = 1; i <= e; i++) {
					ans = ans - ch[i];
				}
				cout << ans << "\n";
				continue;
			}
		} else {
			for (int i = 1; i <= n; i++) {
				if (a[i].x > b[i].x && a[i].x > c[i].x) {
					ans += a[i].x;
					a[i].y = 1;
					if (b[i].x > c[i].x) {
						b[i].y = 2;
					} else {
						c[i].y = 2;
					}
					maa++;
				} else if (b[i].x > a[i].x && b[i].x > c[i].x) {
					ans += b[i].x;
					b[i].y = 1;
					if (a[i].x > c[i].x) {
						a[i].y = 2;
					} else {
						c[i].y = 2;
					}
					mab++;
				} else if (c[i].x > a[i].x && c[i].x > b[i].x) {
					ans += c[i].x;
					c[i].y = 1;
					if (a[i].x > b[i].x) {
						a[i].y = 2;
					} else {
						b[i].y = 2;
					}
					mac++;
				}
			}

			if (maa <= ma && mab <= ma && mac <= ma) {
				cout << ans << "\n";
				continue;
			} else {
				if (maa > ma) {
					e = maa - ma;
					for (int i = 1; i <= n; i++) {
						if (a[i].y) {
							ch[i] = a[i].x - max(b[i].x, c[i].x);
						}
					}
				}
				if (mab > ma) {
					e = mab - ma;
					for (int i = 1; i <= n; i++) {
						if (b[i].y) {
							ch[i] = b[i].x - max(a[i].x, c[i].x);
						}
					}
				}
				if (mac > ma) {
					e = mac - ma;
					for (int i = 1; i <= n; i++) {
						if (c[i].y) {
							ch[i] = c[i].x - max(a[i].x, b[i].x);
						}
					}
				}
				sort(ch + 1, ch + n + 1, cmp2);
				for (int i = 1; i <= e; i++) {
					ans = ans - ch[i];
				}
				cout << ans << "\n";
				continue;
			}
		}
	}


	return 0;

}












































































