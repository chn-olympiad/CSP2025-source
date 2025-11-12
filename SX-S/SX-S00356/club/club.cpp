#include <bits/stdc++.h>
using namespace std;
#define maxn 100009

struct node {
	int a, b, c;
	int id;
} m[maxn], a[maxn], b[maxn], c[maxn], l[maxn];

int T, n, ta, tb, tc, totot, ca, cb, cc;

int f(node a) {
	if (a.a != a.b && a.b != a.c) {
		if (a.a > a.b && a.a > a.c)
			return 1;
		if (a.b > a.a && a.b > a.c)
			return 2;
		if (a.c > a.a && a.c > a.b)
			return 3;
	}
	if (a.a == a.b && a.b == a.c) {
		if (ta == tb && tb == tc)
			return 1;
		if (ta == tb) {
			if (ta > tc)
				return 3;
			else
				return 1;
		}
		if (ta == tc) {
			if (ta > tb)
				return 2;
			else
				return 1;
		}
		if (tb == tc) {
			if (tb > ta)
				return 1;
			else
				return 2;
		}
		if (ta < tb && ta < tc)
			return 1;
		if (tb < ta && tb < tc)
			return 2;
		if (tc < ta && tc < tb)
			return 3;
	}
	if (a.a == a.b) {
		if (a.a > a.c) {
			if (ta > tb)
				return 2;
			return 1;
		} else {
			return 3;
		}
	}
	if (a.b == a.c) {
		if (a.b > a.a) {
			if (tb < tc)
				return 2;
			return 3;
		} else {
			return 1;
		}
	}
	if (a.a == a.c) {
		if (a.a > a.b) {
			if (ta < tc)
				return 1;
			return 3;
		} else {
			return 2;
		}
	}
	return 1;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(m, 0, sizeof(m));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		totot = ta = tb = tc = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &m[i].a, &m[i].b, &m[i].c);
			int end = f(m[i]);
			if (end == 1) {
				if (ta < n / 2) {
					ta++;
					a[ta] = m[i];
					totot += m[i].a;
				} else {
					totot += m[i].a;
					int maxi;
					int cj = INT_MIN;
					ta++;
					a[ta] = m[i];
//					cout << 1;
					for (int j = 1; j <= ta; j++) {
						if (totot + max(a[j].b, a[j].c) - a[j].a >= cj) {
							maxi = j;
							cj = totot + max(a[j].b, a[j].c) - a[j].a ;
						}
					}
					if (a[maxi].b > a[maxi].c) {
						tb++;
						b[tb] = a[maxi];
						a[maxi] = a[ta];
					} else {
						tc++;
						c[tc] = a[maxi];
						a[maxi] = a[ta];
					}
					ta--;
					totot = cj;
				}
			}
			if (end == 2) {
				if (tb < n / 2) {
					tb++;
					b[tb] = m[i];
					totot += m[i].b;
				} else {
					totot += m[i].b;
					int cj = INT_MIN;
					int mbxi;
					tb++;
					b[tb] = m[i];
//					cout << 2;
					for (int j = 1; j <= tb; j++) {
						if (totot + max(b[j].c, b[j].a) - b[j].b >= cj) {
							mbxi = j;
							cj = totot + max(b[j].c, b[j].a) - b[j].b;
						}
					}
					if (b[mbxi].c > b[mbxi].a) {
						tc++;
						c[tc] = b[mbxi];
						b[mbxi] = b[tb];
					} else {
						ta++;
						a[ta] = b[mbxi];
						b[mbxi] = b[tb];
					}
					tb--;
					totot = cj;
				}
			}
			if (end == 3) {
				if (tc < n / 2) {
					tc++;
					c[tc] = m[i];
					totot += m[i].c;
				} else {
					totot += m[i].c;
					int cj = INT_MIN;
					int mcxi;
					tc++;
					c[tc] = m[i];
//					cout << 3;
					for (int j = 1; j <= tc; j++) {
						if (totot + max(c[j].a, c[j].b) - c[j].c >= cj) {
							mcxi = j;
							cj = totot + max(c[j].a, c[j].b) - c[j].c;
						}
					}
					if (c[mcxi].a > c[mcxi].b) {
						ta++;
						a[ta] = c[mcxi];
						c[mcxi] = c[tc];
					} else {
						tb++;
						b[tb] = c[mcxi];
						c[mcxi] = c[tc];
					}
					tc--;
					totot = cj;
				}
			}
		}
		cout << totot << '\n';
		continue;
	}
	return 0;
}