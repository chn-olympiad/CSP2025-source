#include <bits/stdc++.h>
using namespace std;
int t ;

struct stu {
	int a, b, c, h;
} g[10010];

bool cmp(stu s1, stu s2) {
	return s1.h < s2.h;
}

int main() {
	cin >> t;
	while (t--) {
		int n, m = 0, o = 0, p = 0, sum = 0, cnt = 0;
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> g[i].a >> g[i].b >> g[i].c;
			g[i].h = g[i].a + g[i].b + g[i].c;
		}
		sort(g + 1, g + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			int x = g[i].a;
			int y = g[i].b;
			int z = g[i].c;
			int f = max(max(x, z), y);
			cnt += f;
			if (f == x) {
				if (m + 1 <= n / 2) {
					m++;
					sum += f;
				} else if (y > z) {
					if (o + 1 <= n / 2) {
						o++;
						sum += y;
					} else if (p + 1 <= n / 2) {
						p++;
						sum += z;
					}
				}
			} else if (f == y) {
				if (o + 1 <= n / 2) {
					o++;
					sum += f;
				} else if (x > z) {
					if (m + 1 <= n / 2) {
						m++;
						sum += x;
					} else if (p + 1 <= n / 2) {
						p++;
						sum += z;
					}
				}
			} else {
				if (p + 1 <= n / 2) {
					p++;
					sum += f;
				} else if (x > y) {
					if (m + 1 <= n / 2) {
						m++;
						sum += x;
					} else if (o + 1 <= n / 2) {
						o++;
						sum += y;
					}
				}
			}
		}
		cout << sum;
		cout << endl;
	}
	return 0;
}