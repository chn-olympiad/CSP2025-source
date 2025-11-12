#include <bits/stdc++.h>
using namespace std;
const  int N = 1e5 + 10;
int t, n, x1, x2, x3, ansl, ansll, sx, l;
long long int s[N][5];

struct  {
	int a;
	int b;
	int c;
	int ab;
	int ac;
	int bc;

} d[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int m = 1; m <= t; m++) {
		cin >> n;
		sx = n / 2;
		if (n == 2) {
			int a, b, c, d, e, f, g, a1, a2, a3, a4, a5, a6;
			cin >> a >> b >> c >> d >> e >> f;
			ansl = max(a + e, ansl);
			ansl = max(a + f, ansl);
			ansl = max(b + d, ansl);
			ansl = max(b + f, ansl);
			ansl = max(c + d, ansl);
			ansl = max(c + e, ansl);
			cout << ansl;
		} else {
			for (int i = 1; i <= n; i++) {
				cin >> d[t].a >> d[t].b >> d[t].c;
				d[t].ab = max(d[t].a, d[t].b) - min(d[t].a, d[t].b);
				d[t].ac = max(d[t].a, d[t].c) - min(d[t].a, d[t].c);
				d[t].bc = max(d[t].c, d[t].b) - min(d[t].c, d[t].b);
			}
			for (int i = 1; i <= n; i++) {
				l = max(d[t].a, d[t].b);
				l = max(l, d[t].c);
				ansl += l;
			}
			if (n == 4) {

			}
			if (n > 6) {
				for (int i = 1; i < n; i++) {
					for (int j = 1; j < n; j++) {
						if (d[j].a > d[j + 1].a) {
							int h = d[j].a;
							d[j].a = d[j + 1].a;
							d[j + 1].a = h;
						}
					}
				}
				for (int i = n; i > sx; i++)
					ansl += d[i].a;
				cout << ansl;
			}
		}

	}
	return 0;
}